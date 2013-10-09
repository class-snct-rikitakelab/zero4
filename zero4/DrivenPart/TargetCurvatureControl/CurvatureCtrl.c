#include "CurvatureCtrl.h"
#include "../../Factory.h"

#define CYCLE_TIME 0.004

void CC_init(CurvatureCtrl *self,PIDCurvatureCtrl *PCC)
{
	self->mPIDCurvatureCtrl = PCC;
	PCC_init(self->mPIDCurvatureCtrl);
	C_init(&mCurvature);
	self->C_CtrlState = C_CTRL_OFF;
}

void CC_setTargCurvature(CurvatureCtrl *self,float parm)
{
	C_setTargCurvature(&mCurvature,parm);
}

float CC_getTargCurvatureCtrl(CurvatureCtrl *self)
{
	return C_getTargCurvature(&mCurvature);
}

void CC_setCtrlParm(CurvatureCtrl *self,PIDCurvatureCtrlParm parm)
{
	PCC_setPIDCurvatureCtrlParm(self->mPIDCurvatureCtrl,parm);
}

PIDCurvatureCtrlParm CC_getCtrlParm(CurvatureCtrl *self)
{
	return PCC_getPIDCurvatureCtrlParm(self->mPIDCurvatureCtrl);
}

void CC_startCtrl(CurvatureCtrl *self)
{
	PCC_reset(self->mPIDCurvatureCtrl);
	CC_changeMode(&(*self),C_CTRL_ON);
	CurvatureEncoder_get_curvature(&curvatureEncoder);
}

void CC_stopCtrl(CurvatureCtrl *self)
{
	PCC_reset(self->mPIDCurvatureCtrl);
	CC_changeMode(&(*self),C_CTRL_OFF);
}

float CC_doCtrl(CurvatureCtrl *self)
{
	float curvature = C_getCurvature(&mCurvature,ecrobot_get_systick_ms());
	float turn = PCC_calcCurvatureCtrlVal(self->mPIDCurvatureCtrl,
		C_getTargCurvature(&mCurvature),curvature,Timer_get_ms(&timer)*0.001);
	return turn;
}

float CC_run(CurvatureCtrl *self)
{
	float turn = 0;
	switch(self->C_CtrlState){
	case C_CTRL_ON:
		turn = CC_doCtrl(&(*self));
		break;
	case C_CTRL_OFF:
		turn = 0;
		break;
	default:
		turn = 0;
		break;
	}

	return turn;
}

void CC_changeMode(CurvatureCtrl *self,CurvatureCtrlState state)
{
	self->C_CtrlState = state;
}

