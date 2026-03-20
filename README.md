# This project features a 2 wheel differential robot similar to a comercial vacuum cleaner roomba.

### I put it together using an old/used robotic vacuum cleaner from cleanfix, videos from articulated robotics, arduino, motor drivers and ROS2.

### Physical Robot:

To run the robot:

`ros2 launch ld08_driver ld08.launch.py `

And then:

`ros2 launch robot_description launch_sim.launch.py`

### Simulation

To run the simulation:

`ros2 launch robot_description launch_sim.launch.py world:=src/robot_description/worlds/my_world `

To move the robot around with the keyboard use

`ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args -r /cmd_vel:=/diff_cont/cmd_vel_unstamped`

