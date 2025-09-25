# Setup docker

Pull the docker image (3GB, may take a while):
```bash
docker pull rynge/einsteintoolkit
```

Open docker container in a terminal:
```bash
docker run -it --name ET_docker_1 rynge/einsteintoolkit /bin/bash
```

Copy necessary files to the container: Check `docker_stuff/container_files_change.md` for more details.

Copy necessary files from the container to the host:
```bash
docker cp ET_docker_1:/opt/Cactus .
```

Then use the following python scripts to parse the Cactus code:
 - `ET_collect_test_names.py` to collect the test names to `test_names.txt` for later use
 - `ETdata_hf_code.py` to collect the Cactus code to huggingface dataset
 - `ETdata_hf_test.py` to collect the Cactus test files to huggingface dataset
 - `ET_code_ds_add_context.py` to add a test column to the dataset so that it can be loaded as `takehome/load_infer.py` does

# Run parameter checks

Before taking a long time to run tests, we can check the parameter files first (~minutes).
```bash
cd docker_stuff/par_check
python ../../check_docker_tests.py ET_docker_1 ../../test_names.txt ../../Cactus
```

# Run tests


After the run finishes, exit the container and remove it:
```bash
docker rm ET_docker_1
```


# scratch

docker container runer
```bash

docker rm ET_docker_1
docker run -it --name ET_docker_1 rynge/einsteintoolkit /bin/bash

```

sync-er
```bash

screen -S sync_docker


while true; do
    echo "$(date): Copying files..."
    
    # Copy with verbose output (remove 2>/dev/null temporarily)
    docker cp -L ET_docker_1:/opt/Cactus/test_results.txt ./
    docker cp -L ET_docker_1:/opt/Cactus/log_files ./log_files_host/
    docker cp -L ET_docker_1:/opt/Cactus/test_outputs ./test_outputs_host/
    
    echo "Copy completed. Waiting..."
    sleep 3
done
```

master
```bash

docker cp -L Cactus/configs/sim/ThornList ET_docker_1:/opt/Cactus/configs/sim/ThornList
docker cp -L run_all_tests.sh ET_docker_1:/opt/Cactus
docker cp -L test_names.txt ET_docker_1:/opt/Cactus
docker cp -L ADMConstraints ET_docker_1:/opt/Cactus/arrangements/EinsteinAnalysis/ADMConstraints

docker exec ET_docker_1 chmod +x /opt/Cactus/run_all_tests.sh
docker exec ET_docker_1 mkdir /opt/Cactus/log_files
docker exec ET_docker_1 bash -c "cd /opt/Cactus && ./simfactory/bin/sim build > ./log_files/build_log.txt"

cd docker_stuff/par_check
python ../../check_docker_tests.py ET_docker_1 ../../test_names.txt ../../Cactus
cd ../..

docker exec ET_docker_1 bash -c "cd /opt/Cactus && ./run_all_tests.sh "

python reanalyze_docker_results.py
mv checked_tests* checked_tests.txt
python map_tests_to_thorns.py


```

I used relative tolerance 1e-6 and absolute tolerance 1e-12 in `checked_tests.txt`. To check with different tolerances (check the folder `tol_test` for more details):
```bash
./tol_test/test_tolerances.sh
```
