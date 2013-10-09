#include "Speed.h"
#include "../../Factory.h"

void S_init(Speed *this_Speed){
	this_Speed->targSpeed = 0;
	this_Speed->bfSpeed = 0;
}

float S_getSpeed(Speed *this_Speed,int time){

	float speed = SpeedEncoder_get_speed(&speedEncoder);

	this_Speed->bfSpeed = speed;
	return speed;
}

float S_getBfSpeed(Speed *this_Speed){
	return this_Speed->bfSpeed;
}

float S_getTargSpeed(Speed *this_Speed){
	return this_Speed->targSpeed;
}

void S_setTargSpeed(Speed *this_Speed,int parm){
	this_Speed->targSpeed = parm;
}
