from datasets import load_dataset
ds = load_dataset("xinshuo/ET_code")

# Show dataset structure
train_ds = ds['train']
print(f"Number of examples: {len(train_ds)}")
print(f"Columns: {train_ds.column_names}")

print("Running inference on dataset...")

# prepare context for the dataset
# Define a function to create a new column
def new_column(example):
    # Create a new dictionary with the context field while preserving original columns
    return {**example, 'context_filenames': "", 'context': ""}

# Map the function to create the 'context' column
train_ds = train_ds.map(new_column)
def add_context_from_nearby(example, idx, dataset, window_size=40):
    example_thorn_name = example['thorn_name']
    example_src_filename = example['src_filename']
    new_example = dict(example)
    context_filenames = ""
    context = ""
    start_idx = max(0, idx - window_size)
    end_idx = min(len(dataset), idx + window_size)
    for i in range(start_idx, end_idx):
        if i == idx:  # Skip the current example
            continue
        nearby_example = dataset[i]
        # Only add context from the same thorn but different files
        if (nearby_example['thorn_name'] == example_thorn_name and 
            nearby_example['src_filename'] != example_src_filename):
            context += f"{nearby_example['src_filename']}:\n"
            context += f"```\n{nearby_example['src_code']}\n```\n\n"
            context_filenames += f"{nearby_example['src_filename']}\n"
    new_example['context'] = context
    new_example['context_filenames'] = context_filenames
    return new_example

# Apply the context function to each example
train_ds = train_ds.map(
    lambda example, idx: add_context_from_nearby(example, idx, train_ds),
    with_indices=True
)

train_ds.push_to_hub("xinshuo/ET_code_with_context")