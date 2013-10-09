#ifndef DRIVENPART_TARGETDIRECTIONCONTROL_DIRECTION_CTRL_H
#define DRIVENPART_TARGETDIRECTIONCONTROL_DIRECTION_CTRL_H

#include "Curvature.h"
#include "PIDCurvatureCtrl.h"
#include "CurvatureCtrlState.h"


typedef struct {
	CurvatureCtrlState C_CtrlState;
	PIDCurvatureCtrl *mPIDCurvatureCtrl;
}CurvatureCtrl;


Curvature mCurvature;

extern void CC_init(CurvatureCtrl *self,PIDCurvatureCtrl *PCC);

extern void CC_setTargCurvature(CurvatureCtrl *self,float parm);
extern float CC_getTargCurvatureCtrl(CurvatureCtrl *self);
extern void CC_setCtrlParm(CurvatureCtrl *self,PIDCurvatureCtrlParm parm);
extern PIDCurvatureCtrlParm CC_getCtrlParm(CurvatureCtrl *self);
extern void CC_startCtrl(CurvatureCtrl *self);
extern void CC_stopCtrl(CurvatureCtrl *self);
extern float CC_doCtrl(CurvatureCtrl *self);
extern float CC_run(CurvatureCtrl *self);
extern void CC_changeMode(CurvatureCtrl *self,CurvatureCtrlState state);

#endif
