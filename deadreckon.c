//const tSensors touchSensor          = (tSensors) S1;   //touch sensor config
//all units in inches
float rpm = 30;
float circumference = 12;
float turnduration = 2.4; //seconds

void setMotors(int powerleft, int powerright){
	motor[motorB] = powerright;
	motor[motorC] = powerleft;
}

void moveDistance(float distancetogo){
	float timetomove = distancetogo / (rpm * circumference);
	timetomove *= 60;
	float timemoved = 0;
	setMotors(100, 100);
	while(timemoved < timetomove){
		wait1Msec(1);
		timemoved += 0.001;
		/*if(!SensorValue(touchSensor) == 1){
			setMotors(100);
			
		}
		else{
			setMotors(0);
		}*/
	}
	setMotors(0);
}

void turn(float degree){
	float duration = abs(degree) * turnduration / 360;
	if(degree > 0){
		setMotors(-100, 100);
	}
	else{
		setMotors(100, -100);
	}
	float timemoved = 0;
	while(timemoved < duration){
		timemoved += 0.001;
		wait1Msec(1);
	}
}

task main(){
	moveDistance(36);
	turn(90);
}
