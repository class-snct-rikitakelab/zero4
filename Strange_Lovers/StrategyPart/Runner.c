#include "Runner.h"
#include "../Factory.h"


void Runner_init(Runner *self,Section *start_section){
	self->current_section = start_section;
	self->runner_state = STOP;

}
void Runner_run(Runner *self){
	
	if(Section_run(self->current_section)==1){
		Section_reset(self->current_section);
		self->current_section = Section_get_next_section(self->current_section);
	}
}


void Runner_execute(Runner *self){

	switch (self->runner_state){
	case (RUN):
		BrightnessEncoder_cal_normalized_brightness_(&brightnessEncoder);
		DirectionEncoder_calc_speed(&directionEncoder);
		DistanceEncoder_calc_distance(&distanceEncoder);
		SpeedEncoder_calc_speed(&speedEncoder);
		CurvatureEncoder_calc_curvature(&curvatureEncoder);
		//CoordinateEncoder_calc_coordinate(&coordinateEncoder);
		SonarEncoder_mesure_distance_obstacle(&sonorEncoder,Timer_get_ms(&timer));
		Runner_run(self);
			break;
	case (STOP) :
		ecrobot_set_motor_speed(NXT_PORT_A, 0);
		ecrobot_set_motor_speed(NXT_PORT_B, 0);
		ecrobot_set_motor_speed(NXT_PORT_C, 0);
		
		break;
	default :
		break;
	}
}

void Runner_start_run(Runner *self){
	self->runner_state = RUN;
}

void Runner_stop_run(Runner *self){
	self->runner_state = STOP;
}

RunnerState Runner_get_runner_state(Runner *self){
	return self->runner_state;
}