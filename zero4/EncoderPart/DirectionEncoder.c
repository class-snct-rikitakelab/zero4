
#include "DirectionEncoder.h"
#include "../Factory.h"

#define CYCLE_TIME 0.004
#define TARGTIME 100


void DirectionEncoder_init(DirectionEncoder *self)
{
	self->direction = 0;
	self->revL_buf = 0;
	self->revR_buf = 0;
}

float DirectionEncoder_get_direction(DirectionEncoder *self)
{
	return self->direction;
}

void DirectionEncoder_calc_speed(DirectionEncoder *self)
{
	int revL = WheelMotor_get_count(&leftWheelMotor) - self->revL_buf;

	int revR = WheelMotor_get_count(&rightWheelMotor) - self->revR_buf;	

	self->direction = (float)WHEEL_R /MACHINE_W * (revR - revL);
	
}


void DirectionEncoder_reset(DirectionEncoder *self)
{
	self->revL_buf = WheelMotor_get_count(&leftWheelMotor);
	self->revR_buf = WheelMotor_get_count(&rightWheelMotor);
	self->direction = 0;
}