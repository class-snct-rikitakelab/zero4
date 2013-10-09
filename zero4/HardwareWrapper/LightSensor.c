#include "LightSensor.h"

U16 LightSensor_get_light_sensor(U8 port_id)
{
	return ecrobot_get_light_sensor(port_id);
}
