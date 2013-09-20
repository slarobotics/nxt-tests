const tSensors touchSensor          = (tSensors) S1;   //touch sensor config
//all units in inches
float rpm = 30;
float circumference = 12;

void setMotors(int power){
	motor[motorB] = power;
	motor[motorC] = power;
}

void moveDistance(float distancetogo){
	float timetomove = distancetogo / (rpm * circumference);
	timetomove *= 60;
	float timemoved = 0;
	while(timemoved < timetomove){
		wait1Msec(1);
		if(!SensorValue(touchSensor) == 1){
			setMotors(100);
			timemoved += 0.001;
		}
		else{
			setMotors(0);
		}
	}
	setMotors(0);
}

task main(){
	moveDistance(36);
}
