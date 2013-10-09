#include "ThurdCurveFactory.h"


void thurd_curve_factory_init()
{
	//Section Local variables
	TargetValues target_values; 
	Section *nextSection;
	RunningMethod *runningMethod;

	//RunningMethod Local Variables
	ControllerWeight use_controller;
	SwitchTerm switch_term={0,0,0,0,0,0};
	int number_of_running_method=0;
	int balancing_requrement =1;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop = 0;
	int (*fp_SwitchJudge)(SwitchTerm);
	MovementDirection movementDirection = FORWARD;


	//thurdCurve_1 RunningMethod
	use_controller.target_curvature_controller_weight = 0.5;
	use_controller.target_light_controller_weight = 0.5;
	switch_term.distance = 187;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&thurdCurve_1LineTraceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);

	
	//thurdCurve_1 Section
	thurdCurve_1_running_method_array[0]=thurdCurve_1LineTraceMethod;
	runningMethod = thurdCurve_1_running_method_array;
	number_of_running_method=1;
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 1.0/1678.0;
	target_values.target_speed = 400;
	nextSection = &thurdCurve_2;

	Section_init(&thurdCurve_1,nextSection,number_of_running_method,runningMethod,target_values);


	//thurdCurve_2 RunningMethod
	use_controller.target_curvature_controller_weight = 0.4;
	use_controller.target_light_controller_weight = 0.6;
	//switch_term.distance = 548.5929;

	switch_term.distance = 648.5929;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&thurdCurve_2LineTraceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);

	
	//thurdCurve_2 Section
	thurdCurve_2_running_method_array[0]=thurdCurve_2LineTraceMethod;
	runningMethod = thurdCurve_2_running_method_array;
	number_of_running_method=1;
	target_values.target_brightness = 0.5;
	//target_values.target_curvature = 1.0/810.0;
	target_values.target_curvature = 1.0/610.0;
	
	target_values.target_speed = 400;
	nextSection = &thurdCurve_3;

	Section_init(&thurdCurve_2,nextSection,number_of_running_method,runningMethod,target_values);


	//thurdCurve_3 RunningMethod
	use_controller.target_curvature_controller_weight = 0.4;
	use_controller.target_light_controller_weight = 0.6;
	switch_term.distance = 1214.5;
	
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&thurdCurve_3LineTraceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);

	
	//thurdCurve_3 Section
	thurdCurve_3_running_method_array[0]=thurdCurve_3LineTraceMethod;
	runningMethod = thurdCurve_3_running_method_array;
	number_of_running_method=1;
	target_values.target_brightness = 0.5;
	//target_values.target_curvature = 1.0/978.1;
	target_values.target_curvature = 1.0/878.1;
	
	target_values.target_speed = 400;
	nextSection = &thurdCurve_4;

	Section_init(&thurdCurve_3,nextSection,number_of_running_method,runningMethod,target_values);


	//thurdCurve_4 RunningMethod
	use_controller.target_curvature_controller_weight = 0.4;
	use_controller.target_light_controller_weight = 0.6;
	switch_term.distance = 247;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&thurdCurve_4LineTraceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);

	
	//thurdCurve_4 Section
	thurdCurve_4_running_method_array[0]=thurdCurve_4LineTraceMethod;
	runningMethod = thurdCurve_4_running_method_array;
	number_of_running_method=1;
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 1.0/1214.0;
	
	target_values.target_speed = 400;
	nextSection = &thurdCurve_5;

	Section_init(&thurdCurve_4,nextSection,number_of_running_method,runningMethod,target_values);


		//thurdCurve_5 RunningMethod
	use_controller.target_curvature_controller_weight = 0.4;
	use_controller.target_light_controller_weight = 0.6;
	switch_term.distance = 400;
	
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&thurdCurve_5LineTraceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);

	
	//thurdCurve_5 Section
	thurdCurve_5_running_method_array[0]=thurdCurve_5LineTraceMethod;
	runningMethod = thurdCurve_5_running_method_array;
	number_of_running_method=1;
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 1.0/1000.0;
	target_values.target_speed = 400;
	nextSection = &forthStraight;

	Section_init(&thurdCurve_5,nextSection,number_of_running_method,runningMethod,target_values);

}
