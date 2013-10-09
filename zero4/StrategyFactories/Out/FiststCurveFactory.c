#include "FiststCurveFactory.h"
#include "FiststStraightFactory.h"


void first_curve_factory_init(){
	
	//RunningMethod
	
	//curveLineTraceMethod
	curveLineTraceMethod.balancing_requrement = 1;
	curveLineTraceMethod.fp_SwitchJudge= DirectionDistanceMultipleSwitch_judge_switch_method;
	//curveLineTraceMethod.fp_SwitchJudge= DistanceSwitch_judge_switch_method;
	
	curveLineTraceMethod.gyroOffsetRevise = 0;

	curveLineTraceMethod.switch_term.distance = 1600.60;
	//curveLineTraceMethod.switch_term.distance = 1300.60;
	curveLineTraceMethod.switch_term.direction = 90;

	curveLineTraceMethod.switch_term.inclination = 0;
	curveLineTraceMethod.switch_term.time = 0;
	curveLineTraceMethod.movementDirection =FORWARD;

	curveLineTraceMethod.target_tail_angle=0;
	curveLineTraceMethod.use_controller.target_curvature_controller_weight=0.5;
	curveLineTraceMethod.use_controller.target_light_controller_weight = 0.5;

	first_curve_running_method_array[0]=curveLineTraceMethod;

	firstCurve.current_running_method_number=0;
	firstCurve.number_of_running_method=1;
	firstCurve.running_methods=first_curve_running_method_array;
	firstCurve.target_values.target_curvature=-1.0/1050.17;
	firstCurve.target_values.target_curvature=-1.0/1000.17;
	
	firstCurve.target_values.target_brightness=0.4;
	firstCurve.target_values.target_speed=400;
	firstCurve.nextSection = &secondStraight;

}
