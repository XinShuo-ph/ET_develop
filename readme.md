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

while true; do docker cp -L ET_docker_1:/opt/Cactus/log_files ./log_files_host/ 2>/dev/null; docker cp -L ET_docker_1:/opt/Cactus/test_results.txt ./; docker cp -L ET_docker_1:/opt/Cactus/test_outputs ./test_outputs_host/ 2>/dev/null; sleep 3; done

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



docker exec ET_docker_1 bash -c "cd /opt/Cactus && ./run_all_tests.sh "

```
