#ifndef _PID_CURVATURE_CONTROL_PARM_H
#define _PID_CURVATURE_CONTROL_PARM_H

typedef struct{
	float cKp;
	float cKi;
	float cKd;
} PIDCurvatureCtrlParm;

extern void PCCP_init(PIDCurvatureCtrlParm *this_PIDCurvatureCtrlParm);
extern float PCCP_getCKp(PIDCurvatureCtrlParm *this_PIDCurvatureCtrlParm);
extern void PCCP_setCKp(PIDCurvatureCtrlParm *this_PIDCurvatureCtrlParm,float parm);
extern float PCCP_getCKi(PIDCurvatureCtrlParm *this_PIDCurvatureCtrlParm);
extern void PCCP_setCKi(PIDCurvatureCtrlParm *this_PIDCurvatureCtrlParm,float parm);
extern float PCCP_getCKd(PIDCurvatureCtrlParm *this_PIDCurvatureCtrlParm);
extern void PCCP_setCKd(PIDCurvatureCtrlParm *this_PIDCurvatureCtrlParm,float parm);

#endif
