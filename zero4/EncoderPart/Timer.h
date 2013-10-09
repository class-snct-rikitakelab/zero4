#ifndef __Timer
#define __Timer

#include "../HardwareWrapper/SystemTimer.h"
#include "ecrobot_interface.h"

typedef struct  {
	unsigned int init_time;
}Timer;

void Timer_init(Timer *this_Timer);

unsigned int Timer_get_ms(Timer *this_Timer);

void Timer_reset(Timer *this_Timer);
#endif

