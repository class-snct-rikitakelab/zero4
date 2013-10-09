#include "TouchSensor.h"


U8 TouchSensor_getTouchSensor(U8 port_id)
{
	return ecrobot_get_touch_sensor(port_id);
}
