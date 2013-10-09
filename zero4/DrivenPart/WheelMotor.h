#ifndef __WheelMotor
#define __WheelMotor

#include "../HardwareWrapper/Motor.h"

typedef struct{
	U32 port_id;
}WheelMotor;

void WheelMotor_init(WheelMotor *this_WheelMotor,U32 port_id);
int WheelMotor_get_count(WheelMotor *this_WheelMotor);
void WheelMotor_drive_motor(WheelMotor *this_WheelMotor, int pwm);
void WheelMotor_set_count(WheelMotor *this_WheelMotor, int count);

#endif


