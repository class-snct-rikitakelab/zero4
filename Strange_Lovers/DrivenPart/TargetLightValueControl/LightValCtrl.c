#include "LightValCtrl.h"
#include "../../Factory.h"

void LVC_init(LightValCtrl *this_LightValCtrl,LightValEncoder LVE,WheelMotor WM,PIDLightValCtrl PLVC){
	LV_init(&mLightVal,LVE);
	mWheelMotor = WM;
	WM_init(&mWheelMotor);
	mPIDLightValCtrl = PLVC;
	PLVC_init(&mPIDLightValCtrl);
	this_LightValCtrl->LV_CtrlState = LV_CTRL_OFF;
}

void LVC_setTargLightVal(LightValCtrl *this_LightValCtrl,int parm){
	LV_setTargLightVal(&mLightVal,parm);
}

int LVC_getTargLightValCtrl(LightValCtrl *this_LightValCtrl){
	return LV_getTargLightVal(&mLightVal);
}

void LVC_setCtrlParm(LightValCtrl *this_LightValCtrl,PIDLightValCtrlParm parm){
	PLVC_setCtrlParm(&mPIDLightValCtrl,parm);
}

PIDLightValCtrlParm LVC_getCtrlParm(LightValCtrl *this_LightValCtrl){
	return PLVC_getCtrlParm(&mPIDLightValCtrl);
}

void LVC_startCtrl(LightValCtrl *this_LightValCtrl){
	LVC_changeMode(this_LightValCtrl,LV_CTRL_ON);
}

void LVC_stopCtrl(LightValCtrl *this_LightValCtrl){
	ecrobot_sound_tone(900,100,10);
	LVC_changeMode(this_LightValCtrl,LV_CTRL_OFF);
}

int LVC_doCtrl(LightValCtrl *this_LightValCtrl){
	int turn;
	//WM_setTurn(&mWheelMotor,PLVC_calcCtrlVal(&mPIDLightValCtrl,LV_getTargLightVal(&mLightVal),LV_getLightVal(&mLightVal),systick_get_ms()*0.001));
	turn = PLVC_calcCtrlVal(&mPIDLightValCtrl,LV_getTargLightVal(&mLightVal),LV_getLightVal(&mLightVal),systick_get_ms()*0.001);
	return turn;
}

void LVC_run(LightValCtrl *this_LightValCtrl){
	switch(this_LightValCtrl->LV_CtrlState){
	case LV_CTRL_ON:
		LVC_doCtrl(&(*this_LightValCtrl));
		break;
	case LV_CTRL_OFF:
		WM_init(&mWheelMotor);
		break;
	default:
		break;
	}
}

void LVC_changeMode(LightValCtrl *this_LightValCtrl,LightValCtrlState state){
	this_LightValCtrl->LV_CtrlState = state;
}

LightValRange LVC_getLightValRange(LightValCtrl *this_LightValCtrl){
	return LV_getLightValRange(&mLightVal);
}

void LVC_setLightValRange(LightValCtrl *this_LightValCtrl,LightValRange LVR){
	LV_setLightValRange(&mLightVal,LVR);
}

void LVC_setLightValListener(LightValCtrl *this_LightValCtrl,LightValListener LVL){
	LV_setLightValListener(&mLightVal,LVL);
}