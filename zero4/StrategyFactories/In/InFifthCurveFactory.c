#include "InFifthCurveFactory.h"


void In_sixth_curve_factory_init(){
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
	

	//InFifthCurve_1_LineTraceRunningMethod
	use_controller.target_curvature_controller_weight = 0.3;
	use_controller.target_light_controller_weight = 0.7;
	//switch_term.distance = 463;
	switch_term.distance = 563;
	
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&InFifth_Curve_1_LineTraceRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//InFifthCurve_1 Section
	InFifth_curve_1_running_method_array[0]=InFifth_Curve_1_LineTraceRunningMethod;
	number_of_running_method=1;
	target_values.target_brightness = 0.3;
	//target_values.target_curvature = -1/262.979;
	target_values.target_curvature = -1/180.0;
	target_values.target_speed = 250;
	nextSection= &InFifthCurve_2;
	Section_init(&InFifthCurve_1,nextSection,number_of_running_method,InFifth_curve_1_running_method_array,target_values);


	//InFIfthCurve_2_LineTraceRunningMethod
	use_controller.target_curvature_controller_weight = 0.3;
	use_controller.target_light_controller_weight = 0.7;
	switch_term.distance = 492;
	
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = DistanceSwitch_judge_switch_method;
	RunningMethod_init(&InFifth_Curve_2_LineTraceRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//InFifthCurve_2 Section
	InFifth_curve_2_running_method_array[0]=InFifth_Curve_2_LineTraceRunningMethod;
	number_of_running_method=1;
	target_values.target_brightness = 0.5;
	//target_values.target_curvature = 1.0/250.0;
	target_values.target_curvature = -1.0/859.61;
	
	target_values.target_speed = 300;
	nextSection = &afterInFifthCurveStraight;
	Section_init(&InFifthCurve_2,nextSection,number_of_running_method,InFifth_curve_2_running_method_array,target_values);


}
