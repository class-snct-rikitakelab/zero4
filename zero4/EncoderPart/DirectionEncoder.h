#ifndef __DirectionEncoder
#define __DirectionEncoder


#include "./DistanceEncoder.h"
#include "../DrivenPart/WheelMotor.h"
#include "../NXTSettings.h"



typedef struct{
	float direction;
	int revL_buf;
	int revR_buf;
}DirectionEncoder;


float DirectionEncoder_get_direction(DirectionEncoder *self);
void DirectionEncoder_calc_speed(DirectionEncoder *self);
void DirectionEncoder_init(DirectionEncoder *self);
void DirectionEncoder_reset(DirectionEncoder *self);

#endif 


