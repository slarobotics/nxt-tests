#pragma config(Sensor, S1,     touch,          sensorTouch) // touch sensor config

//all units in inches
float rotationdistance = 2;
//float circumference = 12;
int turnticks = 360;
int minDistance = 5;

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

void turn(int ticks){
	nMotorEncoderTarget[motorB] = ticks;
	setMotors(100, 100);
	nSyncedTurnRatio = -100;
	while(nMotorEncoder[motorB] < ticks){
	}
	setMotors(0, 0);
}

 
void stopMotors(){
	setMotors(0, 0); //stop all motors
}

task main(){
	nSyncedMotors = synchBC;
 	moveDistance(36);
	turn(360);
}
