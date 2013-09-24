//const tSensors touchSensor          = (tSensors) S1;   //touch sensor config
//all units in inches
float rotationdistance = 2;
//float circumference = 12;
//float turnduration = 2.4; //seconds

void setMotors(int powerleft, int powerright){
	motor[motorB] = powerright;
	motor[motorC] = powerleft;
}

void moveDistance(float distancetogo){
	float ticksneeded = (distancetogo / (rotationdistance)) * 360;
	nMotorEncoderTarget[motorB] = ticksneeded;
	setMotors(100, 100);
	nSyncedTurnRatio = +100;
	while(nMotorEncoder[motorB] < ticksneeded){
	}
	setMotors(0, 0);
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
	nSyncedMotors = synchBC;
	moveDistance(36);
	turn(90);
}
