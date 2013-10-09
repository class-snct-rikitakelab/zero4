#include "DistanceEncoder.h"
#include "../Factory.h"
#define CIRCUMFERENCE 258


void DistanceEncoder_init(DistanceEncoder *self)
{
	self->distance = 0;
	self->revL_buf=0;
	self->revR_buf=0;

}


float DistanceEncoder_get_distance(DistanceEncoder *self)
{
	return self->distance;
}

float DistanceEncoder_get_total_distance(DistanceEncoder *self)
{
	return self->total_distance;
}

void DistanceEncoder_calc_distance(DistanceEncoder *self)
{
	S16 revL=0,revR=0;
	revL = WheelMotor_get_count(&leftWheelMotor);
	revR = WheelMotor_get_count(&rightWheelMotor);	
	self->distance= CIRCUMFERENCE/360.0 * (((revL - self->revL_buf) + (revR- self->revR_buf)) /2.0);
	self->total_distance =	CIRCUMFERENCE/360.0 * ((revL + revR) /2.0);
}

 void DistanceEncoder_reset_Encoder(DistanceEncoder *self)
{
	self->revL_buf=WheelMotor_get_count(&leftWheelMotor);
	self->revR_buf=WheelMotor_get_count(&rightWheelMotor);
	self->distance = 0;
}

