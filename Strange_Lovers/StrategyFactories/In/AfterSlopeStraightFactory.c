#include "AfterSlopeStraightFactory.h"


void after_slope_straight_factory_init(){
	
	//RunningMethod

	//afterSlopeStraightRunningMethod
	afterSlopeStraightRunningMethod.balancing_requrement = 1;
	afterSlopeStraightRunningMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	afterSlopeStraightRunningMethod.gyroOffsetRevise = 0;
	
	afterSlopeStraightRunningMethod.switch_term.distance = 345;
	afterSlopeStraightRunningMethod.switch_term.inclination = 0;
	afterSlopeStraightRunningMethod.switch_term.time = 0;
	
	afterSlopeStraightRunningMethod.target_tail_angle=0;
	afterSlopeStraightRunningMethod.use_controller.target_curvature_controller_weight= 0.0;
	afterSlopeStraightRunningMethod.use_controller.target_light_controller_weight = 1.0;
	afterSlopeStraightRunningMethod.movementDirection = FORWARD;

	after_slope_straight_running_method_array[0]=afterSlopeStraightRunningMethod;
	
	afterSlopeStraight.current_running_method_number=0;
	afterSlopeStraight.number_of_running_method=1;
	afterSlopeStraight.running_methods=after_slope_straight_running_method_array;
	
	afterSlopeStraight.target_values.target_brightness=0.5;
	afterSlopeStraight.target_values.target_curvature=0;
	afterSlopeStraight.target_values.target_speed=100;
	
	afterSlopeStraight.nextSection = &firstCurve;

}
