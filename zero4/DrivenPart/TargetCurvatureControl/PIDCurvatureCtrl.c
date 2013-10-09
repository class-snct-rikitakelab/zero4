#include "PIDCurvatureCtrl.h"

extern void PCC_init(PIDCurvatureCtrl *self)
{
	self->integratedDeviation = 0;
	self->bfDeviation = 0;
	self->lastMeasurementTime = 0;
	self->turn_buf=0;
}

extern float PCC_calcCurvatureCtrlVal(PIDCurvatureCtrl *self,float targCurvature,float curvature,float time)
{
	float turn;
	
	float deviation =   self->movementDirection*(targCurvature - curvature);

	self->integratedDeviation = (float) (self->integratedDeviation + 
		(deviation * (time - self->lastMeasurementTime)));

	float differentialDeviation = (float) ((deviation - 
		self->bfDeviation)/(time - self->lastMeasurementTime));

	turn = (deviation * PCCP_getCKp(&self->mPIDCurvatureCtrlParm)
		+ self->integratedDeviation * PCCP_getCKi(&self->mPIDCurvatureCtrlParm)
		+ differentialDeviation * PCCP_getCKd(&self->mPIDCurvatureCtrlParm));
	
	turn = turn + self->turn_buf;
	
	if(turn > 100)
		turn = 100;
	else if(turn < -100)
		turn = -100;

	self->bfDeviation = deviation;
	self->lastMeasurementTime = time;
	self->turn_buf = turn;

	return turn;
}

PIDCurvatureCtrlParm PCC_getPIDCurvatureCtrlParm(PIDCurvatureCtrl *self)
{
	return self->mPIDCurvatureCtrlParm;
}

void PCC_setPIDCurvatureCtrlParm(PIDCurvatureCtrl *self,PIDCurvatureCtrlParm parm)
{
	self->mPIDCurvatureCtrlParm = parm;
}

void PCC_reset(PIDCurvatureCtrl *self)
{
	self->integratedDeviation = 0;
	self->bfDeviation = 0;
	self->lastMeasurementTime = 0;
	self->turn_buf=0;
}

void PCC_setMovementDirection(PIDCurvatureCtrl *self,MovementDirection movementDirection)
{
	self->movementDirection = movementDirection;
}
