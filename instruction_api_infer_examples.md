In the currently repo, I have successfully tested how to build and run einsteintoolkit in docker, how to interact with remote LLM provider, and how to write a good prompt for generating einsteintoolkit code. Now let's collect the pieces: Write just one python script, that does this {load the huggingface dataset, query using api with a specific prompt for einsteintoolkit code generation (write to a file for me to check), put the generated code source file into docker, build and (if build is successful) run the test corresponding to the Thorn, give a score according to the build/test results.} There should be no technical details to explore, simply reuse my existing scripts. For reference: 

- Using api: @api_usage.py and see my terminal output for the returned json format 
- Using docker: @readme.md @container_files_change.md 
- Build and run einstein toolkit (in docker): @readme.md @run_all_tests.sh 
    - note that this is for running all tests, in our case, only run tests corresponding to a specific Thorn listed in @thorn_to_tests.txt 
- Check Thorns in huggingface datasets: @validate_thorns.py 
- Load example, write prompt from an example (in ET_code_with_context dataset): @load_infer.py 
    - note that this script uses a locally deployed LLM, we should change a lot of stuff according to api interaction with remote LLM. For instance, we may not be able to change system prompt (check?)
    - note that this script uses similarity score. But we should give score sccording to the build and run tests.
    - note that not all Thorns in the datasets can be tested. We should filter out the examples that have thorn_name exist in @thorn_to_tests.txt , like what we did in @validate_thorns.py 


When you develop the script, make a dir `scratch` to put any stuff output when you are debugging. Now start your work following this workflow:
1. check the @instruction_api_infer_examples.md , briefly check the reference files, check the current status of this machine (e.g. `docker ps`, `which python`, etc)
2. understand the task in steps, estimate the difficulties of each step, and make an educated plan of TODO list.
3. Work on the TODO list one by one, for each todo item, iterate as follows
    - Carefully read @instruction_api_infer_examples.md and carefully read the relevant codes for current todo item.
    - Write code, when if unsure with anything, write some quick check and keep the stuff in scratch dir
    - test the code
    - repeat until the code is correct and concise and implement the correct work.