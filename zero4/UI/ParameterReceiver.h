#ifndef __ParameterReciver
#define __ParameterReciver

#include "../DrivenPart/TargetLightValueControl/LightValCtrl.h"
#include "../DrivenPart/TargetSpeedControl/SpeedCtrl.h"
#include "../DrivenPart/TargetCurvatureControl/CurvatureCtrl.h"
#include "./Display.h"

typedef enum {
	KP,
	KI,
	KD,
}ADJUSTING_PARAMETER;

typedef struct {
	LightValCtrl *lightValCtrl;
	SpeedCtrl *speedCtrl;
	CurvatureCtrl *curvatureCtrl;
	ADJUSTING_PARAMETER adjusing_paramter;
}ParameterReceiver;



void ParameterReceiver_init(ParameterReceiver *self,LightValCtrl *lightValCtrl,SpeedCtrl *speedCtrl,CurvatureCtrl *curvatureCtrl);

void ParamterReceiver_parameter_adjust(ParameterReceiver *self);


#endif

