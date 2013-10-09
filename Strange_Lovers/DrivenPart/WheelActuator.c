#include "WheelActuator.h"
#include "../Factory.h"

#define KINGYO_PWM_HOSEI 0.987


static void WheelActuator_reset_wheel_motors(WheelActuator *self);
static int WheelActuator_need_reset_balancer(WheelActuator *self,int self_balancing_requirment);

void WheelActuator_init(WheelActuator *self){
	self->forward = 0;
	self->turn = 0;
	balance_init();
}

void WheelActuator_balance_running(WheelActuator *self,S8 *pwm_l,S8 *pwm_r){
	
	balance_control(
				(F32)self->forward,
				(F32)self->turn,
				(F32)InclinationEncoder_get_inclination(&inclinationEncoder),
				(F32)InclinationEncoder_get_gyro_offset(&inclinationEncoder),
				(F32)nxt_motor_get_count(NXT_PORT_C),
				(F32)nxt_motor_get_count(NXT_PORT_B),
				(F32)ecrobot_get_battery_voltage(),
				pwm_l,
				pwm_r);
}


void WheelActuator_set_forward(WheelActuator *self , float forward){
	self->forward = forward;
}

void WheelActuator_set_turn(WheelActuator *self , float turn){
	self->turn = turn;
}

void WheelActuator_tail_running(WheelActuator *self,S8 *pwm_l,S8 *pwm_r){
	S8 rivised_pwm_l=0,rivised_pwm_r=0;
	if(self->turn>=0){
		rivised_pwm_l = 100;
		rivised_pwm_r = 100- self->turn ;
	}
	else {
		rivised_pwm_l = 100 - (-self->turn);
		rivised_pwm_r = 100;
	}
	*pwm_l = cutoff(rivised_pwm_l,100);
	*pwm_r = cutoff(rivised_pwm_r,100);
	
}

void WheelActuator_dirve_motors(WheelActuator *self){
	S8 pwm_l=0,pwm_r=0;
	if(self->self_balancing_requirment == 1){
		WheelActuator_balance_running(self,&pwm_l,&pwm_r);
	}
	else if(self->self_balancing_requirment==0){
		 WheelActuator_tail_running(self,&pwm_l,&pwm_r);
	}
	else {
	//fetal error
	}

	WheelMotor_drive_motor(&leftWheelMotor,pwm_l);
	WheelMotor_drive_motor(&rightWheelMotor,pwm_r);
}


void WheelActuator_set_self_balancing_requirement(WheelActuator *self,int self_balancing_requirment){
	if(WheelActuator_need_reset_balancer(self,self_balancing_requirment)){
		balance_init();
		WheelActuator_reset_wheel_motors(self);
	}
	self->self_balancing_requirment= self_balancing_requirment;
}

void WheelActuator_stop_wheel_motors(WheelActuator *self)
{
	WheelMotor_drive_motor(&leftWheelMotor,0);
	WheelMotor_drive_motor(&rightWheelMotor,0);
}

void WheelActuator_revise_gyro_offset(WheelActuator *self,int gyro_offset_revise){
	int base = InclinationEncoder_get_intilal_gyro_offset(&inclinationEncoder);
	int revised_gyro_offset = base + gyro_offset_revise;

	InclinationEncoder_set_gyro_offset(&inclinationEncoder,revised_gyro_offset);

}

void WheelActuator_reset_wheel_motors(WheelActuator *self){
	WheelMotor_set_count(&leftWheelMotor,0);
	WheelMotor_set_count(&rightWheelMotor,0);
}

int WheelActuator_need_reset_balancer(WheelActuator *self,int self_balancing_requirment){
	
	if(self->self_balancing_requirment == 0 && self_balancing_requirment ==1){
		return 1;
	}
	return 0;
}