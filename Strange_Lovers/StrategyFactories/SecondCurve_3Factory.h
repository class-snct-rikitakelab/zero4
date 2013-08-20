#ifndef _SecondCurve_3Factory_
#define _SecondCurve_3Factory_

#include "../DrivenPart/DrivenDirector.h"
#include "../DrivenPart/ControllerWeight.h"


#include "../EncoderPart/DistanceEncoder.h"
#include "../EncoderPart/SpeedEncoder.h"
#include "../EncoderPart/Timer.h"
#include "../EncoderPart/InclinationEncoder.h"
#include "../EncoderPart/BrightnessEncoder.h"
#include "../EncoderPart/DirectionEncoder.h"
#include "../EncoderPart/CurvatureEncoder.h"

#include "../StrategyPart/Runner.h"
#include "../StrategyPart/RunningMethod.h"
#include "../StrategyPart/Section.h"
#include "../StrategyPart/SwitchTerm.h"
#include "../StrategyPart/TargetValues.h"
#include "../StrategyPart/SwitchTerm.h"

#include "../StrategyPart/RunningMethodSwitchJudge/SwitchJudge.h"
#include "../StrategyPart/RunningMethodSwitchJudge/DistanceSwitch.h"
#include "../StrategyPart/RunningMethodSwitchJudge/InclinationSwitch.h"
#include "../StrategyPart/RunningMethodSwitchJudge/MultipleTermSwitch.h"

#include "secondCurve_4Factory.h"


//StarategyPart

Section secondCurve_3;
RunningMethod secondCurve_3_LineTraceRunningMethod;

RunningMethod second_curve_3_running_method_array[1];


//StrategyPart/RunningMethodSwitchJudge


extern void second_curve_3_factory_init();

#endif


