
long blockColor;

void runAutonomous() {
	tHTIRS2 irSeeker;//create a struct
	initSensor(&irSeeker, S3);//initialize the IR sensor

	servo[clawServo] = CLAW_CLOSED;//close the claw around the item
	servo[armServo] = ARM_DOWN;//lift the arm up

	blockColor = SensorValue[colorSensor];//assign the color of the item in claw to blockColor

	if(blockColor == (long)GREENCOLOR || blockColor == (long)BLUECOLOR) {//if the item in claw is blue
		(bool)irSeeker.mode = (irSeeker.mode == DSP_1200);//set the seeking mode to 1200 MHrtz
	}
	else if(blockColor == (long)WHITECOLOR || blockColor == (long)REDCOLOR) {//if the item is yellow
		(bool)irSeeker.mode = (irSeeker.mode == DSP_600);//set the seeking mode to 600 MHrtz
	}//closing of else if
	else {
		return;
	}
	while(SensorValue(touchSensor) == 0) {//while the touch sensor is not pressed
		readSensor(&irSeeker);

		if(irSeeker.acDirection == 5) {//if the IR beacon is in zone 5
			//make the robot move forward
			motor[rightMotor] = 50;
			motor[leftMotor] = 50;
		}
		else if(irSeeker.acDirection < 5) {//if the IR beacon is in a zone that is more that 5
			motor[leftMotor] = 50;//give leftMotor 50% power
			motor[rightMotor] = 0;
		}
		else if(irSeeker.acDirection > 5) {//if the IR beacon is in a zone that is less than 5
			motor[leftMotor] = 0;
			motor[rightMotor] = 50;//give rightMotor 50% power
		}//closing of else if
	}//closing of while
	return;
}//closing of function
