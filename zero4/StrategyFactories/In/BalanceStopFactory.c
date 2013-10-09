#include "BalanceStopFactory.h"
#include "LookUpGate.h"


void balance_stop_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop=0;
	MovementDirection movementDirection = FORWARD;
	
	int (*fp_SwitchJudge)(SwitchTerm);
	//First Straight 1010mm

	//stableRunningMethod
	use_controller.target_curvature_controller_weight = 0;
	use_controller.target_light_controller_weight = 0.1;
	//switch_term.distance =	20;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =2500;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop =0; 
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	movementDirection = FORWARD;
	RunningMethod_init(&stopBalanceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//straightLineTraceMethod
	use_controller.target_curvature_controller_weight = 0;
	use_controller.target_light_controller_weight = 0.1;
	switch_term.distance =0;		//98;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =150;
	balancing_requrement = 1;
	target_tail_angle=90;
	gyroOffsetRevise=-50;
	request_forced_stop = 0;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	movementDirection = FORWARD;
	RunningMethod_init(&downTailUpMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	


	balanceStop_method_array[0]=stopBalanceMethod;
	balanceStop_method_array[1]=downTailUpMethod;
	int number_of_running_method=2;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 0;
	Section *nextSection =&lookup;		// &slope;
	Section_init(&balanceStop,nextSection,number_of_running_method,balanceStop_method_array,target_values);
}
