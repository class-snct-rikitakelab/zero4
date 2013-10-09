#include "LightValCtrl.h"
#include "../../Factory.h"



void LVC_init(LightValCtrl *self,PIDLightValCtrl *PLVC){
	LV_init(&mLightVal);
	PLVC_init(PLVC,&mPIDLightValCtrlParm);
	self->mPIDLightValCtrl = PLVC;
	self->LV_CtrlState = LV_CTRL_ON;
	self->turn = 0;
}

void LVC_setTargLightVal(LightValCtrl *self,int parm){
	LV_setTargLightVal(&mLightVal,parm);
}

int LVC_getTargLightValCtrl(LightValCtrl *self){
	return LV_getTargLightVal(&mLightVal);
}

void LVC_setCtrlParm(LightValCtrl *self,PIDLightValCtrlParm *parm){
	PLVC_setCtrlParm(&mPIDLightValCtrl,parm);
}

PIDLightValCtrlParm* LVC_getCtrlParm(LightValCtrl *self){
	return PLVC_getCtrlParm(self->mPIDLightValCtrl);
}

void LVC_startCtrl(LightValCtrl *self){
	LVC_changeMode(self,LV_CTRL_ON);
}

void LVC_stopCtrl(LightValCtrl *self){
	LVC_changeMode(self,LV_CTRL_OFF);
}

void LVC_doCtrl(LightValCtrl *self){
	self->turn = PLVC_calcCtrlVal(&mPIDLightValCtrl,LV_getTargLightVal(&mLightVal),LV_getLightVal(&mLightVal),systick_get_ms()*0.001);
	PIDLightValCtrlParm *parameter = LVC_getCtrlParm(&mLightValCtrl);
}

float LVC_run(LightValCtrl *self){
	switch(self->LV_CtrlState){
	case LV_CTRL_ON:
		LVC_doCtrl(&(*self));
		break;
	case LV_CTRL_OFF:
		break;
	default:
		break;
	}

	return self->turn;
}

void LVC_changeMode(LightValCtrl *self,LightValCtrlState state){
	self->LV_CtrlState = state;
}

LightValRange LVC_getLightValRange(LightValCtrl *self){
	return LV_getLightValRange(&mLightVal);
}

void LVC_setLightValRange(LightValCtrl *self,LightValRange LVR){
	LV_setLightValRange(&mLightVal,LVR);
}

void LVC_setLightValListener(LightValCtrl *self,LightValListener LVL){
	LV_setLightValListener(&mLightVal,LVL);
}