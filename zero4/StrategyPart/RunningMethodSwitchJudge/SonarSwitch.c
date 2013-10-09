#include "SonarSwitch.h"
#include "../../Factory.h"

int SonarSwitch_judge_switch_method(SwitchTerm switch_term)
{
	int judge_flag=0;
	int distance_obstacle = SonarEncoder_get_distance_obstacle(&sonorEncoder);
	
	if(switch_term.distance_obstacle >= distance_obstacle){
		judge_flag=1;
	}
	//ecrobot_debug1(switch_term.distance_obstacle,distance_obstacle,switch_term.distance);
	return judge_flag;
}

