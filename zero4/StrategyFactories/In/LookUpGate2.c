#include "LookUpGate2.h"
#include "LookUpGate3.h"

void look_up2_factory_init(){
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
	use_controller.target_light_controller_weight = 1.0;
	switch_term.distance =	0;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	switch_term.distance_obstacle = 27;
	balancing_requrement = 0;
	target_tail_angle=80;
	gyroOffsetRevise=0;
	request_forced_stop =0; 
	movementDirection = FORWARD;
	RunningMethod_init(&throughgreyMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,SonarSwitch_judge_switch_method,request_forced_stop,movementDirection);



	look_up2_running_method_array[0] = throughgreyMethod;

	int number_of_running_method=1;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 200;
	Section *nextSection = &lookup3;
	Section_init(&lookup2,nextSection,number_of_running_method,look_up2_running_method_array,target_values);
}
