#pragma config(Sensor, S1,     colorPort,           sensorCOLORFULL)

int powerLeft = 100;
int powerRight = 100;
task main()
{
	wait10Msec(3);
	while(1){
		if(SensorValue[colorPort] == 6){ //if we see light, turn right
				powerLeft = 35;
		}
		else powerLeft = 100;
		if(SensorValue[colorPort] < 6){
			powerRight = 35;
		}
		else powerRight = 100;
		motor[motorC] = powerLeft;
		motor[motorB] = powerRight;
	}
}
