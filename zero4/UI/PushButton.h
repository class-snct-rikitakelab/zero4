#ifndef _PushButton_
#define _PushButton_

#include "../HardwareWrapper/TouchSensor.h"


typedef struct{
	U8 port_id;
	int previous_button_state;
}PushButton;


void PushButton_init(PushButton *self, U8 port_id);

int PushButton_detect_push_button(PushButton *self);

#endif

