float rpm = 10;
float circumference = 1.5;
int distancetogo = 100;

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
		Wait1Msec(1);
		timemoved += 0.001
	}
	setMotors(0);
}
