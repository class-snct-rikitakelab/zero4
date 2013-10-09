#ifndef DETECTORPART_INCLINATION_ENCODER_H
#define DETECTORPART_INCLINATION_ENCODER_H

#include "../HardwareWrapper/GyroSensor.h"

typedef struct {
	U8 port_id;
	int gyro_offset;
	int initial_gyro_offset;
}InclinationEncoder;


void InclinationEncoder_init(InclinationEncoder *self,U8 port_id);
int InclinationEncoder_get_inclination(InclinationEncoder *self);
void InclinationEncoder_set_initial_gyro_offset(InclinationEncoder *self,int gyro_offset);
void InclinationEncoder_set_gyro_offset(InclinationEncoder *self,int gyro_offset);

int InclinationEncoder_get_gyro_offset(InclinationEncoder *self);
int InclinationEncoder_get_intilal_gyro_offset(InclinationEncoder *self);

#endif

