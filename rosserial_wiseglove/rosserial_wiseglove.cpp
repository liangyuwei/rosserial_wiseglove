#include "stdafx.h"
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

// ROS related (note that a different order of includes of ros.h and Windows.h cause build errors!!!)
#include "ros.h"
//#include "ros/time.h" // for ros::rate
#include <Windows.h>
#include "arm_hand_capture\GloveState.h"


// For Wiseglove
#include "Wiseglove.h"

// For responding keyboard interrupt
#include <conio.h>

using std::string;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// Set up Wiseglove SDK
	WiseGlove *g_pGlove_l = GetWiseGlove();
	WiseGlove *g_pGlove_r = GetWiseGlove();

	if (g_pGlove_l == NULL || g_pGlove_r == NULL)
	{
		printf("Failed to create glove handles!\n");
		system("pause");
		return -1;
	}

	// Number of gloves
	int com = g_pGlove_l->Scan();
	g_pGlove_r->Scan(); // should scan the ports to get the information needed later for opening ports
	if (com == 0)
	{
		printf("No Glove connected on this system now!\n");
		system("pause");
		g_pGlove_l->Close();
		DelWiseGlove(g_pGlove_l);
		g_pGlove_r->Close();
		DelWiseGlove(g_pGlove_r);
		return 0;
	}
	else if (com == 1)
	{
		printf("Only one glove is connected !!!Check the connection !!!\n");
		system("pause");
		g_pGlove_l->Close();
		DelWiseGlove(g_pGlove_l);
		g_pGlove_r->Close();
		DelWiseGlove(g_pGlove_r);
		return 0;
	}
	else
	{
		printf("Both gloves are connected!\n");
	}
	printf("Number of gloves(com ports): %d.\n", com);

	// Return port and baudrate (Note that left glove should be plugged in before right glove !!!)
	unsigned int comport_l = g_pGlove_l->GetPort(0);
	unsigned int combaudrate_l = g_pGlove_l->GetPortBaudrate(0);
	unsigned int comport_r = g_pGlove_r->GetPort(1);
	unsigned int combaudrate_r = g_pGlove_r->GetPortBaudrate(1);

	// Open port
	bool isopen_l = g_pGlove_l->Open(comport_l, combaudrate_l);
	bool isopen_r = g_pGlove_r->Open(comport_r, combaudrate_r);
	if (isopen_l && isopen_r)
	{
		printf("Ports are opened for both Gloves!\n");
	}
	else
	{
		printf("Failed to open port!\n");
		printf("isopen_l: %d, isopen_r: %d\n", isopen_l, isopen_r);
		system("pause");
		g_pGlove_l->Close();
		DelWiseGlove(g_pGlove_l);
		g_pGlove_r->Close();
		DelWiseGlove(g_pGlove_r);
		return -1;
	}

	// Output information
	char model[32]; // model number
	char manu[32]; // manufacturer string
	char sn[32]; // serial number
	int num_sensor;
	int num_pressure;
	float angle_l[14]; // for one glove
	float angle_r[14];
	unsigned short elec_l[14]; // for collecting electrical signal value
	unsigned short elec_r[15];
	//std::vector<double> angle_vec;
	//double d_angle[14];
	g_pGlove_l->GetModel(model);
	g_pGlove_l->GetManu(manu);
	g_pGlove_l->GetSn(sn);
	num_sensor = g_pGlove_l->GetNumOfSensor();  // Number of bend sensors
	num_pressure = g_pGlove_l->GetNumOfPressure(); // Number of pressure sensors
	printf("===== Left hand glove =====\n");
	printf("Model: %s\n", model);
	printf("Manufaturer string: %s\n", manu);
	printf("Serial number: %s\n", sn);
	printf("Finger sensors: %d, pressure sensors: %d\n", num_sensor, num_pressure);
	g_pGlove_r->GetModel(model);
	g_pGlove_r->GetManu(manu);
	g_pGlove_r->GetSn(sn);
	num_sensor = g_pGlove_r->GetNumOfSensor();  // Number of bend sensors
	num_pressure = g_pGlove_r->GetNumOfPressure(); // Number of pressure sensors
	printf("===== Right hand glove =====\n");
	printf("Model: %s\n", model);
	printf("Manufaturer string: %s\n", manu);
	printf("Serial number: %s\n", sn);
	printf("Finger sensors: %d, pressure sensors: %d\n", num_sensor, num_pressure);

	printf("===== Usage =====\n");
	printf("Press \'R\': Reset calibration for right hand glove.\n");
	printf("Press \'L\': Reset calibration for left hand glove.\n");
	printf("Press \'S\': Save calibration files for both gloves.\n");
	printf("Press \'I\': Import previous calibration results from files, for both gloves.\n");
	printf("Press \'Q\': Quit the program.\n");

	// Before publishing
	printf("Press any key to start publishing!!!\n");
	system("pause");

	// Start publishing
	std::vector<double> l_angle_vec(14);
	std::vector<double> r_angle_vec(14);
	std::vector<uint64_t> l_glove_elec_vec(14);
	std::vector<uint64_t> r_glove_elec_vec(14);

	/* Note that the definition and initialization should stay as close to .publish() as possible!!! */
	ros::NodeHandle nh;
	// Connect to a remote ROS master
	char *ros_master = "192.168.66.2"; //:11411";
	printf("Connecting to server at %s\n", ros_master);
	nh.initNode(ros_master);
	// Set up a publisher for sending the glove state
	arm_hand_capture::GloveState glove_state;
	ros::Publisher pub("wiseglove_state_pub", &glove_state);
	nh.advertise(pub);
	while (1)
	{

		// Detect keyboard interrupt (non-blocking)
		if (_kbhit())
		{
			char ch = _getch();
			// use absolute path to ensure correctness!!! in case of unknown errors !!!
			char *filename_l = "C:\\Documents\\rosserial_wiseglove\\rosserial_wiseglove\\x64\\Release\\calib_files\\calib_l.txt"; 
								//"calib_l.txt";
			char *filename_r = "C:\\Documents\\rosserial_wiseglove\\rosserial_wiseglove\\x64\\Release\\calib_files\\calib_r.txt";
								//"calib_r.txt";
							  
			// Calibration for right hand glove
			if (ch == 'r')
			{
				printf("Reset glove for calibration!\n");
				g_pGlove_r->ResetCalib();  // Reset finger sensors
				// note that calibration mode is set to Auto Calib after this reset operation
			}
			// Calibration for left hand glove
			if (ch == 'l')
			{
				printf("Reset glove for calibration!\n");
				g_pGlove_l->ResetCalib();  // Reset finger sensors
				// note that calibration mode is set to Auto Calib after this reset operation
			}
			// Save calibration data
			// *** note that this can only be used when the program is executed by double click in file system, 
			// instead of inside VS!!!
			if (ch == 's')
			{
				printf("Saving calibration data.....\n");
				printf("Set Calibration Mode to Manual before storing calibration files!!!\n");
				g_pGlove_l->SetCalibMode(CALIB_MANU);
				g_pGlove_r->SetCalibMode(CALIB_MANU);
				bool result_l = g_pGlove_l->SaveCalib(filename_l);
				bool result_r = g_pGlove_r->SaveCalib(filename_r);
				if (result_l)
					printf("Left glove calibration file stored successfully!\n");
				else
					printf("Failed to store left glove calibration data!!!\n");
				if (result_r)
					printf("Right glove calibration file stored successfully!\n");
				else
					printf("Failed to store right glove calibration data!!!\n");
				system("pause");
				printf("Done!\n");
			}
			// Import saved calibration(in case only program is restarted, while glove hasn't been taken off since last calibration.)
			if (ch == 'i')
			{
				printf("Loading calibration data.....\n");
				printf("Set Calibration Mode to Manual before importing calibration files!!!\n");
				g_pGlove_l->SetCalibMode(CALIB_MANU);
				g_pGlove_r->SetCalibMode(CALIB_MANU);
				bool result_l = g_pGlove_l->LoadCalib(filename_l);
				bool result_r = g_pGlove_r->LoadCalib(filename_r);
				if (result_l)
					printf("Left glove calibration file loaded successfully!\n");
				else
					printf("Failed to load left glove calibration data!!!\n");
				if (result_r)
					printf("Right glove calibration file loaded successfully!\n");
				else
					printf("Failed to load right glove calibration data!!!\n");
				system("pause");
				printf("Done!\n");
			}
			// Quit the program
			if (ch == 'q')
			{
				printf("Quiting...");
				break;
			}

			// Check out the joint angle
			if (ch == 'c')
			{
				printf("===== Joint Angle Range =====\n");
				printf("== Left Glove ==\n");
				for (unsigned int j = 0; j < num_sensor; j++)
					std::cout << "S" << j << ": (" << g_pGlove_l->GetMin_adj(j) << ", " << g_pGlove_l->GetMax_adj(j) << "), range is " << g_pGlove_l->GetCalibRange(j) << std::endl;
				printf("== Right Glove ==\n");
				for (unsigned int j = 0; j < num_sensor; j++)
					std::cout << "S" << j << ": (" << g_pGlove_r->GetMin_adj(j) << ", " << g_pGlove_r->GetMax_adj(j) << "), range is " << g_pGlove_r->GetCalibRange(j) << std::endl;
				system("pause");
			}
		}

		// Update glove state
		glove_state.header.stamp = nh.now();//ros::Time::now();
		unsigned long validdata_l = g_pGlove_l->GetAngle(angle_l);
		unsigned long validdata_r = g_pGlove_r->GetAngle(angle_r);
		unsigned int validdata_l_elec = g_pGlove_l->GetData(elec_l);
		unsigned int validdata_r_elec = g_pGlove_r->GetData(elec_r);

		//printf("validdata is: %d\n", validdata);
		if (validdata_l > 0 && validdata_r > 0 && validdata_l_elec > 0 && validdata_r_elec > 0)
		{
			// Left glove
			printf("Left Angles: ");
			for (int j = 0; j < num_sensor; j++)
			{
				printf("%4.1f ", angle_l[j]);
				l_angle_vec[j] = (double) angle_l[j];
			}
			printf("\n");

			// Right glove
			printf("Right Angles: ");
			for (int j = 0; j < num_sensor; j++)
			{
				printf("%4.1f ", angle_r[j]);
				r_angle_vec[j] = (double)angle_r[j];
			}
			printf("\n");

			// Left glove electrical signal
			//printf("Left Glove Data: ");
			for (int j = 0; j < num_sensor; j++)
			{
				//printf("%d ", elec_l[j]);
				l_glove_elec_vec[j] = (uint64_t) elec_l[j];
			}
			//printf("\n");

			// Right glove electrical signal
			//printf("Right Glove Data: ");
			for (int j = 0; j < num_sensor; j++)
			{
				//printf("%d ", elec_r[j]);
				r_glove_elec_vec[j] = (uint64_t) elec_r[j];
				//printf("%d ", r_glove_elec_vec[j]);
			}
			//printf("\n");

			glove_state.left_glove_state = l_angle_vec.data();
			glove_state.left_glove_state_length = l_angle_vec.size();
			glove_state.right_glove_state = r_angle_vec.data();
			glove_state.right_glove_state_length = r_angle_vec.size();

			glove_state.l_glove_elec = l_glove_elec_vec.data();
			glove_state.l_glove_elec_length = l_glove_elec_vec.size();
			glove_state.r_glove_elec = r_glove_elec_vec.data();
			glove_state.r_glove_elec_length = r_glove_elec_vec.size();

			// Publish the new glove state
			pub.publish(&glove_state);

			// Spin once to publish the buffered message
			nh.spinOnce();

		}
		else
		{
			printf("Failed to get angle!\n");
		}

		// Sleep for 100 ms
		Sleep(10);

	}


	// Close Glove
	g_pGlove_l->Close();
	DelWiseGlove(g_pGlove_l);
	g_pGlove_r->Close();
	DelWiseGlove(g_pGlove_r);
	
	printf("Publisher shut down!\n");
	return 0;
}
