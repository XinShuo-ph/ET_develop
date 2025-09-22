#!/usr/bin/env python3
import argparse
from datasets import load_dataset
import anthropic
import json
import os

def parse_arguments():
    """Parse command line arguments"""
    parser = argparse.ArgumentParser(description="Generate code using Claude API")
    parser.add_argument("--dataset", type=str, default="xinshuo/ET_code", help="HuggingFace dataset name")
    parser.add_argument("--model", type=str, default="claude-3-7-sonnet-20250219", help="Anthropic model name")
    parser.add_argument("--api-key", type=str, default="sk-STZg9YucRPrzS6PkEUphjtGglC7XkVAgVI9OADZQ4zzVFzPD", help="Anthropic API key")
    parser.add_argument("--base-url", type=str, default="https://claude.cloudapi.vip", help="Anthropic API base URL")
    parser.add_argument("--split", type=str, default="train", help="Dataset split to use")
    parser.add_argument("--index", type=int, default=0, help="Index of the example to process")
    parser.add_argument("--num-examples", type=int, default=1, help="Number of examples to process")
    parser.add_argument("--max-tokens", type=int, default=1024, help="Maximum tokens for generation")
    parser.add_argument("--temperature", type=float, default=0.7, help="Temperature for generation")
    parser.add_argument("--output-dir", type=str, default="outputs", help="Directory to save results")
    
    return parser.parse_args()

def create_prompt(example, output_column='src_code'):
    """Create a prompt from the example data"""
    prompt = "You are an AI code assistant. Based on the following context, generate the appropriate code.\n\n"
    
    # Add each column with its name (except the output column)
    for col, value in example.items():
        if col != output_column:
            prompt += f"# {col}:\n{value}\n\n"
    
    # Add instruction for the output
    prompt += f"# Generate the following: {output_column}\n"
    
    return prompt

def generate_code(client, prompt, model, max_tokens, temperature):
    """Generate code using the Anthropic API"""
    try:
        message = client.messages.create(
            model=model,
            max_tokens=max_tokens,
            temperature=temperature,
            messages=[
                {"role": "user", "content": prompt}
            ]
        )
        
        # Extract the generated text
        generated_text = message.content[0].text
        return generated_text
    except Exception as e:
        print(f"Error calling Anthropic API: {e}")
        return f"API Error: {str(e)}"

def process_examples(dataset, split, start_idx, num_examples, client, model, max_tokens, temperature, output_column='src_code'):
    """Process examples from the dataset and generate outputs"""
    if split not in dataset:
        raise ValueError(f"Split '{split}' not found in dataset")
    
    # Ensure we don't go out of bounds
    max_idx = min(start_idx + num_examples, len(dataset[split]))
    
    results = []
    for i in range(start_idx, max_idx):
        example = dataset[split][i]
        print(f"Processing example {i}...")
        
        # Create prompt
        prompt = create_prompt(example, output_column)
        
        # Generate code
        generated_code = generate_code(client, prompt, model, max_tokens, temperature)
        
        # Create result
        result = {
            "example_id": i,
            "context": {k: v for k, v in example.items() if k != output_column},
            "actual_output": example.get(output_column, "N/A"),
            "generated_output": generated_code
        }
        
        results.append(result)
        print(f"Completed example {i}")
        
    return results

def save_results(results, output_dir):
    """Save results to files"""
    os.makedirs(output_dir, exist_ok=True)
    
    # Save the raw results
    with open(os.path.join(output_dir, "results.json"), "w") as f:
        json.dump(results, f, indent=2)
    
    # Save individual examples
    for result in results:
        example_id = result["example_id"]
        
        # Create a directory for this example
        example_dir = os.path.join(output_dir, f"example_{example_id}")
        os.makedirs(example_dir, exist_ok=True)
        
        # Save context
        for col, value in result["context"].items():
            with open(os.path.join(example_dir, f"{col}.txt"), "w") as f:
                f.write(str(value))
        
        # Save actual output
        with open(os.path.join(example_dir, "actual_output.txt"), "w") as f:
            f.write(str(result["actual_output"]))
        
        # Save generated output
        with open(os.path.join(example_dir, "generated_output.txt"), "w") as f:
            f.write(str(result["generated_output"]))
    
    print(f"Results saved to {output_dir}")

def main():
    args = parse_arguments()
    
    # Load dataset
    print(f"Loading dataset: {args.dataset}...")
    try:
        dataset = load_dataset(args.dataset)
        print(f"Successfully loaded dataset: {args.dataset}")
    except Exception as e:
        print(f"Error loading dataset: {e}")
        return
    
    # Initialize Anthropic client
    print(f"Initializing Anthropic client for model: {args.model}...")
    try:
        client = anthropic.Anthropic(
            api_key=args.api_key,
            base_url=args.base_url
        )
        # Test API connection
        test_message = client.messages.create(
            model=args.model,
            max_tokens=10,
            messages=[
                {"role": "user", "content": "Hello"}
            ]
        )
        print("Anthropic API connection successful!")
    except Exception as e:
        print(f"Error initializing Anthropic client: {e}")
        return
    
    # Process examples
    try:
        output_column = 'src_code'  # Assuming the output column is src_code
        
        # Check if output column exists in the dataset
        split = args.split if args.split in dataset else next(iter(dataset.keys()))
        if len(dataset[split]) > 0:
            first_example = dataset[split][0]
            if output_column not in first_example:
                print(f"Warning: Output column '{output_column}' not found in dataset. Available columns: {list(first_example.keys())}")
                # Use the last column as output
                output_column = list(first_example.keys())[-1]
                print(f"Using '{output_column}' as output column instead.")
        
        results = process_examples(
            dataset=dataset,
            split=args.split,
            start_idx=args.index,
            num_examples=args.num_examples,
            client=client,
            model=args.model,
            max_tokens=args.max_tokens,
            temperature=args.temperature,
            output_column=output_column
        )
        
        # Print results to console
        for result in results:
            print(f"\n\n===== Example {result['example_id']} =====")
            print("\n--- Context ---")
            for col, value in result["context"].items():
                print(f"\n{col}:")
                print(value[:500] + "..." if len(str(value)) > 500 else value)
            
            print("\n\n--- Actual Output ---")
            actual_output = result["actual_output"]
            print(actual_output[:500] + "..." if len(str(actual_output)) > 500 else actual_output)
            
            print("\n\n--- Generated Output ---")
            generated_output = result["generated_output"]
            print(generated_output[:500] + "..." if len(str(generated_output)) > 500 else generated_output)
        
        # Save results
        save_results(results, args.output_dir)
    
    except Exception as e:
        print(f"Error processing examples: {e}")

if __name__ == "__main__":
    main() 