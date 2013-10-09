#include "SonarSensor.h"

int SonarSensor_get_sonor_sensor(unsigned char port_id)
{
	return (int)ecrobot_get_sonar_sensor((U8)port_id);
}