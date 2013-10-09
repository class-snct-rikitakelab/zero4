#ifndef _LIGHT_VAL_H
#define _LIGHT_VAL_H

#include "LightValListener.h"
#include "LightValRange.h"
#include "../../EncoderPart/BrightnessEncoder.h"

typedef struct{
	float targLightVal;
}LightVal;


extern void LV_init(LightVal *this_LightVal);
extern float LV_getLightVal(LightVal *this_LightVal);
extern float LV_getTargLightVal(LightVal *this_LightVal);
extern void LV_setTargLightVal(LightVal *this_LightVal,float parm);
extern LightValRange LV_getLightValRange(LightVal *this_LightVal);
extern void LV_setLightValListener(LightVal *this_LightVal,LightValListener LVL);
extern void LV_setLightValRange(LightVal *this_LightVal,LightValRange LVR);

#endif
