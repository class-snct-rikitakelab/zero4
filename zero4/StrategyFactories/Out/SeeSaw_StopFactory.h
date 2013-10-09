#ifndef _SeeSaw_stopFactory_
#define _SeeSaw_stopFactory_

#include "../StrategyFactories_inculude.h"

#include "SeeSaw_2Factory.h"



//StarategyPart

Section seesaw_stop;
RunningMethod SeesawStopMethod;

RunningMethod seesaw_stop_running_method_array[1];


//StrategyPart/RunningMethodSwitchJudge

extern void seesaw_stop_factory_init();

#endif


