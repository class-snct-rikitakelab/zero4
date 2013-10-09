#include "InclinationSwitch.h"
#include "../../Factory.h"


int InclinationSwitch_judge_switch_method(SwitchTerm switch_term)
{
	int inclination = InclinationEncoder_get_inclination(&inclinationEncoder);
	int initial_gyro_offset = InclinationEncoder_get_intilal_gyro_offset(&inclinationEncoder);
	int deviation = inclination - initial_gyro_offset;

	if( deviation > switch_term.inclination || deviation < -switch_term.inclination){
		return 1;
	}
	else {
	return 0;
	}
}


