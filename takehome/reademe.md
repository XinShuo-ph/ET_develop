

## Step 1 -- Background
`my_simple_rl.py` is a simple experiment with the Proximal Policy Optimization (PPO) algorithm.

## Step 2 RL Environment
`collect_ET_code_dataset.py` is the code for collecting the Einstein Toolkit code dataset, this was run on the Sherlock cluster at Stanford, where the I already compiled and tested the code before.

`bleu_reward.py`, `llm_judge.py` and `compile_reward.py` define the reward structure for the task of generating code for the Einstein Toolkit: combination of BLEU score and LLM judge grading.

## Step 3 Sampling
`load_infer.py` is the code for sampling outputs from the model using the dataset collected in Step 2. This also explicitly defines the task. 

Running `python load_infer.py > log.txt 2>&1` will generate the text shown in Appendix A of the writeup.

## Step 4 Eval Metrics
`generate_GReX.py`, `evaluate_GReX.py` and `evaluate_all_checkpoints.py` are the code for evaluating the model on the GReX code. Running `python evaluate_all_checkpoints.py --start_line 376 --end_line 378 --batch_range 
0,180,10 --output_dir ./evaluation_results_376_378` generates the data in `evaluation_results_376_378`, which is used for Figure 5 in the writeup.

## Step 5 Training
`ppo_trainer.py` and `train_rl.py` defines the training loop. Running the following command defines the experiment explored in the writeup. Figure 4, 6, 7 are screenshots after the training runs.

```bash
python train_rl.py --model_name Qwen/Qwen2.5-Coder-0.5B-Instruct\
          --num_epochs 5 \
          --batch_size 3 \
          --ppo_epochs 4\
          --learning_rate 1e-7 \
          --clip_epsilon 0.02 \
          --use_llm_judge --use_wandb 
```

## misc
The notebook `Shuo_Xin_RL_Training_Take_Home_Assignment.ipynb` also contains all the code content above, but are much less organized and are not supposed to be runnable. The file is still kept for reference.

All the codes contain content assisted by LLMs (at least hinted by copilot auto-completion), mostly Claude 3.7 Sonnet, accessed through cursor and copilot. Certain codes are heavily assisted by LLMs, such as `generate_GReX.py`, `evaluate_GReX.py`, where I included the initial instructions at the top of the file as comments. More details of LLM usage can be provided upon request, which can be mostly retrieved locally in my cursor agent conversation history.