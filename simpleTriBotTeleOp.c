#pragma config(Motor,  motorA,          arm,           tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftDrive,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightDrive,    tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//!use with standard LEGO tribot!/

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}

task main()
{
  initializeRobot();

  waitForStart();   // wait for start of tele-op phase

  nMotorEncoder[arm] = 0;

  while (true)
  {
	  if(abs(joystick.joy1_y1) < 15){
	  	motor[rightDrive] = 0;
	  }
	  else{
	  	motor[rightDrive] = joystick.joy1_y1;
	  }

	  if(abs(joystick.joy1_y2) < 15){
	  	motor[leftDrive] = 0;
	  }
	  else{
	  	motor[leftDrive] = joystick.joy1_y2;
	  }

	  if(joy1Btn(7) == 1 && nMotorEncoder[arm] > 0){
	  	motor[arm] = 30;
	  }
	  else if(joy1Btn(8) == 1 && nMotorEncoder[arm] < 50){
	  	motor[arm] = -30;
	  }
	  else{
	  	motor[arm] = 0;
	  }

  }//end of while
}//end task main
