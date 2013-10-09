# Target specific macros
TARGET = Strange_Lovers

NXTOSEK_ROOT = /cygdrive/c/cygwin/nxtOSEK

# nxtway_gs_balancer library desiged for NXTway-GS two wheeled self-balancing robot
USER_INC_PATH= $(NXTOSEK_ROOT)/ecrobot/nxtway_gs_balancer
USER_LIB = nxtway_gs_balancer

# using NXT standard tires (not Motorcycle tires)
#USER_DEF = NXT_STD_TIRE
DRIVENPART_SOURCES := 
# User application source
TARGET_SOURCES := \
	./lib/CommonFunction.c \
	./lib/mymath.c \
	./lib/MovingAverage.c \
	./lib/LowPassFillter.c \
	./lib/MyString.c \
	model_impl.c \
	Factory.c \
	balancer_param.c \
	Calibration.c \
	logSend.c \
	./DrivenPart/PID_Tail.c \
	./HardwareWrapper/TouchSensor.c \
	./HardwareWrapper/Motor.c \
	./HardwareWrapper/SystemTimer.c \
	./HardwareWrapper/GyroSensor.c \
	./HardwareWrapper/LightSensor.c \
	./HardwareWrapper/SonarSensor.c \
	./UI/PushButton.c \
	./UI/Display.c \
	./UI/Starter.c \
	./UI/ParameterReceiver.c \
	./EncoderPart/Timer.c \
	./EncoderPart/DistanceEncoder.c \
	./EncoderPart/SpeedEncoder.c \
	./EncoderPart/InclinationEncoder.c \
	./EncoderPart/BrightnessEncoder.c \
	./EncoderPart/DirectionEncoder.c \
	./EncoderPart/CurvatureEncoder.c \
	./EncoderPart/CoordinateEncoder.c \
	./EncoderPart/SonarEncoder.c \
	./DrivenPart/WheelMotor.c \
	./DrivenPart/TailMotor.c \
	./DrivenPart/WheelActuator.c \
	./DrivenPart/DrivenDirector.c \
	./DrivenPart/TargetSpeedControl/SpeedCtrl.c \
	./DrivenPart/TargetSpeedControl/Speed.c \
	./DrivenPart/TargetSpeedControl/PIDSpeedCtrl.c \
	./DrivenPart/TargetSpeedControl/PIDSpeedCtrlParm.c \
	./DrivenPart/TargetCurvatureControl/CurvatureCtrl.c \
	./DrivenPart/TargetCurvatureControl/PIDCurvatureCtrlParm.c \
	./DrivenPart/TargetCurvatureControl/Curvature.c \
	./DrivenPart/TargetCurvatureControl/PIDCurvatureCtrl.c \
	./DrivenPart/TargetLightValueControl/LightVal.c \
	./DrivenPart/TargetLightValueControl/LightValCtrl.c \
	./DrivenPart/TargetLightValueControl/LightValListener.c \
	./DrivenPart/TargetLightValueControl/LightValRange.c \
	./DrivenPart/TargetLightValueControl/PIDLightValCtrl.c \
	./DrivenPart/TargetLightValueControl/PIDLightValCtrlParm.c \
	./DrivenPart/TargetDirectionControl/DirectionCtrl.c \
	./StrategyPart/Section.c \
	./StrategyPart/RunningMethod.c \
	./StrategyPart/Runner.c \
	./StrategyPart/RunningMethodSwitchJudge/SwitchJudge.c \
	./StrategyPart/RunningMethodSwitchJudge/DistanceSwitch.c \
	./StrategyPart/RunningMethodSwitchJudge/InclinationSwitch.c \
	./StrategyPart/RunningMethodSwitchJudge/TimeSwitch.c \
	./StrategyPart/RunningMethodSwitchJudge/inPushedSwitch.c \
	./StrategyPart/RunningMethodSwitchJudge/MultipleTermSwitch.c \
	./StrategyPart/RunningMethodSwitchJudge/SpeedTimerMultipleSwitch.c \
	./StrategyPart/RunningMethodSwitchJudge/CurvatureSwitch.c \
	./StrategyPart/RunningMethodSwitchJudge/StartSignalRecieveSwitch.c\
	./StrategyPart/RunningMethodSwitchJudge/DirectionSwitch.c \
	./StrategyPart/RunningMethodSwitchJudge/DirectionDistanceMultipleSwitch.c \
	./StrategyPart/RunningMethodSwitchJudge/MarkerSwitch.c \
	./StrategyFactories/Out/StartUpFactory.c \
	./StrategyFactories/Out/StartUpWithTailFactory.c \
	./StrategyFactories/Out/FiststStraightFactory.c \
	./StrategyFactories/Out/SlopeFactory.c \
	./StrategyFactories/Out/AfterSlopeStraightFactory.c \
	./StrategyFactories/Out/FiststCurveFactory.c \
	./StrategyFactories/Out/SecondStraightFactory.c \
	./StrategyFactories/Out/SecondCurveFactory.c \
	./StrategyFactories/Out/ThurdStraightFactory.c \
	./StrategyFactories/Out/ThurdCurveFactory.c \
	./StrategyFactories/Out/ForthStraightFactory.c \
	./StrategyFactories/Out/ForthCurveFactory.c \
	./StrategyFactories/Out/OutFifthStraightFactory.c \
	./StrategyFactories/Out/AfterOutFifthCurveStraight.c \
	./StrategyFactories/Out/OutFifthCurveFactory.c \
	./StrategyFactories/Out/OutSixthCurveFactory.c \
	./StrategyFactories/Out/SeeSaw_1Factory.c \
	./StrategyFactories/Out/SeeSaw_StopFactory.c \
	./StrategyFactories/Out/SeeSaw_2Factory.c \
	./StrategyFactories/Out/SeeSaw_2_2Factory.c \
	./StrategyFactories/Out/SeeSaw_3Factory.c \
	./StrategyFactories/Out/SeeSaw_4Factory.c \
	./StrategyFactories/Out/SeeSaw_5Factory.c \
	./StrategyFactories/Out/SeeSaw_2_3Factory.c \
	./StrategyFactories/Out/SeeSaw_UpslopeFactory.c \
	./StrategyFactories/Initialize/OutInitialize.c \

TOPPERS_OSEK_OIL_SOURCE := ./prog.oil


O_PATH ?= build

BUILD_MODE=ROM_ONLY

include $(NXTOSEK_ROOT)/ecrobot/lejos_osek.tmf


