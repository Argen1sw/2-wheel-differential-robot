# This gives the container access to the X server, 
# allowing GUI applications to run inside the container and display on the host machine.
xhost local:root


# XAUTH=/tmp/.docker.xauth

docker run -it \
    --user ros \
    --net=host \
    --ipc=host \
    -v $PWD/2-wheel-differential-robot:/home/ros_ws/src \
    -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
    --env=DISPLAY \
    --env ROS_DOMAIN_ID=30 \
    -v /dev/input:/dev/input \
    --device-cgroup-rule='c 13:* rmw' \
    2-wheel-diff-robot:latest \
    # Nvidia
    --runtime=nvidia \
    --gpus all \
    bash

echo "Done."