#include "SonarEncoder.h"

void SonarEncoder_init(SonarEncoder *self,unsigned char port_id)
{
	self->port_id = port_id;
	self->last_mesurement_time=0;
}
int SonarEncoder_get_distance_obstacle(SonarEncoder *self){
	return self->distance_obstacle;
} 

void SonarEncoder_mesure_distance_obstacle(SonarEncoder *self,unsigned int time){
	if((time - self->last_mesurement_time) >= SONOR_MESURE_CYCLE_TIME){
		self->distance_obstacle= SonarSensor_get_sonor_sensor(self->port_id);
		self->last_mesurement_time = time;
	}
}	