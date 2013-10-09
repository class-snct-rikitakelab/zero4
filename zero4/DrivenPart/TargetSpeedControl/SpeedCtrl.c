#include "SpeedCtrl.h"
#include "../../Factory.h"


//初期化メソッド
void SC_init(SpeedCtrl *self,PIDSpeedCtrl *PSC)
{
	S_init(&mSpeed);
	self->mPIDSpeedCtrl = PSC;
	PSC_init(self->mPIDSpeedCtrl);

	self->S_CtrlState = S_CTRL_OFF;
}

//目標角度設定メソッド
void SC_setTargSpeed(SpeedCtrl *self, int parm)
{
	S_setTargSpeed(&mSpeed,parm);
}

int SC_getTargSpeed(SpeedCtrl *self)
{
	return S_getTargSpeed(&mSpeed);
}

void SC_setCtrlParm(SpeedCtrl *self,PIDSpeedCtrlParm parm)
{
	PSC_setPIDSpeedCtrlParm(self->mPIDSpeedCtrl,parm);
}

PIDSpeedCtrlParm SC_getCtrlParm(SpeedCtrl *self)
{
	return PSC_getPIDSpeedCtrlParm(self->mPIDSpeedCtrl);
}

void SC_startCtrl(SpeedCtrl *self)
{
	SC_changeMode(&(*self),S_CTRL_ON);
}

void SC_stopCtrl(SpeedCtrl *self)
{
	PSC_reset(self->mPIDSpeedCtrl);
	SC_changeMode(&(*self),S_CTRL_OFF);
}

void SC_run(SpeedCtrl *self)
{
	switch(self->S_CtrlState){
	case S_CTRL_ON:
		SC_doCtrl(&(*self));
		break;
	case S_CTRL_OFF:
		break;
	default:
		break;
	}
}

void SC_doCtrl(SpeedCtrl *self)
{
	float speed = S_getSpeed(&mSpeed,systick_get_ms());
	float forward = PSC_calcSpeedCtrlVal(self->mPIDSpeedCtrl,S_getTargSpeed(&mSpeed),S_getBfSpeed(&mSpeed),speed,systick_get_ms()*0.001);
	WheelActuator_set_forward(&wheelActuator ,forward);
}

void SC_changeMode(SpeedCtrl *self,SpeedCtrlState state){
	self->S_CtrlState = state;
}
