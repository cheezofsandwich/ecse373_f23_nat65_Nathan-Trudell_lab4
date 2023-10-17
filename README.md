## ECSE 473 Lab 4
#### Nathan Trudell

#### Description
This package utilizes the STDR simulator to simulate arobot in an environemnt and practice moving it around while preventing collision with walls using laser data. This package is developed in ROS noetic.


#### Required Packages and Dependencies

##### Required to run:
stdr simulator (not publicly available)
roscpp
sensor_msgs
geometry_msgs

##### Required for full functionality
rqt_gui


#### How to Run:
Download entire package from Github.

source devel/setup.bash

Run for entire workspace:
catkin_make

Construct node:
catkin_make no_crash_node

Launch:
roslaunch robot_no_crash robot_no_crash.launch

Launch can be fed a Namespace (default is robot)ns="robot0"). This allows the use of multiple robots at one time.


#### Contributors
Coded by Nathan Trudell as a part of the ECSE 473 course by Dr. Gregory Lee at CWRU.

