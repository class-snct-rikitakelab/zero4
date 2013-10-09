#ifndef _GarageIn_
#define _GarageIn_

#include "../../StrategyFactories/StrategyFactories_inculude.h"


//StarategyPart

Section garageIn;
RunningMethod beforeGarageMethod;
RunningMethod grayGarageMethod;

RunningMethod garage_running_method_array[1];


//Section firstCurve;


//StrategyPart/RunningMethodSwitchJudge


extern void garage_factory_init();

#endif


