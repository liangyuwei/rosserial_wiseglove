### rosserial_wiseglove

This project is used for transporting dataglove captured data from Windows to Ubuntu, in combination with mocap data measured by Optitrack Motive.
 
# Requirement
1. Install ROS on Windows.
2. Wiseglove(s) hardware.
 
# Usage (together with another repo)
1. Generate ros_lib on Ubuntu machine to obtain GloveState msg description files, and copy them to the folder.
2. Compile the project.
3. ROS Launch arm_hand_capture/start_all_with_image.launch to bring up VRPN server first, then run the executable.
4. Do calibration and save calibration files (for later fine-tuning calibration...) before recording data!!!
