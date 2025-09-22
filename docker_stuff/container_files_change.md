# files changed or added

```
/opt/Cactus/configs/sim/ThornList
/opt/Cactus/run_all_tests.sh
/opt/Cactus/test_names.txt
/opt/Cactus/arrangements/EinsteinAnalysis/ADMConstraints
```

# commands

to make the changes after the container is running (`docker cp -L ET_docker_1:/opt/Cactus/COPYRIGHT . `)

run this in the father folder (ET_develop if I didn't change it)
```bash
docker cp -L Cactus/configs/sim/ThornList ET_docker_1:/opt/Cactus/configs/sim/ThornList
docker cp -L run_all_tests.sh ET_docker_1:/opt/Cactus
docker cp -L test_names.txt ET_docker_1:/opt/Cactus
docker cp -L ADMConstraints ET_docker_1:/opt/Cactus/arrangements/EinsteinAnalysis/ADMConstraints
```

# notes

To save compilation time, we desabled Formaline. This is done simply by changing the `ThornList` file in the container (commenting out the line `CactusUtils/Formaline`). 

I collected all test names and have a script to run all tests. (thus the `test_names.txt` and `run_all_tests.sh` files)

A lot of tests are complaining the missing of Thorn `ADMConstraints`. I get it from `git clone https://bitbucket.org/einsteintoolkit/einsteinanalysis.git` and copied the `ADMConstraints` folder here.
