#include "JoystickDriver.c" 
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

/*
* Touch sensors have 2 states, these states are
* stored in SensorValue(touch). touch is the name of 
* the default sensor in this file
*/

bool checkIfTouching(){
	if (SensorValue(touch) == 1){ //on state
		return true;
	} else return false; 
}

void initBlockKick(){
	if (checkIfTouching() == true){
		turn(45); //this turned 45 degrees before ticks, not sure if will work now
	}
	
}

//I took this from the robotc joystick example- It should work with the motors,
void initControl(){
	int threshold = 20;             /* Int 'threshold' will allow us to ignore low      
                                	 readings that keep our robot in perpetual motion. */

  while(true)                            // Infinite loop:
  {
    getJoystickSettings(joystick); // get state of joystick
    if(abs(joystick.joy1_y2) > threshold) //right joystick readings
    {
      motor[motorB] = joystick.joy1_y2;         
    else                                    
    {
      motor[motorB] = 0;                        
    }


    if(abs(joystick.joy1_y1) > threshold)  //left joystick 
    {
      motor[motorC] = joystick.joy1_y1;        
    }
    else                                    
    {
      motor[motorC] = 0;                        
    }
  }
}

/* 
* This is for the ultrasonic sensor,
* which has states from 0-255, which is 
* the distance in CM
* sonar is the default UV sensor here
*/

void stopMotors(){
	setMotors(0, 0); //stop all motors
}

void autonomus(){
	//this is the function for autonomus mode
	moveDistance(36);
	turn(360);
}

task main(){
	nSyncedMotors = synchBC;
	autonomus(); // calls the function for autonomus 
	while (true){ //starts the joystick control 
		initcontrol();
	}
}
