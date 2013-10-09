#ifndef _StartUpFactory_
#define _StartUpFactory_

#include "../../StrategyFactories/StrategyFactories_inculude.h"

#include "FiststStraightFactory.h"


//StarategyPart

Section startUp;
RunningMethod waitTouchRunningMethod;
RunningMethod tailMoveRunningMethod;
RunningMethod tailBackRunningMethod;

RunningMethod start_up_running_method_array[3];


//Section firstCurve;


//StrategyPart/RunningMethodSwitchJudge


extern void start_up__factory_init();

#endif


