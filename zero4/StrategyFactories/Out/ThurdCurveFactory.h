#ifndef _ThurdCurveFactory_
#define _ThurdCurveFactory_

#include "../StrategyFactories_inculude.h"
#include "ForthStraightFactory.h"


//StarategyPart

Section thurdCurve_1;
RunningMethod thurdCurve_1LineTraceMethod;
RunningMethod thurdCurve_1_running_method_array[2];

Section thurdCurve_2;
RunningMethod thurdCurve_2LineTraceMethod;
RunningMethod thurdCurve_2_running_method_array[2];

Section thurdCurve_2_2;
RunningMethod thurdCurve_2_2LineTraceMethod;
RunningMethod thurdCurve_2_2_running_method_array[2];


Section thurdCurve_3;
RunningMethod thurdCurve_3LineTraceMethod;
RunningMethod thurdCurve_3_running_method_array[2];


Section thurdCurve_4;
RunningMethod thurdCurve_4LineTraceMethod;
RunningMethod thurdCurve_4_running_method_array[2];


Section thurdCurve_5;
RunningMethod thurdCurve_5LineTraceMethod;
RunningMethod thurdCurve_5_running_method_array[2];


extern void thurd_curve_factory_init();

#endif


