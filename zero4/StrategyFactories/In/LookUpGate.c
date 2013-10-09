#include "LookUpGate.h"
#include "LookUpGate2.h"

void look_up_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop = 0;
	MovementDirection movementDirection = FORWARD;

	int (*fp_SwitchJudge)(SwitchTerm);


	//beforelookupMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.8;
	switch_term.distance =	0;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	switch_term.distance_obstacle = 55;
	balancing_requrement = 0;
	target_tail_angle=80;
	gyroOffsetRevise=0;
	request_forced_stop =0; 
	movementDirection = FORWARD;
	RunningMethod_init(&beforeLookUpMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,SonarSwitch_judge_switch_method,request_forced_stop,movementDirection);



	look_up_running_method_array[0] = beforeLookUpMethod;

	int number_of_running_method=1;
	TargetValues target_values; 
	target_values.target_brightness = 0.58;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 200;
	Section *nextSection = &lookup2;
	Section_init(&lookup,nextSection,number_of_running_method,look_up_running_method_array,target_values);
}
