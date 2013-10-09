#ifndef _FACTORY_H_
#define _FACTORY_H_


#include "ecrobot_interface.h"

#include "./lib/CommonFunction.h"
#include "./lib/mymath.h"
#include "./lib/LowPassFillter.h"
#include "./lib/MovingAverage.h"


#include "Calibration.h"


#include "./UI/PushButton.h"
#include "./UI/Display.h"
#include "./UI/Starter.h"
#include "./UI/ParameterReceiver.h"



#include "./DrivenPart/WheelMotor.h"
#include "./DrivenPart/TailMotor.h"
#include "./DrivenPart/WheelActuator.h"
#include "./DrivenPart/PID_Tail.h"
#include "./DrivenPart/DrivenDirector.h"
#include "DrivenPart/ControllerWeight.h"

#include "./DrivenPart/TargetSpeedControl/SpeedCtrl.h"
#include "DrivenPart/TargetCurvatureControl/CurvatureCtrl.h"
#include "DrivenPart/TargetCurvatureControl/PIDCurvatureCtrl.h"
#include "DrivenPart/TargetCurvatureControl/Curvature.h"
#include "DrivenPart/TargetCurvatureControl/PIDCurvatureCtrlParm.h"

#include "DrivenPart/TargetDirectionControl/DirectionCtrl.h"


#include "EncoderPart/DistanceEncoder.h"
#include "EncoderPart/SpeedEncoder.h"
#include "EncoderPart/Timer.h"
#include "EncoderPart/InclinationEncoder.h"
#include "EncoderPart/BrightnessEncoder.h"
#include "EncoderPart/DirectionEncoder.h"
#include "EncoderPart/CurvatureEncoder.h"
#include "EncoderPart/CoordinateEncoder.h"
#include "EncoderPart/SonarEncoder.h"

#include "./StrategyPart/Runner.h"
#include "./StrategyPart/RunningMethod.h"
#include "./StrategyPart/Section.h"
#include "./StrategyPart/SwitchTerm.h"
#include "./StrategyPart/TargetValues.h"
#include "./StrategyPart/SwitchTerm.h"

#include "StrategyPart/RunningMethodSwitchJudge/SwitchJudge.h"
#include "StrategyPart/RunningMethodSwitchJudge/DistanceSwitch.h"
#include "StrategyPart/RunningMethodSwitchJudge/InclinationSwitch.h"
#include "StrategyPart/RunningMethodSwitchJudge/MultipleTermSwitch.h"
#include "StrategyPart/RunningMethodSwitchJudge/SpeedTimerMultipleSwitch.h"
#include "StrategyPart/RunningMethodSwitchJudge/TailAngleSwitch.h"
#include "StrategyPart/RunningMethodSwitchJudge/StartSignalRecieveSwitch.h"

#include "StrategyFactories/Initialize/CommonInitializeInterface.h"



Calibration calibration;



//UI package
PushButton pushButton;
Display display;
Starter starter;
ParameterReceiver parameterReceiver;

//lib 
LowPassFillter lowPassFillter;
MovingAverage speedEncoderMovingAverage;
MovingAverage curvatureEncoderMovingAverage;



//EncoderPart
Timer timer;
DistanceEncoder distanceEncoder;
SpeedEncoder speedEncoder;
InclinationEncoder inclinationEncoder;
BrightnessEncoder brightnessEncoder; 
DirectionEncoder directionEncoder;
CurvatureEncoder curvatureEncoder; 
CoordinateEncoder coordinateEncoder;
SonarEncoder sonorEncoder;

//DrivenPart
PID_TAIL pid_tail;
WheelActuator wheelActuator;
WheelMotor rightWheelMotor;
WheelMotor leftWheelMotor;
TailMotor tailMotor;
DrivenDirector drivenDirector;


//DrivenPart/SpeedControl
SpeedCtrl mSpeedCtrl;
PIDSpeedCtrl mPIDSpeedCtrl;
PIDSpeedCtrlParm mPIDSpeedCtrlParm;

//DrivenPart/DirectionCtrl
CurvatureCtrl mCurvatureCtrl; 
PIDCurvatureCtrl mPIDCurvatureCtrl;
PIDCurvatureCtrlParm mPIDCurvatureCtrlParm;

//DrivenPart/LightValueContrl
LightValListener mLightValListener;
LightValRange mLightValRange;
PIDLightValCtrlParm mPIDLightValCtrlParm;
PIDLightValCtrl mPIDLightValCtrl;
LightVal mLightVal;
LightValCtrl mLightValCtrl;

//DrivenPart/DirectionControl
DirectionCtrl directionCtrl;


//StarategyPart
Runner runner;

Section *startSection; 


//StrategyPart/RunningMethodSwitchJudge


extern void initialization();
extern void clear_objects();


#endif


