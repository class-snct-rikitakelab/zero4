#include "PIDLightValCtrlParm.h"

void PLVCP_init(PIDLightValCtrlParm *selfParm,float Kp,float Ki,float Kd){

	selfParm->lKp = Kp;
	selfParm->lKi = Ki;
	selfParm->lKd = Kd;
}
float PLVCP_getLKp(PIDLightValCtrlParm *selfParm){
	return selfParm->lKp;
}
void PLVCP_setLKp(PIDLightValCtrlParm *selfParm,float parm){
	selfParm->lKp = parm;
}
float PLVCP_getLKi(PIDLightValCtrlParm *selfParm){
	return selfParm->lKi;
}
void PLVCP_setLKi(PIDLightValCtrlParm *selfParm,float parm){
	selfParm->lKi = parm;
}
float PLVCP_getLKd(PIDLightValCtrlParm *selfParm){
	return selfParm->lKd;
}
void PLVCP_setLKd(PIDLightValCtrlParm *selfParm,float parm){
	selfParm->lKd = parm;
}

