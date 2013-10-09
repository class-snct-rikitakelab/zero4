#ifndef _SPEED_CTRL_H
#define _SPEED_CTRL_H

#include "Speed.h"
#include "PIDSpeedCtrl.h"
#include "SpeedCtrlState.h"

typedef struct{
	SpeedCtrlState S_CtrlState;
	PIDSpeedCtrl *mPIDSpeedCtrl;
} SpeedCtrl;


Speed mSpeed;

extern void SC_init(SpeedCtrl *self,PIDSpeedCtrl *PSC);
extern void SC_setTargSpeed(SpeedCtrl *self,int parm);
extern float SC_getTargSpeedCtrl(SpeedCtrl *self);
extern void SC_setCtrlParm(SpeedCtrl *self,PIDSpeedCtrlParm parm);
extern PIDSpeedCtrlParm SC_getCtrlParm(SpeedCtrl *self);
extern void SC_startCtrl(SpeedCtrl *self);
extern void SC_stopCtrl(SpeedCtrl *self);
extern void SC_doCtrl(SpeedCtrl *self);
extern void SC_run(SpeedCtrl *self);
extern void SC_changeMode(SpeedCtrl *self,SpeedCtrlState state);

#endif
