#ifndef _CURVATURE_H
#define _CURVATURE_H

#include "../../EncoderPart/CurvatureEncoder.h"


typedef struct{
	float targCurvature;
	float bfDist;
	float bfTheta;
} Curvature;


extern void C_init(Curvature *this_Curvature);
extern float C_getCurvature(Curvature *this_Curvature,int time);
extern float C_getTargCurvature(Curvature *this_Curvature);
extern void C_setTargCurvature(Curvature *this_Curvature,float parm);

#endif
