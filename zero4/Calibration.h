#ifndef _CALIBRATION_H_
#define _CALIBRATION_H_

#include "Balancer.h"

#include "UI/Display.h"
#include "UI/PushButton.h"
#include "EncoderPart/InclinationEncoder.h"
#include "./EncoderPart/BrightnessEncoder.h"


typedef struct{
	U32 gyro;
}Calibration;


extern void Calibration_init(Calibration *this_Calibration);
int Calibration_calibration(Calibration *this_Calibration);

#endif

