//use color sensor, distance sensor, and ir sensor

task main(){
	while(//ir beacon is not strong enough){
		motor[motorB] = 70;
		motor[motorC] = 70;
	}
	motor[motorB] = 0;
	motor[motorC] = 0;
	//deposit block
	while(//distance sensor detects near wall){
		motor[motorB] = 70;
		motor[motorC] = 70;
	}
	//turn
	while(//color sensor does not detect white line){
		motor[motorB] = 70;
		motor[motorC] = 70;
	}
	//turn
	//climb ramp
}