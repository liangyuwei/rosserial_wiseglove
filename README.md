# rosserial_wiseglove

This repo is used for transporting finger joint angles measured by datagloves (Wiseglove) from Windows to Ubuntu, so as to be sync-ed with mocap data captured by Optitrack Motive software.  

For time synchronization of dataglove and motion capture system, refer to the package [```arm_hand_capture```](https://github.com/liangyuwei/sign_language_robot/tree/master/arm_hand_capture) in repo [sign_language_robot](https://github.com/liangyuwei/sign_language_robot).

 
## Requirements
1. Install ROS on Windows.
2. Optitrack Motive.
3. Wiseglove(s) hardware (Used to be S14. Now we use S15, which consists of 15 sensors for one hand, including flexion/extension, abduction/adduction, and others).

 
## Usage (together with another repo)
1. Generate message header files in ```ros_lib``` folder on Ubuntu machine to obtain GloveState msg description, as explained [here](http://wiki.ros.org/rosserial/Tutorials/Adding%20Other%20Messages), and copy them to the root of this project.
```
rosrun rosserial_client make_libraries ros_lib/
```


2. Compile the project.  
```catkin_make```


3. ROS Launch ```arm_hand_capture/start_all_with_image.launch``` on Ubuntu to bring up VRPN server first, then run the executable of this project.


4. Perform calibration gestures and save calibration files (for later fine-tuning calibration...) before recording data!!!
