#include "TailMotor.h"



void TailMotor_init(TailMotor *this_TailMotor,U32 port_id){
	this_TailMotor->port_id = port_id;
}

int TailMotor_get_count(TailMotor *this_TailMotor)
{
	return Motor_get_count(this_TailMotor->port_id);
}

void TailMotor_drive_tail(TailMotor *this_TailMotor, int pwm)
{
Motor_set_speed(this_TailMotor->port_id,pwm,1); //3rd paramter means barake mode

}
