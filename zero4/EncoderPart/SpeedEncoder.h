#ifndef __SpeedEncoder
#define __SpeedEncoder


#include "./DistanceEncoder.h"
#include "./Timer.h"
#include "../lib/MovingAverage.h"


typedef struct{
	float speed;
	float buf_distance;
	float buf_speed;
	float lower_limit;
	float upper_limit;
}SpeedEncoder;


float SpeedEncoder_get_speed(SpeedEncoder *self);
void SpeedEncoder_calc_speed(SpeedEncoder *self);
void SpeedEncoder_init(SpeedEncoder *self);

#endif 


