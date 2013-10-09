#include "WheelMotor.h"


void WheelMotor_init(WheelMotor *this_WheelMotor,U32 port_id){
	this_WheelMotor->port_id = port_id;
}

int WheelMotor_get_count(WheelMotor *this_WheelMotor)
{
	return Motor_get_count(this_WheelMotor->port_id);
}

void WheelMotor_drive_motor(WheelMotor *this_WheelMotor, int pwm)
{
Motor_set_speed(this_WheelMotor->port_id,pwm,1); //3rd paramter means barake mode

}

void WheelMotor_set_count(WheelMotor *this_WheelMotor, int count)
{
	Motor_set_count(this_WheelMotor->port_id,count);
}



