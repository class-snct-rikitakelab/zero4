#include "SpeedTimerMultipleSwitch.h"
#include "../../Factory.h"

int SpeedTimerMultipleSwitch_judge_switch_method(SwitchTerm switch_term){
	
	int speed =  SpeedEncoder_get_speed(&speedEncoder);
	int time = Timer_get_ms(&timer);
	int judge_flag = 0;


	if(switch_term.speed >= speed && switch_term.time <= time){
		judge_flag = 1;
		Timer_reset(&timer);
	}
	else{
		judge_flag = 0;
	}

	return judge_flag;

}
