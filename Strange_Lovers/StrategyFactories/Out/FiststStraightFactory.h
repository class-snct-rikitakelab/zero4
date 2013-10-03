#ifndef _FirstStraightFactory_
#define _FirstStraightFactory_

#include "../StrategyFactories_inculude.h"


#include "SlopeFactory.h"


//StarategyPart


Section firstStraightSpeedUp;
RunningMethod stableRunningMethod;
RunningMethod speedUpMethod;

RunningMethod first_straight_speedUp_running_method_array[2];


Section firstStraight;
RunningMethod straightLineTraceMethod;

RunningMethod first_straight_running_method_array[1];



extern void first_straight_speedUp_factory_init();
extern void first_straight_factory_init();

#endif


