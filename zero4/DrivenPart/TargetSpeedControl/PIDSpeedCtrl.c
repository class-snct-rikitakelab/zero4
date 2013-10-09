#include "PIDSpeedCtrl.h"

void PSC_init(PIDSpeedCtrl *self){
	self->integratedDeviation = 0;
	self->bfDeviation = 0;
	self->lastMeasurementTime = 0;
	self->buf_forward=0;

}

float PSC_calcSpeedCtrlVal(PIDSpeedCtrl *self,float targSpeed,float bfSpeed,float speed,float time){
	float forward=0;
	
	float deviation = targSpeed - speed;
	
	self->integratedDeviation = (self->integratedDeviation + 
		(deviation * (time - self->lastMeasurementTime)));


	self->integratedDeviation =  (self->integratedDeviation + 
		(deviation * (time - self->lastMeasurementTime)));


	float differentialDeviation =  ((deviation - 
		self->bfDeviation)/(time - self->lastMeasurementTime));

	forward = (deviation * PSCP_getSKp(&self->mPIDSpeedCtrlParm)
		+ self->integratedDeviation * PSCP_getSKi(&self->mPIDSpeedCtrlParm)
		+ differentialDeviation * PSCP_getSKd(&self->mPIDSpeedCtrlParm));


	self->bfDeviation = deviation;
	self->lastMeasurementTime = time;
	
	forward = forward + self->buf_forward;

	if(forward > 160)
		forward = 160;
	else if(forward < -100)
		forward = -100;
	
	self->buf_forward = forward;
	return forward;
}

PIDSpeedCtrlParm PSC_getPIDSpeedCtrlParm(PIDSpeedCtrl *self){
	return self->mPIDSpeedCtrlParm;
}

void PSC_setPIDSpeedCtrlParm(PIDSpeedCtrl *self,PIDSpeedCtrlParm parm){
	self->mPIDSpeedCtrlParm = parm;
}

void PSC_reset(PIDSpeedCtrl *self){
	self->integratedDeviation = 0;
	self->bfDeviation = 0;
	self->lastMeasurementTime = 0;
	self->buf_forward = 0;
}
