//all units are in inches
foat rpm = 30;
float circumference = 12;
int distancetogo = 24;

void setMotors(int power){
	motor[motorB] = power;
	motor[motorC] = power;
}

task main(){
	float timetomove = distancetogo / (rpm * circumference);
	timetomove *= 60;
	float timemoved = 0;
	setMotors(100);
	while(timemoved < timetomove){
		Wait1Msec(1)
		timemoved += 0.001
	}
	setMotors(0);
}