#ifndef _OutFifthStraightFactory_
#define _OutFifthStraightFactory_

#include "../StrategyFactories_inculude.h"
#include "OutFifthCurveFactory.h"


Section outFifthStraight;
RunningMethod outFifthStraightLineTraceMethod;

RunningMethod out_fifth_straight_running_method_array[1];

RunningMethod outFifthStraightSlowDownMethod;
RunningMethod out_fifth_straight_slow_down_running_method_array[1];

Section outFifthStraightSlowDown;




extern void out_fifth_straight_factory_init();

#endif


