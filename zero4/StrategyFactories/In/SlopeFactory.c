#include "SlopeFactory.h"


void slope_factory_init(){
	
	//RunningMethod

	//slopeUpRunningMethod
	slopeUpRunningMethod.balancing_requrement = 1;
	slopeUpRunningMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	slopeUpRunningMethod.gyroOffsetRevise = 0;
	
	slopeUpRunningMethod.switch_term.distance = 573;
	slopeUpRunningMethod.switch_term.inclination = 0;
	slopeUpRunningMethod.switch_term.time = 0;
	
	slopeUpRunningMethod.target_tail_angle=0;
	slopeUpRunningMethod.use_controller.target_curvature_controller_weight= 0.5;
	slopeUpRunningMethod.use_controller.target_light_controller_weight = 0.5;
	slopeUpRunningMethod.movementDirection = FORWARD;

	//slopeDownRunningMethod
	slopeDownRunningMethod.balancing_requrement = 1;
	slopeDownRunningMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	slopeDownRunningMethod.gyroOffsetRevise = 0;
	
	slopeDownRunningMethod.switch_term.distance = 1140;
	slopeDownRunningMethod.switch_term.inclination = 0;
	slopeDownRunningMethod.switch_term.time = 0;
	
	slopeDownRunningMethod.target_tail_angle=0;
	slopeDownRunningMethod.use_controller.target_curvature_controller_weight= 0.5;
	slopeDownRunningMethod.use_controller.target_light_controller_weight = 0.5;
	slopeDownRunningMethod.movementDirection = FORWARD;

	slope_running_method_array[0]=slopeUpRunningMethod;
	slope_running_method_array[1]=slopeDownRunningMethod;
	
	slope.current_running_method_number=0;
	slope.number_of_running_method=2;
	slope.running_methods=slope_running_method_array;

	slope.target_values.target_brightness=0.5;
	slope.target_values.target_curvature=0.0;
	slope.target_values.target_speed=300;
	
	slope.nextSection = &afterSlopeStraight;

}
