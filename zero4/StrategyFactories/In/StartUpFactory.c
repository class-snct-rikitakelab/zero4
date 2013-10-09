#include "StartUpFactory.h"


void start_up__factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop = 0;
	MovementDirection movementDirection = FORWARD;

	int (*fp_SwitchJudge)(SwitchTerm);

	//waitTouchRunningMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.startSignelRecieve = 1;
	switch_term.distance = 0;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	balancing_requrement = 0;
	target_tail_angle=100;
	gyroOffsetRevise=0;
	request_forced_stop = 1;
	movementDirection = FORWARD;
	fp_SwitchJudge =StartSignalRecieveSwitch_judge_switch_method;
	RunningMethod_init(&waitTouchRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//tailMoveRunningMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance =0 ;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =250;
	//switch_term.tail_angle=130;		//119;
	balancing_requrement = 0;
	target_tail_angle=113;

	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&tailMoveRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//tailBackRunningMethod

	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance =0 ;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time = 200;
	//switch_term.tail_angle=0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;		
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&tailBackRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	


	start_up_running_method_array[0] =waitTouchRunningMethod;
	start_up_running_method_array[1]=tailMoveRunningMethod;
	start_up_running_method_array[2] =tailBackRunningMethod;

	int number_of_running_method=3;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 300;
	Section *nextSection = &firstStraightSpeedUp;
	Section_init(&startUp,nextSection,number_of_running_method,start_up_running_method_array,target_values);
}
