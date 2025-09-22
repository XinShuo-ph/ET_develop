import os
import argparse
from datasets import load_dataset
from flask import Flask, request, jsonify
import anthropic

app = Flask(__name__)

# Configuration (will be updated via command line arguments)
config = {
    "dataset_name": "xinshuo/ET_code",
    "model_name": "claude-3-7-sonnet-20250219",
    "api_key": "sk-STZg9YucRPrzS6PkEUphjtGglC7XkVAgVI9OADZQ4zzVFzPD",
    "base_url": "https://claude.cloudapi.vip",
    "max_tokens": 1024,
    "temperature": 0.7,
    "port": 5000,
}

# Global variables for dataset and client
dataset = None
client = None

def load_resources():
    """Load the dataset and initialize the Anthropic client"""
    global dataset, client

    print(f"Loading dataset: {config['dataset_name']}...")
    try:
        dataset = load_dataset(config['dataset_name'])
        print(f"Successfully loaded dataset: {config['dataset_name']}")
        print(f"Dataset structure: {dataset}")
        
        # Print the first example to understand the structure
        if "train" in dataset:
            print(f"First example: {dataset['train'][0]}")
        else:
            first_split = list(dataset.keys())[0]
            print(f"First example from '{first_split}': {dataset[first_split][0]}")
        
        # Set up context and output columns if not specified
        column_names = get_column_names()
        if not column_names:
            raise ValueError("No columns found in dataset")
        
        if config["context_columns"] is None:
            config["context_columns"] = column_names[:-1]
        
        if config["output_column"] is None:
            config["output_column"] = column_names[-1]
            
        print(f"Using context columns: {config['context_columns']}")
        print(f"Using output column: {config['output_column']}")
        
    except Exception as e:
        print(f"Error loading dataset: {e}")
        dataset = None

    print(f"Initializing Anthropic client for model: {config['model_name']}...")
    try:
        client = anthropic.Anthropic(
            api_key=config['api_key'],
            base_url=config['base_url']
        )
        # Test API connection
        test_message = client.messages.create(
            model=config['model_name'],
            max_tokens=10,
            messages=[
                {"role": "user", "content": "Hello"}
            ]
        )
        print("Anthropic API connection successful!")
    except Exception as e:
        print(f"Error initializing Anthropic client: {e}")
        client = None

def get_column_names():
    """Get column names from the dataset"""
    if dataset is None:
        return []
    
    split_name = "train" if "train" in dataset else list(dataset.keys())[0]
    if len(dataset[split_name]) == 0:
        return []
    
    return list(dataset[split_name][0].keys())

def create_prompt(context_data):
    """Create a prompt from the context data"""
    prompt = "You are an AI code assistant. Based on the following context, generate the appropriate code.\n\n"
    
    # Add each context column with its name
    for col in config['context_columns']:
        if col in context_data:
            prompt += f"# {col}:\n{context_data[col]}\n\n"
    
    # Add instruction for the output
    prompt += f"# Generate the following: {config['output_column']}\n"
    
    return prompt

def generate_output(context_columns):
    """Generate the output based on context columns using Anthropic API"""
    if client is None:
        return "Anthropic client not initialized"
    
    # Create the prompt
    prompt = create_prompt(context_columns)
    
    # Call Anthropic API
    try:
        message = client.messages.create(
            model=config['model_name'],
            max_tokens=config['max_tokens'],
            temperature=config['temperature'],
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

@app.route('/info', methods=['GET'])
def get_info():
    """Get information about the dataset and configuration"""
    column_names = get_column_names()
    return jsonify({
        "dataset": config['dataset_name'],
        "model": config['model_name'],
        "all_columns": column_names,
        "context_columns": config['context_columns'],
        "output_column": config['output_column'],
        "dataset_loaded": dataset is not None,
        "client_initialized": client is not None
    })

@app.route('/generate', methods=['POST'])
def generate():
    """Generate the output based on provided context"""
    data = request.json
    
    if not data or not isinstance(data, dict):
        return jsonify({"error": "Invalid input format. Expected JSON object with column values."}), 400
    
    try:
        generated_output = generate_output(data)
        return jsonify({
            "context": data,
            "generated_output": generated_output
        })
    except Exception as e:
        return jsonify({"error": str(e)}), 500

@app.route('/batch_generate', methods=['POST'])
def batch_generate():
    """Process multiple examples in batch"""
    data = request.json
    
    if not data or not isinstance(data, list):
        return jsonify({"error": "Invalid input format. Expected JSON array of examples."}), 400
    
    results = []
    for example in data:
        try:
            generated_output = generate_output(example)
            results.append({
                "context": example,
                "generated_output": generated_output
            })
        except Exception as e:
            results.append({
                "context": example,
                "error": str(e)
            })
    
    return jsonify({"results": results})

@app.route('/process_dataset', methods=['POST'])
def process_dataset():
    """Process examples from the dataset and generate outputs"""
    if dataset is None:
        return jsonify({"error": "Dataset not loaded"}), 500
    
    data = request.json or {}
    split_name = data.get("split", "train")
    start_idx = data.get("start_idx", 0)
    num_examples = data.get("num_examples", 10)
    
    if split_name not in dataset:
        return jsonify({"error": f"Split '{split_name}' not found in dataset"}), 400
    
    # Ensure we don't go out of bounds
    max_idx = min(start_idx + num_examples, len(dataset[split_name]))
    
    results = []
    for i in range(start_idx, max_idx):
        example = dataset[split_name][i]
        # Extract only the context columns
        context = {col: example[col] for col in config['context_columns'] if col in example}
        
        try:
            generated_output = generate_output(context)
            results.append({
                "example_id": i,
                "context": context,
                "actual_output": example.get(config['output_column'], "N/A"),
                "generated_output": generated_output
            })
        except Exception as e:
            results.append({
                "example_id": i,
                "context": context,
                "error": str(e)
            })
    
    return jsonify({
        "processed_examples": len(results),
        "context_columns": config['context_columns'],
        "output_column": config['output_column'],
        "results": results
    })

def parse_arguments():
    """Parse command line arguments"""
    parser = argparse.ArgumentParser(description="MCP Server for dataset code generation")
    parser.add_argument("--dataset", type=str, default=config['dataset_name'], help="HuggingFace dataset name")
    parser.add_argument("--model", type=str, default=config['model_name'], help="Anthropic model name")
    parser.add_argument("--api-key", type=str, default=config['api_key'], help="Anthropic API key")
    parser.add_argument("--base-url", type=str, default=config['base_url'], help="Anthropic API base URL")
    parser.add_argument("--port", type=int, default=config['port'], help="Port to run the server on")
    parser.add_argument("--context-columns", type=str, help="Comma-separated list of column names to use as context")
    parser.add_argument("--output-column", type=str, help="Column name to generate")
    parser.add_argument("--temperature", type=float, default=config['temperature'], help="Temperature for generation")
    parser.add_argument("--max-tokens", type=int, default=config['max_tokens'], help="Maximum tokens for generation")
    
    args = parser.parse_args()
    
    # Update config with parsed arguments
    config['dataset_name'] = args.dataset
    config['model_name'] = args.model
    config['api_key'] = args.api_key
    config['base_url'] = args.base_url
    config['port'] = args.port
    config['temperature'] = args.temperature
    config['max_tokens'] = args.max_tokens
    
    if args.context_columns:
        config['context_columns'] = args.context_columns.split(",")
    else:
        config['context_columns'] = None
    
    if args.output_column:
        config['output_column'] = args.output_column
    else:
        config['output_column'] = None

if __name__ == "__main__":
    parse_arguments()
    load_resources()
    print(f"Starting MCP server on port {config['port']}...")
    app.run(host='0.0.0.0', port=config['port'], debug=True) 