#ifndef _LIGHT_VAL_RANGE_H
#define _LIGHT_VAL_RANGE_H

typedef struct{
	int upperLimit;
	int lowerLimit;
}LightValRange;

extern int LVR_getUpperLimit(LightValRange *this_LightValRange);
extern void LVR_setUpperLimit(LightValRange *this_LightValRange,int parm);
extern int LVR_getLowerLimit(LightValRange *this_LightValRange);
extern void LVR_setLowerLimit(LightValRange *this_LightValRange,int parm);
extern void LVR_init(LightValRange *this_LightValRange);
extern int LVR_checkRange(LightValRange *this_LightValRange,int parm);

#endif
