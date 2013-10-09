#ifndef _SeeSaw_2_2Factory_
#define _SeeSaw_2_2Factory_

#include "../StrategyFactories_inculude.h"

#include "SeeSaw_2_3Factory.h"


//StarategyPart

Section seesaw_2_2;

RunningMethod stopMethod;
RunningMethod tailplusmovingMethod;
RunningMethod tailbackMethod;


RunningMethod seesaw_2_2running_method_array[3];


//StrategyPart/RunningMethodSwitchJudge

extern void seesaw_2_2factory_init();

#endif



