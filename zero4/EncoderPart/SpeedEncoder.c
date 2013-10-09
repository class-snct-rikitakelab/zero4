
#include "SpeedEncoder.h"
#include "../Factory.h"

#define CYCLE_TIME 0.004


float SpeedEncoder_validate_speed(SpeedEncoder *self,float speed);

void SpeedEncoder_init(SpeedEncoder *self)
{
	self->speed = 0;
	self->buf_distance =0;
	self->buf_speed = 0;
	self->upper_limit = 1000;
	self->lower_limit = -500;
}

float SpeedEncoder_get_speed(SpeedEncoder *self)
{
	return self->speed;
}

void SpeedEncoder_calc_speed(SpeedEncoder *self)
{
	float distance = DistanceEncoder_get_distance(&distanceEncoder);
	float speed = ((distance - self->buf_distance)/CYCLE_TIME);
	float validated_speed = SpeedEncoder_validate_speed(self,speed);

	self->speed  = MovingAverage_get_averaged_value(&speedEncoderMovingAverage,validated_speed);
	self->buf_distance=distance;
	self->buf_speed = self->speed;
}

float SpeedEncoder_validate_speed(SpeedEncoder *self,float speed)
{
	float validated_speed =0;

	if(speed>self->upper_limit || speed< self->lower_limit){
		validated_speed= self->buf_speed;
	}
	else {
		validated_speed = speed;
	}
	return validated_speed;
}

