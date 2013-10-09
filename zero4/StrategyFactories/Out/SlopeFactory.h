#ifndef _SlopeFactory_
#define _SlopeFactory_


#include "AfterSlopeStraightFactory.h"


//StarategyPart

Section slope;
RunningMethod slopeUpRunningMethod;
RunningMethod slopeDownRunningMethod;

RunningMethod slope_running_method_array[2];


//Section firstCurve;


//StrategyPart/RunningMethodSwitchJudge


extern void slope_factory_init();

#endif


