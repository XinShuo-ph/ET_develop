#!/usr/bin/env python3
"""
Test script to discover what documentation files are available in thorns.
"""

import os
import glob

def discover_documentation_files(base_dir="./Cactus/arrangements"):
    """Discover what documentation files exist across all thorns."""
    
    print("Discovering documentation files in Einstein Toolkit arrangements...")
    
    stats = {
        'total_thorns': 0,
        'thorns_with_doc_folder': 0,
        'thorns_with_tex_files': 0,
        'thorns_with_readme': 0,
        'tex_files_found': [],
        'readme_files_found': []
    }
    
    if not os.path.exists(base_dir):
        print(f"Base directory {base_dir} does not exist!")
        return
    
    # Walk through all arrangements
    for arrangement in os.listdir(base_dir):
        arrangement_path = os.path.join(base_dir, arrangement)
        if not os.path.isdir(arrangement_path):
            continue
        
        for thorn in os.listdir(arrangement_path):
            thorn_path = os.path.join(arrangement_path, thorn)
            if not os.path.isdir(thorn_path):
                continue
            
            thorn_name = f"{arrangement}/{thorn}"
            stats['total_thorns'] += 1
            
            # Check for doc folder
            doc_folder = os.path.join(thorn_path, 'doc')
            if os.path.exists(doc_folder):
                stats['thorns_with_doc_folder'] += 1
                
                # Look for .tex files
                tex_files = glob.glob(os.path.join(doc_folder, '*.tex'))
                if tex_files:
                    stats['thorns_with_tex_files'] += 1
                    for tex_file in tex_files:
                        filename = os.path.basename(tex_file)
                        stats['tex_files_found'].append((thorn_name, filename))
            
            # Check for README files
            readme_patterns = [
                'README', 'readme', 'Readme',
                'README.txt', 'readme.txt', 'Readme.txt',
                'README.md', 'readme.md', 'Readme.md',
                'README.rst', 'readme.rst'
            ]
            
            for pattern in readme_patterns:
                readme_path = os.path.join(thorn_path, pattern)
                if os.path.exists(readme_path) and os.path.isfile(readme_path):
                    stats['thorns_with_readme'] += 1
                    stats['readme_files_found'].append((thorn_name, pattern))
                    break  # Only count first README found per thorn
    
    # Print statistics
    print(f"\n=== Documentation Discovery Results ===")
    print(f"Total thorns found: {stats['total_thorns']}")
    print(f"Thorns with doc/ folder: {stats['thorns_with_doc_folder']}")
    print(f"Thorns with .tex files: {stats['thorns_with_tex_files']}")
    print(f"Thorns with README files: {stats['thorns_with_readme']}")
    
    # Show examples of .tex files
    print(f"\n=== Sample .tex files found ===")
    for i, (thorn_name, filename) in enumerate(stats['tex_files_found'][:10]):
        print(f"  {thorn_name}: {filename}")
    if len(stats['tex_files_found']) > 10:
        print(f"  ... and {len(stats['tex_files_found']) - 10} more")
    
    # Show examples of README files
    print(f"\n=== Sample README files found ===")
    for i, (thorn_name, filename) in enumerate(stats['readme_files_found'][:10]):
        print(f"  {thorn_name}: {filename}")
    if len(stats['readme_files_found']) > 10:
        print(f"  ... and {len(stats['readme_files_found']) - 10} more")
    
    # Check a specific example
    example_thorn = "CactusExamples/Poisson"
    example_path = os.path.join(base_dir, example_thorn)
    if os.path.exists(example_path):
        print(f"\n=== Detailed check of {example_thorn} ===")
        
        # Check doc folder
        doc_folder = os.path.join(example_path, 'doc')
        if os.path.exists(doc_folder):
            print(f"Doc folder exists: {doc_folder}")
            files = os.listdir(doc_folder)
            print(f"Files in doc folder: {files}")
        else:
            print("No doc folder found")
        
        # Check for README
        for pattern in readme_patterns:
            readme_path = os.path.join(example_path, pattern)
            if os.path.exists(readme_path):
                print(f"README found: {pattern}")
                # Show first few lines
                try:
                    with open(readme_path, 'r', encoding='utf-8', errors='ignore') as f:
                        content = f.read()
                        print(f"README content preview (first 200 chars):")
                        print(content[:200] + "..." if len(content) > 200 else content)
                except Exception as e:
                    print(f"Error reading README: {e}")
                break

if __name__ == "__main__":
    discover_documentation_files()
