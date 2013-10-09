#ifndef _PID_SPEED_CTRL_H
#define _PID_SPEED_CTRL_H

#include "PIDSpeedCtrlParm.h"

typedef struct{
	float integratedDeviation;
	float bfDeviation;
	float lastMeasurementTime;
	float buf_forward;
	PIDSpeedCtrlParm mPIDSpeedCtrlParm;
}PIDSpeedCtrl;

extern void PSC_init(PIDSpeedCtrl *this_PIDSpeedCtrl);
extern float PSC_calcSpeedCtrlVal(PIDSpeedCtrl *this_PIDSpeedCtrl,float targSpeed,float bfSpeed,float speed,float time);
extern PIDSpeedCtrlParm PSC_getPIDSpeedCtrlParm(PIDSpeedCtrl *this_PIDSpeedCtrl);
extern void PSC_setPIDSpeedCtrlParm(PIDSpeedCtrl *this_PIDSpeedCtrl,PIDSpeedCtrlParm parm);
extern void PSC_reset(PIDSpeedCtrl *this_PIDSpeedCtrl);

#endif
