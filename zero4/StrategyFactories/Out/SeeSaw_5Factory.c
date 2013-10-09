#include "SeeSaw_5Factory.h"


void seesaw_5_factory_init(){

	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop;
	MovementDirection movementDirection = FORWARD;
	int (*fp_SwitchJudge)(SwitchTerm);
	//SeesawFinalLineTrace

	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 1.0;
	switch_term.distance = 20;
	switch_term.inclination =0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time = 0;
	balancing_requrement = 1;
	target_tail_angle=100;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&SeesawFinalLineTraceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	
	seesaw_5_running_method_array[0]=SeesawFinalLineTraceMethod;

	seesaw_5.current_running_method_number = 0;
	seesaw_5.number_of_running_method = 1;
	seesaw_5.running_methods = seesaw_5_running_method_array;
	seesaw_5.target_values.target_brightness = 0.5;
	seesaw_5.target_values.target_curvature = 0;
	seesaw_5.target_values.target_speed = 50;
	seesaw_5.nextSection = &firstCurve;

	int number_of_running_method=1;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 50;
	Section *nextSection = &firstCurve;
	RunningMethod *runningMethod = seesaw_5_running_method_array;
	Section_init(&seesaw_5,nextSection,number_of_running_method,runningMethod,target_values);
	


}


