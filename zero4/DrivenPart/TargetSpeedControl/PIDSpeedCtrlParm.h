#ifndef _PID_SPEED_CTRL_PARM_H
#define _PID_SPEED_CTRL_PARM_H

typedef struct{
	float sKp;
	float sKi;
	float sKd;
} PIDSpeedCtrlParm;

extern void PSCP_init(PIDSpeedCtrlParm *this_PIDSpeedCtrlParm);
extern float PSCP_getSKp(PIDSpeedCtrlParm *this_PIDSpeedCtrlParm);
extern void PSCP_setSKp(PIDSpeedCtrlParm *this_PIDSpeedCtrlParm,float parm);
extern float PSCP_getSKi(PIDSpeedCtrlParm *this_PIDSpeedCtrlParm);
extern void PSCP_setSKi(PIDSpeedCtrlParm *this_PIDSpeedCtrlParm,float parm);
extern float PSCP_getSKd(PIDSpeedCtrlParm *this_PIDSpeedCtrlParm);
extern void PSCP_setSKd(PIDSpeedCtrlParm *this_PIDSpeedCtrlParm,float parm);

#endif
