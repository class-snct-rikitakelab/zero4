
#ifndef __DistanceEncoder
#define __DistanceEncoder

#include "../DrivenPart/WheelMotor.h"

typedef struct{
	float distance;
	float total_distance;
	int revL_buf;
	int revR_buf;
}DistanceEncoder;


void DistanceEncoder_init(DistanceEncoder *self);
void DistanceEncoder_calc_distance(DistanceEncoder *self);
float DistanceEncoder_get_distance(DistanceEncoder *self);
float DistanceEncoder_get_total_distance(DistanceEncoder *self);
void DistanceEncoder_reset_Encoder(DistanceEncoder *self);

#endif

