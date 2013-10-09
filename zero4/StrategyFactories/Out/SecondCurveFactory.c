#include "SecondCurveFactory.h"


void second_curve_factory_init(){
	//Section Local variables
	TargetValues target_values; 
	Section *nextSection;

	//RunningMethod Local Variables
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int number_of_running_method=0;
	int balancing_requrement =1;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop = 0;
	int (*fp_SwitchJudge)(SwitchTerm);
	MovementDirection movementDirection = FORWARD;
	
	//secondCurve_1_LineTraceRunningMethod
	use_controller.target_curvature_controller_weight = 0.4;
	use_controller.target_light_controller_weight = 0.6;
	switch_term.distance = 1141.592;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&secondCurve_1_LineTraceRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//secondCurve_1 Section
	second_curve_1_running_method_array[0]=secondCurve_1_LineTraceRunningMethod;
	number_of_running_method=1;
	target_values.target_brightness = 0.3;
	//target_values.target_curvature = -1.0/726.76;
	target_values.target_curvature = -1.0/626.76;
	target_values.target_speed = 400;
	nextSection= &secondCurve_2;
	Section_init(&secondCurve_1,nextSection,number_of_running_method,second_curve_1_running_method_array,target_values);


	//secondCurve_2_LineTraceRunningMethod
	
	use_controller.target_curvature_controller_weight = 0.4;
	use_controller.target_light_controller_weight = 0.6;
	switch_term.distance = 643;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&secondCurve_2_LineTraceRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//secondCurve_2 Section
	second_curve_2_running_method_array[0]=secondCurve_2_LineTraceRunningMethod;
	number_of_running_method=1;
	target_values.target_brightness = 0.3;
	//target_values.target_curvature = -1.0/570.18;
	//target_values.target_curvature = -1.0/470.18;
	target_values.target_curvature = -1.0/400.18;
	target_values.target_speed = 400;
	nextSection = &secondCurve_3;
	Section_init(&secondCurve_2,nextSection,number_of_running_method,second_curve_2_running_method_array,target_values);


	//secondCurve_3_LineTraceRunningMethod
	use_controller.target_curvature_controller_weight = 0.4;
	use_controller.target_light_controller_weight = 0.6;
	//switch_term.distance = 561.34;
	switch_term.distance = 600.34;

	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop =0 ;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;	
	RunningMethod_init(&secondCurve_3_LineTraceRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//secondCurve_3 Section
	second_curve_3_running_method_array[0]=secondCurve_3_LineTraceRunningMethod;
	number_of_running_method=1;
	target_values.target_brightness = 0.3;
	target_values.target_curvature = -1.0/527;
	target_values.target_curvature = -1.0/467;

	target_values.target_speed = 400;
	nextSection = &thurdStraight;
	Section_init(&secondCurve_3,nextSection,number_of_running_method,second_curve_3_running_method_array,target_values);
}
