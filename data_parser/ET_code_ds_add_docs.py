#!/usr/bin/env python3
"""
Script to enhance the ET_code_with_context dataset by adding documentation files.
Adds .tex files from doc/ folders and README files to provide richer context.
"""

import os
import glob
from datasets import load_dataset

def find_documentation_files(thorn_name, base_dir="./Cactus/arrangements"):
    """
    Find documentation files for a given thorn.
    
    Args:
        thorn_name: Name of the thorn (e.g., "CactusExamples/Poisson")
        base_dir: Base directory containing arrangements
    
    Returns:
        dict: Dictionary with documentation content
    """
    thorn_path = os.path.join(base_dir, thorn_name)
    
    if not os.path.exists(thorn_path):
        return {
            'doc_tex_content': '',
            'doc_tex_filenames': '',
            'readme_content': '',
            'readme_filename': ''
        }
    
    doc_data = {
        'doc_tex_content': '',
        'doc_tex_filenames': '',
        'readme_content': '',
        'readme_filename': ''
    }
    
    # Find .tex files in doc/ folder and combine them
    doc_folder = os.path.join(thorn_path, 'doc')
    if os.path.exists(doc_folder):
        tex_files = glob.glob(os.path.join(doc_folder, '*.tex'))
        tex_contents = []
        tex_filenames = []
        
        for tex_file in tex_files:
            try:
                with open(tex_file, 'r', encoding='utf-8', errors='ignore') as f:
                    filename = os.path.basename(tex_file)
                    content = f.read()
                    tex_contents.append(f"=== {filename} ===\n{content}")
                    tex_filenames.append(filename)
                    print(f"  Found .tex file: {filename}")
            except Exception as e:
                print(f"  Error reading {tex_file}: {e}")
        
        doc_data['doc_tex_content'] = '\n\n'.join(tex_contents)
        doc_data['doc_tex_filenames'] = ', '.join(tex_filenames)
    
    # Find README files (various formats)
    readme_patterns = [
        'README', 'readme', 'Readme',
        'README.txt', 'readme.txt', 'Readme.txt',
        'README.md', 'readme.md', 'Readme.md',
        'README.rst', 'readme.rst'
    ]
    
    for pattern in readme_patterns:
        readme_path = os.path.join(thorn_path, pattern)
        if os.path.exists(readme_path) and os.path.isfile(readme_path):
            try:
                with open(readme_path, 'r', encoding='utf-8', errors='ignore') as f:
                    doc_data['readme_content'] = f.read()
                    doc_data['readme_filename'] = pattern
                    print(f"  Found README: {pattern}")
                    break  # Take the first README found
            except Exception as e:
                print(f"  Error reading {readme_path}: {e}")
    
    return doc_data

def add_documentation_to_example(example, thorn_docs_cache):
    """
    Add documentation fields to a dataset example.
    
    Args:
        example: Dataset example
        thorn_docs_cache: Cache of documentation data by thorn name
    
    Returns:
        dict: Enhanced example with documentation fields
    """
    thorn_name = example['thorn_name']
    
    # Get documentation data from cache (computed once per thorn)
    if thorn_name not in thorn_docs_cache:
        thorn_docs_cache[thorn_name] = find_documentation_files(thorn_name)
    
    doc_data = thorn_docs_cache[thorn_name]
    
    # Create enhanced example
    enhanced_example = {
        **example,  # Keep all original fields
        'doc_tex_content': doc_data['doc_tex_content'],
        'doc_tex_filenames': doc_data['doc_tex_filenames'],
        'readme_content': doc_data['readme_content'],
        'readme_filename': doc_data['readme_filename']
    }
    
    return enhanced_example

def create_combined_documentation_context(example):
    """
    Create a combined documentation context string for easier use.
    
    Args:
        example: Enhanced example with documentation fields
    
    Returns:
        dict: Example with additional combined_doc_context field
    """
    doc_context = ""
    
    # Add README content if available
    if example['readme_content'].strip():
        doc_context += f"## README ({example['readme_filename']}):\n"
        doc_context += f"```\n{example['readme_content']}\n```\n\n"
    
    # Add .tex documentation if available
    if example['doc_tex_content'].strip():
        doc_context += "## Documentation (.tex files):\n"
        if example['doc_tex_filenames']:
            doc_context += f"Files: {example['doc_tex_filenames']}\n\n"
        doc_context += f"```tex\n{example['doc_tex_content']}\n```\n\n"
    
    return {
        **example,
        'combined_doc_context': doc_context
    }

def main():
    print("Loading existing ET_code_with_context dataset...")
    
    # Load the existing dataset
    try:
        ds = load_dataset("xinshuo/ET_code_with_context")
        train_ds = ds['train']
        print(f"Loaded dataset with {len(train_ds)} examples")
        print(f"Original columns: {train_ds.column_names}")
    except Exception as e:
        print(f"Error loading dataset: {e}")
        return
    
    print("\nEnhancing dataset with documentation files...")
    
    # Cache for documentation data (one per thorn to avoid redundant file reads)
    thorn_docs_cache = {}
    
    # Get unique thorns to show progress
    unique_thorns = list(set(train_ds['thorn_name']))
    print(f"Found {len(unique_thorns)} unique thorns")
    
    # Pre-populate cache with documentation for all thorns
    print("\nExtracting documentation files...")
    for i, thorn_name in enumerate(unique_thorns):
        print(f"Processing thorn {i+1}/{len(unique_thorns)}: {thorn_name}")
        thorn_docs_cache[thorn_name] = find_documentation_files(thorn_name)
    
    print(f"\nAdding documentation fields to {len(train_ds)} examples...")
    
    # Add documentation fields to all examples
    enhanced_ds = train_ds.map(
        lambda example: add_documentation_to_example(example, thorn_docs_cache),
        desc="Adding documentation fields"
    )
    
    print("Creating combined documentation context...")
    
    # Add combined documentation context field
    final_ds = enhanced_ds.map(
        create_combined_documentation_context,
        desc="Creating combined doc context"
    )
    
    print(f"Enhanced dataset columns: {final_ds.column_names}")
    
    # Show statistics
    print("\nDataset enhancement statistics:")
    print(f"Examples with README files: {sum(1 for ex in final_ds if ex['readme_content'].strip())}")
    print(f"Examples with .tex files: {sum(1 for ex in final_ds if ex['doc_tex_content'].strip())}")
    print(f"Examples with any documentation: {sum(1 for ex in final_ds if ex['combined_doc_context'].strip())}")
    
    # Show example documentation
    print("\nSample documentation content:")
    for i, example in enumerate(final_ds):
        if example['combined_doc_context'].strip():
            print(f"\nExample from {example['thorn_name']} - {example['src_filename']}:")
            print(f"Documentation context length: {len(example['combined_doc_context'])} characters")
            print("First 200 characters of doc context:")
            print(example['combined_doc_context'][:200] + "..." if len(example['combined_doc_context']) > 200 else example['combined_doc_context'])
            break
    
    print(f"\nPushing enhanced dataset to HuggingFace: xinshuo/ET_code_with_context_doc")
    
    try:
        final_ds.push_to_hub("xinshuo/ET_code_with_context_doc", max_shard_size="500MB")
        print("✅ Dataset successfully pushed to HuggingFace!")
    except Exception as e:
        print(f"❌ Error pushing to HuggingFace: {e}")
        
        # Save locally as backup
        print("Saving dataset locally as backup...")
        final_ds.save_to_disk("./et_code_data/ET_code_with_context_doc_local")
        print("✅ Dataset saved locally to ./et_code_data/ET_code_with_context_doc_local")

if __name__ == "__main__":
    main()
