#include "TimeSwitch.h"
#include "../../Factory.h"


int TimeSwitch_judge_switch_method(SwitchTerm switch_term)
{
	unsigned int time = Timer_get_ms(&timer) ;
	int judge_flag=0;

	if(switch_term.time <= time){
		judge_flag = 1;
	}
	else {
		judge_flag = 0;
	}
	return judge_flag;
}
