#ifndef DETECTORPART_SONOR_ENCODER_H
#define DETECTORPART_SONOR_ENCODER_H

#define SONOR_MESURE_CYCLE_TIME 50

#include "../HardwareWrapper/SonarSensor.h"


typedef struct {
	unsigned char port_id;
	int distance_obstacle;
	unsigned int last_mesurement_time;
}SonarEncoder;


void SonarEncoder_init(SonarEncoder *self,unsigned char port_id);
int SonarEncoder_get_distance_obstacle(SonarEncoder *self);
void SonarEncoder_mesure_distance_obstacle(SonarEncoder *self,unsigned int time);


#endif

