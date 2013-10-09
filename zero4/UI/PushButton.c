#include "PushButton.h"


void PushButton_init(PushButton *self, U8 port_id)
{
	self->port_id = port_id;
	self->previous_button_state =0;

}

int PushButton_detect_push_button(PushButton *self)
{
	int button_state = TouchSensor_getTouchSensor(self->port_id);
	int result=0;

	if( button_state == 1 && self->previous_button_state !=1){
		result = 1;
	}
	self->previous_button_state = button_state;
	return result;
}
