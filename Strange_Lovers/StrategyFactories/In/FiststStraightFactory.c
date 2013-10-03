#include "FiststStraightFactory.h"

void first_straight_speedUp_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop=0;
	MovementDirection movementDirection = FORWARD;
	
	//stableRunningMethod
	use_controller.target_curvature_controller_weight = 0.1;
	use_controller.target_light_controller_weight = 0.1;
	switch_term.distance =	20;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop =0; 
	movementDirection = FORWARD;
	RunningMethod_init(&stableRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,DistanceSwitch_judge_switch_method,request_forced_stop,movementDirection);
	

	//straightLineTraceMethod
	use_controller.target_curvature_controller_weight = 0.5;
	use_controller.target_light_controller_weight = 0.5;
	switch_term.distance =600;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	RunningMethod_init(&speedUpMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,DistanceSwitch_judge_switch_method,request_forced_stop,movementDirection);
	


	first_straight_speedUp_running_method_array[0]=stableRunningMethod;
	first_straight_speedUp_running_method_array[1]=speedUpMethod;
	int number_of_running_method=2;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 800;
	Section *nextSection = &firstStraight;
	Section_init(&firstStraightSpeedUp,nextSection,number_of_running_method,first_straight_speedUp_running_method_array,target_values);
}



void first_straight_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop=0;
	MovementDirection movementDirection = FORWARD;
	
	//straightLineTraceMethod
	use_controller.target_curvature_controller_weight = 0.5;
	use_controller.target_light_controller_weight = 0.5;
	switch_term.distance =1180;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	RunningMethod_init(&straightLineTraceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,DistanceSwitch_judge_switch_method,request_forced_stop,movementDirection);
	

	first_straight_running_method_array[0]=straightLineTraceMethod;
	int number_of_running_method=1;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 400;
	Section *nextSection = &slope;
	Section_init(&firstStraight,nextSection,number_of_running_method,first_straight_running_method_array,target_values);
}