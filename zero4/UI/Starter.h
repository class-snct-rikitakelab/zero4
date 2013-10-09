#ifndef _Starter_
#define _Starter_

#include "../HardwareWrapper/TouchSensor.h"
#include "../StrategyPart/Runner.h"
#include "./StarterState.h"
#include "ParameterReceiver.h"



typedef struct{
	StarterState starter_state;
}Starter;



void Starter_init(Starter *self);

void Starter_accept_start_run(Starter *self);

void Starter_accept_stop_run(Starter *self);

void Starter_user_command_accept(Starter *self);

void Starter_parameter_adjust(Starter *self);
#endif

