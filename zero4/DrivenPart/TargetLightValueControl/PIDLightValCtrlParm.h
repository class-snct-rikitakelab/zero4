#ifndef _PID_LIGHT_VAL_CTRL_PARM_H
#define _PID_LIGHT_VAL_CTRL_PARM_H

typedef struct{
	float lKp;
	float lKi;
	float lKd;
}PIDLightValCtrlParm;

extern void PLVCP_init(PIDLightValCtrlParm *selfParm,float Kp,float Ki,float Kd);
extern float PLVCP_getLKp(PIDLightValCtrlParm *selfParm);
extern void PLVCP_setLKp(PIDLightValCtrlParm *selfParm,float parm);
extern float PLVCP_getLKi(PIDLightValCtrlParm *selfParm);
extern void PLVCP_setLKi(PIDLightValCtrlParm *selfParm,float parm);
extern float PLVCP_getLKd(PIDLightValCtrlParm *selfParm);
extern void PLVCP_setLKd(PIDLightValCtrlParm *selfParm,float parm);

#endif
