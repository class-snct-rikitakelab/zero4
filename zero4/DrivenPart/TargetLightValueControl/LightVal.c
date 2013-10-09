#include "LightVal.h"
#include "../../Factory.h"

void LV_init(LightVal *this_LightVal){
	this_LightVal->targLightVal = 0.0;
}

float LV_getLightVal(LightVal *this_LightVal){
	float lightVal = BrightnessEncoder_get_brightness_normalize(&brightnessEncoder);

	if(LVR_checkRange(&mLightValRange,lightVal) == 0)
		LVL_emergency(&mLightValListener,lightVal);

	return lightVal;


}

float LV_getTargLightVal(LightVal *this_LightVal){
	return this_LightVal->targLightVal;
}

void LV_setTargLightVal(LightVal *this_LightVal,float parm){
	this_LightVal->targLightVal = parm;
}

LightValRange LV_getLightValRange(LightVal *this_LightVal){
	return mLightValRange;
}

void LV_setLightValListener(LightVal *this_LightVal,LightValListener LVL){
	mLightValListener = LVL;
}

void LV_setLightValRange(LightVal *this_LightVal,LightValRange LVR){
	mLightValRange = LVR;
}

