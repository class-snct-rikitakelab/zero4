#include "CurvatureSwitch.h"
#include "../../Factory.h"

int CurvatureSwitch_judge_switch_method(SwitchTerm switch_term)
{
	int judge_flag=0;
	float curvature = CurvatureEncoder_get_curvature(&curvatureEncoder);
	
	if(switch_term.curvature>=0){
		if( curvature > switch_term.curvature){
			judge_flag = 1;
		}
	}
	else {
		if( curvature < switch_term.curvature){
			judge_flag = 1;
		}
	}
	return judge_flag;
}