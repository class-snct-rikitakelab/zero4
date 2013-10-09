#include "ForthStraightFactory.h"


void forth_straight_factory_init()
{

	//Section Local variables
	TargetValues target_values; 
	Section *nextSection;
	RunningMethod *runningMethod;

	//RunningMethod Local Variables
	ControllerWeight use_controller;
	SwitchTerm switch_term={0,0,0,0,0};
	int number_of_running_method=0;
	int balancing_requrement =1;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop = 0;
	int (*fp_SwitchJudge)(SwitchTerm);
	MovementDirection movementDirection = FORWARD;
	

	//forthStraightLineTraceMethod
	use_controller.target_curvature_controller_weight = 0.5;
	use_controller.target_light_controller_weight = 0.5;
	//switch_term.distance = 1600;
	//switch_term.distance = 1000;
	switch_term.distance = 900;
	
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&forthStraightLineTraceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);

	
	
	//forthStraightLineTraceMethod
	forth_straight_running_method_array[0]=forthStraightLineTraceMethod;
	runningMethod = forth_straight_running_method_array;
	number_of_running_method=1;
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0;
	target_values.target_speed = 400;
	nextSection = &forthCurve_1;

	Section_init(&forthStraight,nextSection,number_of_running_method,runningMethod,target_values);

}
