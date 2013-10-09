#ifndef _WheelActuator_H_
#define _WheelActuator_H_


#include "balancer.h"
#include "WheelMotor.h"
#include "../EncoderPart/InclinationEncoder.h"


typedef struct{
	float forward;
	float turn;
	int self_balancing_requirment;
}WheelActuator;


extern void WheelActuator_init(WheelActuator *this_WheelActuator);
extern void WheelActuator_balance_running(WheelActuator *this_WheelActuator,S8 *pwm_l,S8 *pwm_r);
extern void WheelActuator_set_forward(WheelActuator *this_WheelActuator , float forward);
extern void WheelActuator_set_turn(WheelActuator *this_WheelActuator , float turn);
extern void WheelActuator_tail_running(WheelActuator *this_WheelActuator,S8 *pwm_l,S8 *pwm_r);
extern void WheelActuator_dirve_motors(WheelActuator *this_WheelActuator);
void WheelActuator_set_self_balancing_requirement(WheelActuator *this_WheelActuator,int self_balancing_requirment);
void WheelActuator_stop_wheel_motors(WheelActuator *self);
void WheelActuator_revise_gyro_offset(WheelActuator *self,int gyro_offset_revise);
#endif

