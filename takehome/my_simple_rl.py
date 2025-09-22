import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import numpy as np

class myppo:
  def __init__(self, dim_state, dim_action, lr = 1e-3, eps = 1e-1, lambda_value = 1.0) -> None:
    self.policy = nn.Sequential(
            nn.Linear(dim_state, 64),
            nn.ReLU(),
            nn.Linear(64, dim_action),
            nn.Softmax(dim=-1)
        )
    self.values = nn.Sequential(
            nn.Linear(dim_state, 64),
            nn.ReLU(),
            nn.Linear(64, 1)
        )

    self.optimizer = optim.Adam(list(self.policy.parameters()) + list(self.values.parameters()), lr=lr) # train both policy and value predictor
    self.eps = eps
    self.lambda_value = lambda_value # control how much we want the value loss be dominant

  def move(self, state): # return action, policy probablity, current value (define advantage as reward-value)
    all_probs = self.policy(state)
    # print(all_probs)
    action = torch.multinomial(all_probs,1)
    value = self.values(state)
    return action, all_probs.gather(1, action), value # the 0th dim is saved for batch dimension
  def update(self, state, action, old_prob, reward, value): # reward will be provided by an external env function
    adv = reward - value.detach()
    all_probs = self.policy(state)
    new_prob = all_probs.gather(1, action)
    ratio = new_prob/old_prob
    # clip
    clipped_ratio = torch.clamp(ratio,1-self.eps,1+self.eps)
    loss_ppo = -torch.min(ratio * adv, clipped_ratio * adv).mean() # following https://en.wikipedia.org/wiki/Proximal_policy_optimization#PPO
    current_values = self.values(state)
    value_loss = F.mse_loss(current_values, reward)
    total_loss = loss_ppo + value_loss*self.lambda_value
    # update
    self.optimizer.zero_grad()
    total_loss.backward()
    self.optimizer.step()
    return total_loss.item()

def myenv():
  # simply a binary env
  def reward_model(state,action):
    if action == 0:
      return 0.1
    else:
      return 0.9
  return reward_model

def take_action(state,action):
  # simply don't move
  return state

# test the ppo training
dim_state = 1
dim_action = 2
ppo = myppo(dim_state,dim_action, lambda_value=1)
env = myenv()

for episode in range(100):
  state = torch.tensor([[1.0]])

  action, prob, value = ppo.move(state)
  reward = env(state.item(),action.item())
  reward = torch.tensor([[reward]])
  loss = ppo.update(state,action,prob.detach(),reward,value)
  if episode % 20 == 0:
    print("step %d, loss %f"%(episode,loss))
    # check the current policy
    print("current policy:", ppo.policy(state))
  # move the state
  state = take_action(state,action)

# should see the model gradually favor action 1