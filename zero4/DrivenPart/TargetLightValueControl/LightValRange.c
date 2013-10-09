#include "LightValRange.h"

void LVR_init(LightValRange *this_LightValRange){
	this_LightValRange->lowerLimit = 0;
	this_LightValRange->upperLimit = 1023;
}

int LVR_getUpperLimit(LightValRange *this_LightValRange){
	return this_LightValRange->upperLimit;
}

void LVR_setUpperLimit(LightValRange *this_LightValRange,int parm){
	this_LightValRange->upperLimit = parm;
}

int LVR_getLowerLimit(LightValRange *this_LightValRange){
	return this_LightValRange->lowerLimit;
}

void LVR_setLowerLimit(LightValRange *this_LightValRange,int parm){
	this_LightValRange->lowerLimit = parm;
}

int LVR_checkRange(LightValRange *this_LightValRange,int parm){
	if(parm <= LVR_getLowerLimit(this_LightValRange) || parm >= LVR_getUpperLimit(this_LightValRange))
		return 0;
	else
		return 1;
}


