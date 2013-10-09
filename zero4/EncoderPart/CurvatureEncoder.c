
#include "CurvatureEncoder.h"
#include "DirectionEncoder.h"
#include "../lib/MovingAverage.h"
#include "../Factory.h"

#define CYCLE_TIME 0.004


void CurvatureEncoder_init(CurvatureEncoder *self)
{
	self->curvature = 0;
	self->curvature_buf = 0;
	self->revL_buf = 0;
	self->revR_buf = 0;
}

float CurvatureEncoder_get_curvature(CurvatureEncoder *self)
{
	return self->curvature;
}

void CurvatureEncoder_calc_curvature(CurvatureEncoder *self)
{
	float curvature=0;
	float averaged_curvature=0;
	
	int revL = 41*WheelMotor_get_count(&leftWheelMotor);
	int revR = 41*WheelMotor_get_count(&rightWheelMotor);	
	
	float diff_revL = (revL - self->revL_buf)/CYCLE_TIME;
	float diff_revR = (revR - self->revR_buf)/CYCLE_TIME;

	if(diff_revL + diff_revR!=0){
	curvature = (float)((diff_revL - diff_revR) /( (diff_revL + diff_revR)*(MACHINE_W/2)));
	}
	else {
		curvature = self->curvature_buf;
	}
	self->revL_buf = revL;
	self->revR_buf = revR;

	averaged_curvature  = MovingAverage_get_averaged_value(&curvatureEncoderMovingAverage,curvature);
	
	self->curvature_buf= curvature;
	self->curvature =averaged_curvature;
}

