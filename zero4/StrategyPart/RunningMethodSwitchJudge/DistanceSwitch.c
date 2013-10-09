#include "DistanceSwitch.h"
#include "../../Factory.h"

int DistanceSwitch_judge_switch_method(SwitchTerm switch_term)
{
	int judge_flag=0;
	float distance = DistanceEncoder_get_distance(&distanceEncoder);

	if(switch_term.distance >= 0)
	{
		if(distance > switch_term.distance){
				judge_flag=1;
		}
	}else{
		if(distance < switch_term.distance){
				judge_flag=1;
		}
	}
	return judge_flag;
}