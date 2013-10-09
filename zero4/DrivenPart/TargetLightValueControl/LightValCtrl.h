#ifndef _LIGHT_VAL_CTRL_H
#define _LIGHT_VAL_CTRL_H

#include "PIDLightValCtrl.h"
#include "PIDLightValCtrlParm.h"
#include "LightVal.h"
#include "LightValCtrlState.h"

typedef struct{
	LightValCtrlState LV_CtrlState;
	PIDLightValCtrl *mPIDLightValCtrl;
	float turn;
}LightValCtrl;



extern void LVC_init(LightValCtrl *self,PIDLightValCtrl *PLVC);
extern void LVC_setTargLightVal(LightValCtrl *self,int parm);
extern int LVC_getTargLightValCtrl(LightValCtrl *self);
extern void LVC_setCtrlParm(LightValCtrl *self,PIDLightValCtrlParm *parm);
extern PIDLightValCtrlParm* LVC_getCtrlParm(LightValCtrl *self);
extern void LVC_startCtrl(LightValCtrl *self);
extern void LVC_stopCtrl(LightValCtrl *self);
extern void LVC_doCtrl(LightValCtrl *self);
extern float LVC_run(LightValCtrl *self);
extern void LVC_changeMode(LightValCtrl *self,LightValCtrlState state);
extern LightValRange LVC_getLightValRange(LightValCtrl *self);
extern void LVC_setLightValRange(LightValCtrl *self,LightValRange LVR);
extern void LVC_setLightValListener(LightValCtrl *self,LightValListener LVL);


#endif
