#include "LightValListener.h"

void LVL_init(LightValListener *this_LightValListener){
	this_LightValListener->lvlState = 0;
}

void LVL_emergency(LightValListener *this_LightValListener,int parm){
	this_LightValListener->lvlState = 1;
}

int LVL_getState(LightValListener *this_LightValListener){
	return this_LightValListener->lvlState;
}
