#ifndef _PID_TAIL_H_
#define _PID_TAIL_H_


#include "./TailMotor.h"
#include "../lib/CommonFunction.h"


typedef struct{
float Kp;
}PID_TAIL;

extern void PID_TAIL_init(PID_TAIL *this_PID_TAIL);
extern void PID_tail(PID_TAIL *self,int target_tail_angle);

#endif

