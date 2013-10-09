#ifndef _BalanceStope_
#define _BalanceStope_

#include "../../StrategyFactories/StrategyFactories_inculude.h"


//StarategyPart

Section balanceStop;
RunningMethod stopBalanceMethod;
RunningMethod downTailUpMethod;

RunningMethod balanceStop_method_array[2];


//Section firstCurve;


//StrategyPart/RunningMethodSwitchJudge


extern void balance_stop_factory_init();

#endif
