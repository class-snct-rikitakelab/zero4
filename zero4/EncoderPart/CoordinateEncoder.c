#include "CoordinateEncoder.h"
#include "../Factory.h"


void CoordinateEncoder_init(CoordinateEncoder *self)
{
	self->xCoo = 0;
	self->yCoo = 0;
	self->distance_buf=0;
}


float CoordinateEncoder_get_xCoo(CoordinateEncoder *self)
{
	return self->xCoo;
}

float CoordinateEncoder_get_yCoo(CoordinateEncoder *self)
{
	return self->yCoo;
}


void CoordinateEncoder_calc_coordinate(CoordinateEncoder *self)
{
	float distance = DistanceEncoder_get_total_distance(&distanceEncoder);
	float theta = DirectionEncoder_get_direction(&directionEncoder);

	self->xCoo += (distance - self->distance_buf) * my_sin(deg2rad(theta));
	self->yCoo += (distance - self->distance_buf) * mycos(deg2rad(theta));
	
	self->distance_buf =distance;

}

 void CoordinateEncoder_reset_Encoder(CoordinateEncoder *self)
{
	self->xCoo=0;
	self->yCoo=0;
	self->distance_buf=0;
 }

