#include "MarkerSwitch.h"
#include "../../Factory.h"


int count=0;
int sum=0;
int sum_av=0;

int MarkerSwitch_judge_switch_method(SwitchTerm switch_term)
{	
	int judge_flag=0;

	//DirectionEncoder_get_direction(&directionEncoder); //Œü‚«‚ÌŒv‘ª
	//BrightnessEncoder_get_brightness(&brightnessEncoder);//‹P“x‚ÌŒv‘ª

	if(count == 100){
		sum_av= sum/100;
		count=0;
		if(sum_av < switch_term.bright){
			judge_flag = 1;
		}
	}else{
		sum+=BrightnessEncoder_get_brightness_normalize(&brightnessEncoder)*1000;
		count++;
	}

	ecrobot_debug1(switch_term.bright,sum_av,BrightnessEncoder_get_brightness_normalize(&brightnessEncoder)*1000);



	return judge_flag;
}