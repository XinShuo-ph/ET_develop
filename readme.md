# Evaluating LLM-generated Einstein Toolkit code

## workflow

Write the necessary configurations in `config.json`, then run the evaluator:
```bash
python ET_evaluator.py --config config.json --max-examples <N> --workers <M> --output-dir results
```
This will initiate `<M>` docker containers to evaluate the total of `<N>` examples in parallel, and the evaluation output will be saved in the `results` folder. Each worker would do the following:
 - send the prompt (using template specified in `config.json`) through http request to remote LLM API to generate code for current example
 - compile the executable of Einstein Toolkit applying the generated code in the container 
 - run the executable on the unit tests (the simulation) corresponding to the current example
 - compare the simulation outputs with the reference, give a score according to compilation success, execution success and numerical accuracy
until all examples are evaluated.

## configurations

Change the `config.json` for different settings:
### api
To send query and get response from LLM. Specify the following (assuming your API key is stored in an environment variable):
- `base_url`: endpoint url of the API
- `model_name`: Model name (e.g., "gcp-claude4-sonnet")
- `api_key_env_var`: Environment variable for API key
- `max_tokens`: Response token limit

### docker
The Einstein Toolkit executable is built and run in a docker container. Specify the following:
- `image_name`: Einstein Toolkit image on Docker Hub ([`rynge/einsteintoolkit`](https://hub.docker.com/r/rynge/einsteintoolkit))
- `container_prefix`: Container name prefix (so that the n-th worker will run stuff in the unique container with name `'<container_prefix>_n'`)
- `working_directory`: Working path inside the container (`/opt/Cactus`)
- `setup_timeout`: Timeout for container initialization
- `build_timeout`: Timeout for Einstein Toolkit build
- `test_timeout`: Timeout for Einstein Toolkit execution of unit tests
- `container_file_changes`: Files to be changed in the container (see `legacy/docker_stuff/container_files_change.md` for reasons why this is needed)


### dataset

The dataset [`ET_code_with_context_doc`](https://huggingface.co/datasets/xinshuo/ET_code_with_context_doc) provides the examples to be evaluated (for details in preparing the dataset, see `data_parser/readme.md`). Each example defines a code generation task: given the `thorn_name`, `src_filename`, `interface`, `schedule`, `param`, `configuration`, `context`, `combined_doc_context`, the LLM is asked to generate the code for `src_filename` (while the reference implementation is recorded in `src_code`, this should not be provided to the LLM). 

In the config, specify the following:
- `name`: HuggingFace dataset name
- `split`: Dataset split to use
- `context_char_limit`: cutoff the context provided to the LLM to this number of characters
- `doc_char_limit`: cutoff the documentation provided to the LLM to this number of characters

### evaluation

- thorn_to_tests_file: file that maps the thorn to its unit tests (see `test_parser/readme.md`)
- scoring: Build (40pts) + Test execution (10pts) + Accuracy (50pts) = 100pts
- tolerances: Numerical comparison with `rtol=1e-6`, `atol=1e-12`

### logging

Records the workflow of container setup, API requests, compilation, executation and evaluation progress of each worker. Change the `logging` field for:
- Configurable log levels and formats
- Build progress streaming (compilation of the Einstein Toolkit executable is slow, ~ 50 seconds. This monitors the progress every, e.g. 5 seconds as specified in `config.json`)
- Keyword filtering (the log of building Einstein Toolkit executable is long, so only keep the lines around several keywords e.g. [`Done`, `error:`])
- Worker-specific log prefixes

### prompt
One prompt template is used to ask LLM for code generation. Change the `prompt` field for:
- `template_file`: Prompt template path (`prompt.txt`)
- Character limits for context and documentation sections

The provided template `prompt.txt`, for example:
```
You are an expert C/C++ developer working on EinsteinToolkit, a codebase for numerical relativity simulations.

Create C/C++ code for the file `{src_filename}` in thorn `{thorn_name}`.

## Thorn Information:
- Name: {thorn_name}
- Target file: {src_filename}

## Interface Definition in interface.ccl:

{interface}

... (more omitted)
```
The fields wrapped in `{` and `}` are the variables that will be replaced with the actual text from the dataset.

## examples

### the example that involves physical understanding
See `special_example_check/` for visualization and interpretation of one example where physical understanding is needed for correct numerical accuracy.

### comparison details (`smart_diff_demo`)
See `smart_diff_demo/` for details in numerical comparison between generated outputs and references. 

### tolerance test
See `tol_test/` for testing of all existing unit tests with different `rtol`/`atol` values (relative and absolute numerical tolerance).

## data preparation

See `data_parser/readme.md` for more details.

## test preparation

See `test_parser/readme.md` for more details.