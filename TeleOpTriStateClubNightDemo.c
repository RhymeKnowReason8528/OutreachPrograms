#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     leftDrive,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     rightDrive,    tmotorTetrix, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

//ranges: motor power = -100 to +100, joystick = -128 to +128.
//For more prescise movement we normalize the values
const float multiplier = 0.3906;// used to normalize joystick values
const int driveLowerThreshold = 15;//prevents motors from straining at very low power if the joystick is not at center
int drivePowerBoost = 100;
//int driveUpperThreshold = 85;

task main()
{
	while (true)//infinite loop
	{
		getJoystickSettings(joystick);	//retrieves current joystick positions
//Drive Code
		float leftPower = joystick.joy1_y1;
		float rightPower = joystick.joy1_y2;

//left motor normalization and stopping at low joystick value
		if(abs(leftPower) <= driveLowerThreshold){	//if absolute value is < 15
			leftPower = 0;	//stop motors
		}
		else if(joy1Btn(8) == 1){	//power boost btn
			if(leftPower < 0){
				leftPower = drivePowerBoost*-1;
			}
			else{
			leftPower = drivePowerBoost;	//set to high power
			}
		}//end of else-if
		else{
			leftPower = joystick.joy1_y1*multiplier;	//normalize
			//if(leftPower > driveUpperThreshold){	//sets it to lower power than power boost so
				//leftPower = driveUpperThreshold;
			//}
		}

//right motor normalization and stopping at low joystick value
		if(abs(rightPower) <= driveLowerThreshold){	//if absolute value is < 15
			rightPower = 0;	//stop motors
		}
		else if(joy1Btn(8) == 1){	//power boost btn
			if(rightPower < 0){	//if its a negative #
				rightPower = drivePowerBoost*-1;	//set to 100 reverse power
			}
			else{	//other wise- meaning it is a positve #
			rightPower = drivePowerBoost;	//set to 100 forward power
			}
		}	//end of else-if
		else{
			rightPower = joystick.joy1_y2*multiplier;	//normalize
			//if(rightPower > driveUpperThreshold){	//sets it to lower power than power boost so
			//	rightPower = driveUpperThreshold;
			//}
		}
//setting both motor powers
		motor[leftDrive] = leftPower;
		motor[rightDrive] = rightPower;
	}//end bracket of loop
}//end task main bracket
