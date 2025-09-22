Docker is used to compile, run, and test the Einstein Toolkit in a container.
Erik Schnetter's docker image (https://hub.docker.com/r/rynge/einsteintoolkit) is used.

Quick notes:

To pull the image:
```bash
docker pull rynge/einsteintoolkit
```

To run the container in the terminal:
```bash
docker run -it --name <container_name> rynge/einsteintoolkit /bin/bash
```

To check the currently running containers:
```bash
docker ps
```
It will show something like this:
```bash
$ docker ps
CONTAINER ID   IMAGE                   COMMAND       CREATED             STATUS             PORTS     NAMES
ed4c8d2354c4   rynge/einsteintoolkit   "/bin/bash"   About an hour ago   Up About an hour             gifted_nash
```

To copy folder/file to/from the container to the host:
```bash
docker cp <container_id>:<path_in_container> <path_on_host>  # from container to host
docker cp <path_on_host> <container_id>:<path_in_container>  # from host to container
```
The `../Cactus` stuff in this folder is copied using this command `docker cp ed4c8d2354c4:/opt/Cactus ../`.
The container id can also be replaced with the container name, so that we have control.

To delete the container:
```bash
docker rm <container_id>
```
The container id can also be replaced with the container name.
