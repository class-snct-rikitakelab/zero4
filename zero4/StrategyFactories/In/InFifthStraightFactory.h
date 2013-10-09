#ifndef _InFifthStraightFactory_
#define _InFifthStraightFactory_

#include "../../StrategyFactories/StrategyFactories_inculude.h"
#include "InFifthCurveFactory.h"


Section InFifthStraight;
RunningMethod InFifthStraightLineTraceMethod;

RunningMethod In_fifth_straight_running_method_array[1];

RunningMethod InFifthStraightSlowDownMethod;
RunningMethod In_fifth_straight_slow_down_running_method_array[1];

Section InFifthStraightSlowDown;




extern void In_fifth_straight_factory_init();

#endif


