#include "SeeSaw_3Factory.h"

void seesaw_3_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop;
	MovementDirection movementDirection = FORWARD;
	int (*fp_SwitchJudge)(SwitchTerm);

	//SeesawForwardRunning
	use_controller.target_curvature_controller_weight = 0.3;
	use_controller.target_light_controller_weight = 0.7;
	switch_term.distance =120; //320;
	switch_term.inclination = 600;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time = 0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&SeesawForwardRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//SeesawRunningUp
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 1.0;
	switch_term.distance =60;
	switch_term.inclination = 130;  //100;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time = 0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=25;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&SeesawRunningUpMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//SeesawRunningUp2Running
	use_controller.target_curvature_controller_weight = 0.2;
	use_controller.target_light_controller_weight = 0.8;
	switch_term.distance = 60;
	switch_term.inclination = 600;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time = 450;
	balancing_requrement = 1;
	target_tail_angle=105;
	gyroOffsetRevise=-600;
	request_forced_stop= 0;
	movementDirection = BACKWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&SeesawRunningUp2Method,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);

	seesaw_3_running_method_array[0]=SeesawForwardRunningMethod;
	seesaw_3_running_method_array[1]=SeesawRunningUpMethod;
	seesaw_3_running_method_array[2]=SeesawRunningUp2Method;


	int number_of_running_method=3;
	TargetValues target_values; 
	target_values.target_brightness = 0.3;
	target_values.target_curvature = 0.0001;
	target_values.target_speed = 40;
	Section *nextSection = &seesaw_Upslope;
	RunningMethod *runningMethod = seesaw_3_running_method_array;
	Section_init(&seesaw_3,nextSection,number_of_running_method,runningMethod,target_values);

}
