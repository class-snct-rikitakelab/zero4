#ifndef _PID_CURVATURE_CONTROL_H
#define _PID_CURVATURE_CONTROL_H

#include "PIDCurvatureCtrlParm.h"
#include "../../NXTSettings.h"

typedef struct{
	float integratedDeviation;
	float bfDeviation;
	float lastMeasurementTime;
	float turn_buf;
	PIDCurvatureCtrlParm mPIDCurvatureCtrlParm;
	MovementDirection movementDirection;
} PIDCurvatureCtrl;

extern void PCC_init(PIDCurvatureCtrl *this_PIDCurvatureCtrl);
extern float PCC_calcCurvatureCtrlVal(PIDCurvatureCtrl *this_PIDCurvatureCtrl,float targCurvature,float curvature,float time);
extern PIDCurvatureCtrlParm PCC_getPIDCurvatureCtrlParm(PIDCurvatureCtrl *this_PIDCurvatureCtrl);
extern void PCC_setPIDCurvatureCtrlParm(PIDCurvatureCtrl *this_PIDCurvatureCtrl,PIDCurvatureCtrlParm parm);
extern void PCC_reset(PIDCurvatureCtrl *this_PIDCurvatureCtrl);
extern void PCC_setMovementDirection(PIDCurvatureCtrl *self,MovementDirection movementDirection);

#endif
