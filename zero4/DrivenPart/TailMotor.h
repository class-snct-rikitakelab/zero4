#ifndef __TailMotor
#define __TailMotor

#include "../HardwareWrapper/Motor.h"

typedef struct{
	U32 port_id;
}TailMotor;

void TailMotor_init(TailMotor *this_TailMotor,U32 port_id);
int TailMotor_get_count(TailMotor *this_TailMotor);
void TailMotor_drive_tail(TailMotor *this_TailMotor, int pwm);

#endif

