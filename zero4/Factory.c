#include "Factory.h"
#include "StrategyFactories/Initialize/CommonInitializeInterface.h"

void initialization(){
	
	ecrobot_set_motor_rev(NXT_PORT_A,0);
	ecrobot_set_motor_rev(NXT_PORT_B,0);
	ecrobot_set_motor_rev(NXT_PORT_C,0);
	nxt_motor_set_count(NXT_PORT_A, 0); 
    nxt_motor_set_count(NXT_PORT_B, 0); /* reset left motor count */
    nxt_motor_set_count(NXT_PORT_C, 0); /* reset right motor count */

	Calibration_init(&calibration);
	

	//UI
	PushButton_init(&pushButton,NXT_PORT_S4);
	ParameterReceiver_init(&parameterReceiver,&mLightValCtrl,&mSpeedCtrl,&mCurvatureCtrl);
	Display_init(&display);
	

	//lib
	MovingAverage_init(&speedEncoderMovingAverage,25);
	MovingAverage_init(&curvatureEncoderMovingAverage,25);
	


	//EncoderPart
	Timer_init(&timer);
	DistanceEncoder_init(&distanceEncoder);
	InclinationEncoder_init(&inclinationEncoder,NXT_PORT_S1);
	BrightnessEncoder_init(&brightnessEncoder,NXT_PORT_S3,&lowPassFillter);
	DirectionEncoder_init(&directionEncoder);
	CurvatureEncoder_init(&curvatureEncoder);
	SpeedEncoder_init(&speedEncoder);
	CoordinateEncoder_init(&coordinateEncoder);
	SonarEncoder_init(&sonorEncoder,NXT_PORT_S2);

	//DrivenPart
	PID_TAIL_init(&pid_tail);
	WheelActuator_init(&wheelActuator);
	WheelMotor_init(&rightWheelMotor,NXT_PORT_B);
	WheelMotor_init(&leftWheelMotor,NXT_PORT_C);
	TailMotor_init(&tailMotor,NXT_PORT_A);
	DrivenDirector_init(&drivenDirector);

	//DrivenPart/TargetSpeedControl
	SC_setCtrlParm(&mSpeedCtrl,mPIDSpeedCtrlParm);
	
	PSCP_init(&mPIDSpeedCtrlParm);
	SC_init(&mSpeedCtrl,&mPIDSpeedCtrl);
	SC_startCtrl(&mSpeedCtrl);

	//DrivenPart/TargetCurvatureControl
	PCCP_init(&mPIDCurvatureCtrlParm);
	CC_init(&mCurvatureCtrl,&mPIDCurvatureCtrl);
	CC_setCtrlParm(&mCurvatureCtrl,mPIDCurvatureCtrlParm);
	CC_setTargCurvature(&mCurvatureCtrl,0);
	CC_startCtrl(&mCurvatureCtrl);

	//DrivenPart/TargetLightValueControl
	LVC_init(&mLightValCtrl,&mPIDLightValCtrl);

	strategies_init();
	
	//StrategyPart
	Runner_init(&runner,startSection);

}

void clear_objects(){
	
	ecrobot_set_motor_rev(NXT_PORT_A,0);
	ecrobot_set_motor_rev(NXT_PORT_B,0);
	ecrobot_set_motor_rev(NXT_PORT_C,0);
	nxt_motor_set_count(NXT_PORT_A, 0); 
    nxt_motor_set_count(NXT_PORT_B, 0); // reset left motor count 
    nxt_motor_set_count(NXT_PORT_C, 0); // reset right motor count 

	Calibration_init(&calibration);
	
	//UI
	PushButton_init(&pushButton,NXT_PORT_S4);
	ParameterReceiver_init(&parameterReceiver,&mLightValCtrl,&mSpeedCtrl,&mCurvatureCtrl);
	Display_init(&display);
	

	//lib
	MovingAverage_init(&speedEncoderMovingAverage,25);
	MovingAverage_init(&curvatureEncoderMovingAverage,25);
	


	//EncoderPart
	Timer_reset(&timer);
	DistanceEncoder_reset_Encoder(&distanceEncoder);
	InclinationEncoder_init(&inclinationEncoder,NXT_PORT_S1);
	DirectionEncoder_init(&directionEncoder);
	CurvatureEncoder_init(&curvatureEncoder);
	SpeedEncoder_init(&speedEncoder);
	CoordinateEncoder_reset_Encoder(&coordinateEncoder);
	SonarEncoder_init(&sonorEncoder,NXT_PORT_S2);
	//DrivenPart
	PID_TAIL_init(&pid_tail);
	WheelActuator_init(&wheelActuator);
	WheelMotor_init(&rightWheelMotor,NXT_PORT_B);
	WheelMotor_init(&leftWheelMotor,NXT_PORT_C);
	TailMotor_init(&tailMotor,NXT_PORT_A);
	DrivenDirector_init(&drivenDirector);

	//DrivenPart/TargetSpeedControl
	PSC_reset(mSpeedCtrl.mPIDSpeedCtrl);

	//DrivenPart/TargetCurvatureControl
	PCC_reset(mCurvatureCtrl.mPIDCurvatureCtrl);

	//DrivenPart/TargetLightValueControl
	PLVC_reset(mLightValCtrl.mPIDLightValCtrl);

	strategies_init();
	Runner_init(&runner,startSection);
}


