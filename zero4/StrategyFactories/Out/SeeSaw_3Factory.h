#ifndef _SeeSaw_3Factory_
#define _SeeSaw_3Factory_

#include "../StrategyFactories_inculude.h"

#include "SeeSaw_UpslopeFactory.h"


//StarategyPart

Section seesaw_3;
RunningMethod SeesawForwardRunningMethod;
RunningMethod SeesawRunningUpMethod;
RunningMethod SeesawRunningUp2Method;
RunningMethod seesaw_3_running_method_array[3];


//StrategyPart/RunningMethodSwitchJudge

extern void seesaw_3_factory_init();

#endif

