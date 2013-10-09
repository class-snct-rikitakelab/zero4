#include "InclinationEncoder.h"
#include "../Factory.h"

void InclinationEncoder_init(InclinationEncoder *self,U8 port_id)
{
	self->port_id = port_id;
}

int InclinationEncoder_get_inclination(InclinationEncoder *self)
{
	return GyroSensor_get_gyro_sensor(self->port_id);
}

int InclinationEncoder_get_gyro_offset(InclinationEncoder *self)
{
	return self->gyro_offset;
}

int InclinationEncoder_get_intilal_gyro_offset(InclinationEncoder *self)
{
	return self->initial_gyro_offset;
}

void InclinationEncoder_set_gyro_offset(InclinationEncoder *self,int gyro_offset){

	self->gyro_offset = gyro_offset;
}

void InclinationEncoder_set_initial_gyro_offset(InclinationEncoder *self,int gyro_offset){

	self->initial_gyro_offset = gyro_offset;
}
