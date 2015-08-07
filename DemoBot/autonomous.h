
int blockColor;

void runAutonomous() {
	tHTIRS2 irSeeker;//create a struct
	initSensor(&irSeeker, S3);//initialize the IR sensor

	servo[armServo] = ARM_UP;//lift the arm up
	servo[clawServo] = CLAW_CLOSED;//close the claw around the item

	blockColor = SensorValue[colorSensor];//assign the color of the item in claw to blockColor

	while(SensorValue(touchSensor) == 0) {//while the touch sensor is not pressed
		if(blockColor == (long)BLUECOLOR) {//if the item in claw is blue
			(bool)irSeeker.mode = (irSeeker.mode == DSP_1200);//set the seeking mode to 1200 MHrtz
			if(HTIRS2_AC_DIR == 5) {//if the IR beacon is in zone 5
				//make the robot move forward
				motor[rightMotor] = 50;
				motor[leftMotor] = 50;
			}
			else if(HTIRS2_AC_DIR > 5) {//if the IR beacon is in a zone that is more that 5
				motor[leftMotor] = 50;//give leftMotor 50% power
			}
			else if(HTIRS2_AC_DIR < 5) {//if the IR beacon is in a zone that is less than 5
				motor[rightMotor] = 50;//give rightMotor 50% power
			}//closing of else if
		}//closing of if
		else if(blockColor == (long)YELLOWCOLOR) {//if the item is yellow
			(bool)irSeeker.mode = (irSeeker.mode == DSP_600);//set the seeking mode to 600 MHrtz
			if(HTIRS2_AC_DIR == 5) {//if the IR beacon is in zone 5
				//make the robot move forward
				motor[rightMotor] = 50;
				motor[leftMotor] = 50;
			}
			else if(HTIRS2_AC_DIR > 5) {//if the IR beacon is in a zone that is more than 5
				motor[leftMotor] = 50;//give leftMotor 50% power
			}
			else if(HTIRS2_AC_DIR < 5) {//if the IR beacon is in a zone that is less than 5
				motor[rightMotor] = 50;//give rightMotot 50% power
			}//closing of else if
		}//closing of else if
	}//closing of while
}//closing of function 'runAutonomous'
