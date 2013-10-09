#ifndef _SeeSaw_UpslopeFactory_
#define _SeeSaw_UpslopeFactory_

#include "../StrategyFactories_inculude.h"

#include "SeeSaw_4Factory.h"


//StarategyPart

Section seesaw_Upslope;
RunningMethod SeesawAfterUpRunningMethod;
RunningMethod SeesawUpslopeRunningMethod;
RunningMethod SeesawSwitchDownslopeMethod;
RunningMethod SeesawDownslopeRunningMethod;
RunningMethod seesaw_Upslope_running_method_array[4];


//StrategyPart/RunningMethodSwitchJudge

extern void seesaw_Upslope_factory_init();

#endif

