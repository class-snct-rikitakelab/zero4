#include "SecondCurve_3Factory.h"


void second_curve_3_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =1;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;


	//secondCurve_1_LineTraceRunningMethod
	use_controller.target_curvature_controller_weight = 0.5;
	use_controller.target_light_controller_weight = 0.5;
	switch_term.distance = 480;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	RunningMethod_init(&secondCurve_3_LineTraceRunningMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,DistanceSwitch_judge_switch_method);
	


	second_curve_3_running_method_array[0]=secondCurve_3_LineTraceRunningMethod;
	int number_of_running_method=1;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = -1.0/600.0;
	target_values.target_speed = 400;
	Section *nextSection = &secondCurve_3;
	Section_init(&secondCurve_3,nextSection,number_of_running_method,second_curve_3_running_method_array,target_values);

}
