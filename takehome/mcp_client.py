#!/usr/bin/env python3
import argparse
import requests
import json
import time
import os
from rich.console import Console
from rich.table import Table
from rich.syntax import Syntax

console = Console()

def parse_arguments():
    """Parse command line arguments"""
    parser = argparse.ArgumentParser(description="Client for the MCP Server")
    
    # Server configuration
    parser.add_argument("--host", type=str, default="localhost", help="Server host")
    parser.add_argument("--port", type=int, default=5000, help="Server port")
    
    # Actions
    parser.add_argument("--info", action="store_true", help="Get dataset and model info")
    parser.add_argument("--test-dataset", action="store_true", help="Test with examples from the dataset")
    parser.add_argument("--split", type=str, default="train", help="Dataset split to use")
    parser.add_argument("--start-idx", type=int, default=0, help="Starting index for dataset examples")
    parser.add_argument("--num-examples", type=int, default=10, help="Number of examples to process")
    parser.add_argument("--output-dir", type=str, default="results", help="Directory to save results")
    parser.add_argument("--save", action="store_true", help="Save results to files")
    
    return parser.parse_args()

def make_api_request(host, port, endpoint, method="GET", data=None):
    """Make an API request to the server"""
    url = f"http://{host}:{port}/{endpoint}"
    
    try:
        if method.upper() == "GET":
            response = requests.get(url)
        elif method.upper() == "POST":
            response = requests.post(url, json=data)
        else:
            raise ValueError(f"Unsupported HTTP method: {method}")
        
        response.raise_for_status()
        return response.json()
    except requests.exceptions.RequestException as e:
        console.print(f"[bold red]Error making request to {url}:[/bold red] {str(e)}")
        return None

def display_info(info):
    """Display server information"""
    console.print("[bold green]Server Information:[/bold green]")
    
    table = Table(title="MCP Server Configuration")
    table.add_column("Setting", style="cyan", no_wrap=True)
    table.add_column("Value", style="green")
    
    table.add_row("Dataset", info.get("dataset", "N/A"))
    table.add_row("Model", info.get("model", "N/A"))
    table.add_row("Dataset Loaded", str(info.get("dataset_loaded", False)))
    table.add_row("Model Loaded", str(info.get("model_loaded", False)))
    
    console.print(table)
    
    # Print column information
    console.print("\n[bold blue]Dataset Columns:[/bold blue]")
    
    columns_table = Table(title="Column Configuration")
    columns_table.add_column("Column Name", style="cyan")
    columns_table.add_column("Role", style="green")
    
    all_columns = info.get("all_columns", [])
    context_columns = info.get("context_columns", [])
    output_column = info.get("output_column")
    
    for col in all_columns:
        role = "Context" if col in context_columns else "Output" if col == output_column else "Unused"
        columns_table.add_row(col, role)
    
    console.print(columns_table)

def process_dataset_examples(host, port, split="train", start_idx=0, num_examples=10):
    """Process examples from the dataset"""
    data = {
        "split": split,
        "start_idx": start_idx,
        "num_examples": num_examples
    }
    
    console.print(f"[bold blue]Processing {num_examples} examples from {split} split starting at index {start_idx}...[/bold blue]")
    
    start_time = time.time()
    results = make_api_request(host, port, "process_dataset", method="POST", data=data)
    elapsed_time = time.time() - start_time
    
    if results:
        console.print(f"[bold green]Processed {len(results.get('results', []))} examples in {elapsed_time:.2f} seconds[/bold green]")
        return results
    return None

def display_dataset_results(results):
    """Display the dataset processing results"""
    if not results:
        return
    
    processed_examples = results.get("processed_examples", 0)
    context_columns = results.get("context_columns", [])
    output_column = results.get("output_column", "")
    examples = results.get("results", [])
    
    console.print(f"[bold green]Results for {processed_examples} examples:[/bold green]")
    console.print(f"[bold blue]Context columns:[/bold blue] {', '.join(context_columns)}")
    console.print(f"[bold blue]Output column:[/bold blue] {output_column}")
    
    for i, example in enumerate(examples):
        console.print(f"\n[bold cyan]Example {example.get('example_id')}:[/bold cyan]")
        
        # Display context
        console.print("[bold magenta]Context:[/bold magenta]")
        for col, value in example.get("context", {}).items():
            console.print(f"[green]{col}:[/green]")
            # Display code with syntax highlighting if it looks like code
            if isinstance(value, str) and len(value) > 0:
                syntax = Syntax(value, "python", theme="monokai", line_numbers=False, word_wrap=True)
                console.print(syntax)
            else:
                console.print(value)
        
        # Display actual output if available
        actual_output = example.get("actual_output", "N/A")
        console.print("\n[bold magenta]Actual Output:[/bold magenta]")
        if isinstance(actual_output, str) and len(actual_output) > 0:
            syntax = Syntax(actual_output, "python", theme="monokai", line_numbers=False, word_wrap=True)
            console.print(syntax)
        else:
            console.print(actual_output)
        
        # Display generated output
        generated_output = example.get("generated_output", "")
        console.print("\n[bold magenta]Generated Output:[/bold magenta]")
        if isinstance(generated_output, str) and len(generated_output) > 0:
            syntax = Syntax(generated_output, "python", theme="monokai", line_numbers=False, word_wrap=True)
            console.print(syntax)
        else:
            console.print(generated_output)
        
        # If there was an error, display it
        if "error" in example:
            console.print(f"\n[bold red]Error:[/bold red] {example['error']}")
        
        # Add a separator between examples
        if i < len(examples) - 1:
            console.print("\n" + "-" * 80)

def save_results(results, output_dir):
    """Save results to files"""
    if not results:
        return
    
    # Create output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)
    
    # Save the raw results
    with open(os.path.join(output_dir, "results.json"), "w") as f:
        json.dump(results, f, indent=2)
    
    # Save individual examples
    examples = results.get("results", [])
    for example in examples:
        example_id = example.get("example_id", "unknown")
        
        # Create a directory for this example
        example_dir = os.path.join(output_dir, f"example_{example_id}")
        os.makedirs(example_dir, exist_ok=True)
        
        # Save context
        for col, value in example.get("context", {}).items():
            with open(os.path.join(example_dir, f"{col}.txt"), "w") as f:
                f.write(str(value))
        
        # Save actual output
        with open(os.path.join(example_dir, "actual_output.txt"), "w") as f:
            f.write(str(example.get("actual_output", "")))
        
        # Save generated output
        with open(os.path.join(example_dir, "generated_output.txt"), "w") as f:
            f.write(str(example.get("generated_output", "")))
    
    console.print(f"[bold green]Results saved to {output_dir}[/bold green]")

def main():
    args = parse_arguments()
    
    # Get server info
    if args.info:
        info = make_api_request(args.host, args.port, "info")
        if info:
            display_info(info)
    
    # Process dataset examples
    if args.test_dataset:
        results = process_dataset_examples(
            args.host, 
            args.port, 
            split=args.split,
            start_idx=args.start_idx,
            num_examples=args.num_examples
        )
        
        if results:
            display_dataset_results(results)
            
            # Save results if requested
            if args.save:
                save_results(results, args.output_dir)

if __name__ == "__main__":
    main() 