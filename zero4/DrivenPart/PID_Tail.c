#include "PID_Tail.h"
#include "../Factory.c"
	
void PID_TAIL_init(PID_TAIL *self){
	self->Kp = 4.8;//2.4;
}


void PID_tail(PID_TAIL *self,int target_tail_angle){


	float hensa = target_tail_angle - TailMotor_get_count(&tailMotor);
	float angle = self->Kp*hensa;

	angle = cutoff(angle,100);
	TailMotor_drive_tail(&tailMotor,angle);
}

