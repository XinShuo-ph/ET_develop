import os
import re
import json
import csv
from huggingface_hub import HfApi, upload_file
from datasets import Dataset, DatasetDict

def parse_thornlist(thornlist_path):
    """Parse the thornlist file to extract thorn information."""
    thorns = []
    
    with open(thornlist_path, 'r') as f:
        lines = f.readlines()
    
    current_url = None
    in_checkout_section = False
    
    for line in lines:
        line = line.strip()
        
        # Skip empty lines and comments
        if not line or line.startswith('#'):
            continue
        
        # Look for URL definition
        if line.startswith('!URL'):
            current_url = line.split('=')[1].strip()
        
        # Check if we're entering a checkout section
        elif line.startswith('!CHECKOUT'):
            in_checkout_section = True
            continue
        
        # If we're in a checkout section and have a URL, process thorn names
        elif in_checkout_section and current_url and not line.startswith('!'):
            # Skip disabled thorns
            if line.startswith('#DISABLED'):
                continue
                
            # Split by whitespace and take the first part as the thorn path
            parts = line.split()
            if parts and '/' in parts[0]:
                thorn_name = parts[0]
                thorns.append({
                    'thorn_name': thorn_name,
                    'url': current_url
                })
        
        # If we encounter a new target or type, we're no longer in the checkout section
        elif line.startswith('!TARGET') or line.startswith('!TYPE'):
            in_checkout_section = False
    
    return thorns

def extract_thorn_data_to_rows(thorn_info, base_dir):
    """Extract the data for a specific thorn and return one row per source file."""
    thorn_name = thorn_info['thorn_name']
    url = thorn_info['url']
    
    # Path to the thorn within the existing arrangements directory
    thorn_path = os.path.join(base_dir, thorn_name)
    
    if not os.path.exists(thorn_path):
        print(f"Thorn path {thorn_path} does not exist.")
        return []
    
    # Extract CCL files
    ccl_data = {}
    for ccl_type in ['configuration', 'interface', 'param', 'schedule']:
        ccl_file = os.path.join(thorn_path, f"{ccl_type}.ccl")
        if os.path.exists(ccl_file):
            try:
                with open(ccl_file, 'r', encoding='utf-8', errors='ignore') as f:
                    ccl_data[ccl_type] = f.read()
            except Exception as e:
                print(f"Error reading {ccl_file}: {e}")
                ccl_data[ccl_type] = ""
        else:
            ccl_data[ccl_type] = ""
    
    # Extract source code and create one row per source file
    rows = []
    src_path = os.path.join(thorn_path, 'src')
    if os.path.exists(src_path):
        for root, _, files in os.walk(src_path):
            for file in files:
                file_path = os.path.join(root, file)
                rel_path = os.path.relpath(file_path, src_path)
                
                try:
                    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                        src_code = f.read()
                        
                    # Create a row for this source file
                    row = {
                        'thorn_name': thorn_name,
                        'url': url,
                        'configuration': ccl_data.get('configuration', ''),
                        'interface': ccl_data.get('interface', ''),
                        'param': ccl_data.get('param', ''),
                        'schedule': ccl_data.get('schedule', ''),
                        'src_filename': rel_path,
                        'src_code': src_code
                    }
                    rows.append(row)
                except Exception as e:
                    print(f"Error reading {file_path}: {e}")
    
    return rows

def main():
    # Directory for existing Einstein Toolkit arrangements
    base_dir = "./Cactus/arrangements"
    
    # Directory for collected data
    data_dir = "et_code_data"
    os.makedirs(data_dir, exist_ok=True)
    
    # Path for the local JSONL file
    jsonl_path = os.path.join(data_dir, "einsteintoolkit_code.jsonl")
    
    # Parse the thornlist
    thornlist_path = "./Cactus/thornlists/einsteintoolkit.th"
    thorns = parse_thornlist(thornlist_path)
    
    print(f"Found {len(thorns)} thorns in the thornlist.")
    
    # Write each source file as a separate row in the JSONL file
    with open(jsonl_path, 'w', encoding='utf-8') as jsonl_file:
        total_rows = 0
        
        for i, thorn_info in enumerate(thorns):
            print(f"Processing thorn {i+1}/{len(thorns)}: {thorn_info['thorn_name']}")
            rows = extract_thorn_data_to_rows(thorn_info, base_dir)
            
            for row in rows:
                jsonl_file.write(json.dumps(row) + '\n')
                total_rows += 1
    
    print(f"Total source files processed: {total_rows}")
    print(f"Data saved to {jsonl_path}")
    
    ds = Dataset.from_json(jsonl_path)
    ds.push_to_hub("xinshuo/ET_code", max_shard_size="500MB")

if __name__ == "__main__":
    main()