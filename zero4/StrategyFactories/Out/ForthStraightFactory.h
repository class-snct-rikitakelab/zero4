#ifndef _ForthStraightFactory_
#define _ForthStraightFactory_

#include "../StrategyFactories_inculude.h"
#include "ForthCurveFactory.h"



Section forthStraight;
RunningMethod forthStraightLineTraceMethod;

RunningMethod forth_straight_running_method_array[1];


extern void forth_straight_factory_init();

#endif


