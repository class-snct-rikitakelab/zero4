#include "StartUpWithTailFactory.h"


void start_up_with_tail_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop;
	MovementDirection movementDirection = FORWARD;

	//waitTouchRunningMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance = 0;
	switch_term.inclination = 0;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time =0;
	balancing_requrement = 0;
	target_tail_angle=95;
	gyroOffsetRevise=0;
	request_forced_stop= 1;
	movementDirection = FORWARD;
	RunningMethod_init(&startUpWithTail_waitTouchRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,inPushedSwitch_judge_switch_method,request_forced_stop,movementDirection);
	

	
	start_up_with_tail_running_method_array[0] =startUpWithTail_waitTouchRunningMethod;
	
	int number_of_running_method=1;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 0;
	Section *nextSection = &firstStraight;
	Section_init(&startUpWithTail,nextSection,number_of_running_method,start_up_with_tail_running_method_array,target_values);
}
