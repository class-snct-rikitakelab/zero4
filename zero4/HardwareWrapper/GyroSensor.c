#include "GyroSensor.h"

U16 GyroSensor_get_gyro_sensor(U8 port_id)
{
	return (U32)ecrobot_get_gyro_sensor(port_id);
}

