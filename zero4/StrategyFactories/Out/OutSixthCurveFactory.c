#include "OutSixthCurveFactory.h"


void out_sixth_curve_factory_init(){
	//Section Local variables
	TargetValues target_values; 
	Section *nextSection;

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
	

	//outSixthCurve_1_LineTraceRunningMethod
	use_controller.target_curvature_controller_weight = 0.4;
	use_controller.target_light_controller_weight = 0.6;
	switch_term.distance = 691.1504;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&outSixthCurve_1_LineTraceRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//outSixthCurve_1 Section
	sixth_curve_1_running_method_array[0]=outSixthCurve_1_LineTraceRunningMethod;
	number_of_running_method=1;
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 1.0/250.0;	
	target_values.target_speed = 300;
	nextSection= &outSixthCurve_2;
	Section_init(&outSixthCurve_1,nextSection,number_of_running_method,sixth_curve_1_running_method_array,target_values);


	//outSixthCurve_2_LineTraceRunningMethod
	use_controller.target_curvature_controller_weight = 0.5;
	use_controller.target_light_controller_weight = 0.5;
	switch_term.distance = 1200.0619;

	
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&outSixthCurve_2_LineTraceRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//outSixthCurve_2 Section
	outSixth_curve_2_running_method_array[0]=outSixthCurve_2_LineTraceRunningMethod;
	number_of_running_method=1;
	target_values.target_brightness = 0.5;
	//target_values.target_curvature = 1.0/250.0;
	target_values.target_curvature = 1.0/300.0;
	
	target_values.target_speed = 300;
	nextSection = &seesaw_1;
	Section_init(&outSixthCurve_2,nextSection,number_of_running_method,outSixth_curve_2_running_method_array,target_values);


}
