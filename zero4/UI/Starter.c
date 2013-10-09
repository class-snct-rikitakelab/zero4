#include "Starter.h"
#include "../Factory.h"


void Starter_init(Starter *self)
{
	self->starter_state = ON_CONTEST;
}

void Starter_accept_start_run(Starter *self)
{
	if(PushButton_detect_push_button(&pushButton) == TRUE){
		ecrobot_sound_tone(880, 512, 30);
		systick_wait_ms(500);
		self->starter_state = ON_CONTEST;
		clear_objects();
		Runner_start_run(&runner);
	}
}

void Starter_accept_stop_run(Starter *self)
{
	if(PushButton_detect_push_button(&pushButton) == TRUE){
		ecrobot_sound_tone(880, 512, 30);
		systick_wait_ms(500);
		Runner_stop_run(&runner);
	}
}

void Starter_accept_paramter_adujust_start(Starter *self){
	if(PushButton_detect_push_button(&pushButton) == TRUE){
		systick_wait_ms(500);
		self->starter_state = PARAMETER_ADJUST;
	}
}


void Starter_user_command_accept(Starter *self){

	switch (self->starter_state){

		case ON_CONTEST :
				if(Runner_get_runner_state(&runner)==RUN){
					Starter_accept_stop_run(&starter);
				}
				else if(Runner_get_runner_state(&runner)==STOP){
					Starter_accept_paramter_adujust_start(self);
				}
			break;
		case PARAMETER_ADJUST :
				Starter_accept_start_run(&starter);
				ParamterReceiver_parameter_adjust(&parameterReceiver);
			break;

	}

}

