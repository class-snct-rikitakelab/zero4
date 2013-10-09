#include "DirectionDistanceMultipleSwitch.h"
#include "../../Factory.h"

int DirectionDistanceMultipleSwitch_judge_switch_method(SwitchTerm switch_term)
{	
	int judge_flag=0;
	if(DistanceSwitch_judge_switch_method(switch_term) && DirectionSwitch_judge_switch_method(switch_term)){
		judge_flag= 1;
	}
	return judge_flag;
}