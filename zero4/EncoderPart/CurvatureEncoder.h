#ifndef __CurvatureEncoder
#define __CurvatureEncoder


#include "./DistanceEncoder.h"
#include "./DirectionEncoder.h"

typedef struct{
	float curvature;
	float curvature_buf;
	int revR_buf;
	int revL_buf;	
}CurvatureEncoder;


float CurvatureEncoder_get_curvature(CurvatureEncoder *self);
void CurvatureEncoder_calc_curvature(CurvatureEncoder *self);
void CurvatureEncoder_init(CurvatureEncoder *self);

#endif 


