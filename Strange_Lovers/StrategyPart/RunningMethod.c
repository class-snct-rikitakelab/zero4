#include "RunningMethod.h"
#include "../Factory.h"

void RunningMethod_init(RunningMethod *self,int balancing_requrement,ControllerWeight use_controller,int target_tail_angle,
					int gyroOffsetRevise,SwitchTerm switch_term,int (*fp_SwitchJudge)(SwitchTerm))
{
	self->balancing_requrement = balancing_requrement;
	self->fp_SwitchJudge = fp_SwitchJudge;
	self->gyroOffsetRevise = gyroOffsetRevise;
	
	
	self->switch_term.distance = switch_term.distance;
	self->switch_term.inclination = switch_term.inclination;
	self->switch_term.time = switch_term.time;
	self->switch_term.inPushed = switch_term.inPushed;
	self->switch_term.speed= switch_term.speed;

	self->target_tail_angle = target_tail_angle;
	self->use_controller.target_curvature_controller_weight = use_controller.target_curvature_controller_weight;
	self->use_controller.target_light_controller_weight = use_controller.target_light_controller_weight;

}

int RunningMethod_check_executed(RunningMethod *self)
{
	return SwitchJudge_judge_switch_method(self->fp_SwitchJudge,self->switch_term);
}

void RunningMethod_execute_method(RunningMethod *self, TargetValues target_values)
{
		DrivenDirector_request_drive(&drivenDirector,target_values.target_brightness, target_values.target_curvature,
		target_values.target_speed,self->target_tail_angle,self->balancing_requrement,
		self->use_controller,self->gyroOffsetRevise);
}
