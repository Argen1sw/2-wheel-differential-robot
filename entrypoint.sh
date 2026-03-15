#!/bin/bash

# This entrypoint script is designed to source the ROS 2 Humble setup script and then execute any command passed as arguments to the container.
set -e

# Source the ROS 2 Humble setup script to set up the environment for ROS 2 commands
source /opt/ros/humble/setup.bash

# Print the provided arguments for debugging purposes
echo "Provided arguments: $@"

# Execute the provided command
exec $@