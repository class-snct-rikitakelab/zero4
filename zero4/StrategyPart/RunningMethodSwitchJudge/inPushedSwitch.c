#include "inPushedSwitch.h"
#include "../../Factory.h"


int inPushedSwitch_judge_switch_method(SwitchTerm switch_term)
{			
	int start_flag = 0;
	if(PushButton_detect_push_button(&pushButton) == TRUE){
		start_flag = 1;

	}
	
		return start_flag;
}

