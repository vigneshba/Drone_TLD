# Drone_TLD (shadow) : A drone tracker_follower using OpenTLD

## Packages Required
- [ardrone_autonomy](https://github.com/AutonomyLab/ardrone_autonomy)

## Installation
- Download shadow package and Drone_TLD. Drone_TLD is the rosified verison of the [OpenTLD](https://github.com/zk00006/OpenTLD) by Zdenek Kalal.   
`git clone https://github.com/HALLAB-Halifax/Drone_TLD.git`
- catkin_make the shadow package.
- You need to add ROS support to MATLAB for Drone_TLD to work. Refer to [ROS support for MATLAB](http://www.mathworks.com/hardware-support/robot-operating-system.html?refresh=true) to install it.

## Get it running
- Connect to AR.Drone's network and initiate roscore.
- Run ardrone_autonomy to setup the topics to communicate with the AR.Done.  
`rosrun ardrone_autonomy ardrone_driver`
- Run the file run_TLD.m of Drone_TLD on Matlab.
- In the window showing the camera frame draw a bounding box over the target.
- Next run shadow to get the drone to follow the target.   
`rosrun shadow shadow`
- Watch the drone follow the target. Have Fun! :)
 
## Troubleshooting

**Drone_TLD**

- Compile.m: Make sure the veriables `include` and `libpath` point to the right directories. If unsure, use the terminal to get the paths.  
`pkg-config --cflags opencv` for include   
`pkg-config --libs opencv` for libpath
	
- tldExample.m  
	1) Specify the topic to subscribe from for the camera feed.  
	2) Two callback functions are available. Use `functionrgb` when the subscribed topic is color else use `funcBW` for grayscale input.

- For further info or toubleshooting on TLD refer to the issues section of [OpenTLD](https://github.com/zk00006/OpenTLD)
