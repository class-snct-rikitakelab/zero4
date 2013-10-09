#include "TailAngleSwitch.h"
#include "../../Factory.h"

#define ACCEPT_RANGE 3

int TailAngleSwitch_judge_switch_method(SwitchTerm switch_term)
{
	int tail_angle = TailMotor_get_count(&tailMotor);
	
	if(switch_term.tail_angle - ACCEPT_RANGE <= tail_angle && tail_angle <= ACCEPT_RANGE +3){
		return 1;
	}
	else {
		return 0;
	}
}


