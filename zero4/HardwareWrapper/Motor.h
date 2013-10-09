#ifndef __Motor
#define __Motor
#include "ecrobot_interface.h"


int Motor_get_count(U32 port_id);
void Motor_set_speed(U32 port_id, int pwm, int brake);
void Motor_set_count(U32 port_id,int count);

#endif

