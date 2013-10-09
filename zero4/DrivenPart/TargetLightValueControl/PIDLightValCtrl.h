#ifndef _PID_LIGHT_VAL_CTRL_H
#define _PID_LIGHT_VAL_CTRL_H

#include "PIDLightValCtrlParm.h"
#include "LightVal.h"
#include "../../EncoderPart/BrightnessEncoder.h"
#include "../../logSend.h"
#include "../../NXTSettings.h"


typedef struct{
	float integratedDeviation;
	float bfDeviation;
	float lastMeasurementTime;
	PIDLightValCtrlParm *mPIDLightValCtrlParm;
	MovementDirection movementDirection;
}PIDLightValCtrl;



extern void PLVC_init(PIDLightValCtrl *self,PIDLightValCtrlParm *parm);
extern float PLVC_calcCtrlVal(PIDLightValCtrl *self,float targLightVal,float LightVal,float time);
extern void PLVC_setCtrlParm(PIDLightValCtrl *self,PIDLightValCtrlParm *parm);
extern void PLVC_setMovementDirection(PIDLightValCtrl *self,MovementDirection movementDirection);

extern PIDLightValCtrlParm* PLVC_getCtrlParm(PIDLightValCtrl *self);
extern void PLVC_reset(PIDLightValCtrl *self);

#endif
