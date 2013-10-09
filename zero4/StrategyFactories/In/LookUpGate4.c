#include "LookUpGate4.h"
#include "LookUpGate5.h"

void look_up4_factory_init(){
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
	use_controller.target_light_controller_weight = 0.0;
	use_controller.target_runner_angle_controller_weight = 1.0;
	switch_term.distance =	-260;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	switch_term.distance_obstacle = 0;
	balancing_requrement = 0;
	target_tail_angle=60;
	gyroOffsetRevise=0;
	request_forced_stop =0; 
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&backlookupMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);



	look_up4_running_method_array[0] = backlookupMethod;

	int number_of_running_method=1;
	TargetValues target_values; 
	target_values.target_brightness = 0.67;
	target_values.target_curvature = 0.0;
	target_values.target_speed = -150;
	target_values.target_runner_angle = 0;
	Section *nextSection = &lookup5;
	Section_init(&lookup4,nextSection,number_of_running_method,look_up4_running_method_array,target_values);
}
