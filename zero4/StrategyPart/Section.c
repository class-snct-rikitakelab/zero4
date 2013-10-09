#include "Section.h"
#include "../Factory.h"


static void Section_update_current_running_methods(Section *self);

//区間最後の走法実行終了判断
static int Section_clear_section(Section *self,int executed_flag);
//走法切り替え時のエンコーダのリセット
static void Section_reset_encoder(Section *self);

void Section_init(Section *self,Section *nextSection,int number_of_running_method,RunningMethod *running_methods,TargetValues target_values)
{
	self->nextSection = nextSection;
	self->number_of_running_method = number_of_running_method;
	self->running_methods = running_methods;
	self->target_values.target_brightness = target_values.target_brightness;
	self->target_values.target_curvature  = target_values.target_curvature;
	self->target_values.target_speed = target_values.target_speed;
	self->current_running_method_number=0;
}


void Section_reset(Section *self){

	self->current_running_method_number=0;
}


struct Section* Section_get_next_section(Section *self)
{
	return self->nextSection;
}

int Section_clear_section(Section *self,int executed_flag)
{

	if(executed_flag==1 && 
		self->current_running_method_number+1 == self->number_of_running_method){
			ecrobot_sound_tone(880,10,60);
			return 1;
	}
	else {
		return 0;
	}
}

int Section_run(Section *self)
{
	int cleared_flag=0;
	RunningMethod_execute_method(&(self->running_methods[self->current_running_method_number]),self->target_values);
	
	
	int executed_flag =  RunningMethod_check_executed(&(self->running_methods[self->current_running_method_number]));
	
	if(Section_clear_section(self,executed_flag)){
		cleared_flag = 1;
	}

	if(executed_flag==1){
		Section_update_current_running_methods(self);
	}
	
	return cleared_flag;
}

static void Section_update_current_running_methods(Section *self){
			
	if(self->current_running_method_number +1 < self->number_of_running_method ) {
		self->current_running_method_number +=1;
	}
	else {
		//none
	}
	Section_reset_encoder(self);
}
	
static void Section_reset_encoder(Section *self){
	Timer_reset(&timer);
	DistanceEncoder_reset_Encoder(&distanceEncoder);
	//DirectionEncoder_reset(&directionEncoder);
	ecrobot_sound_tone(1000,5,100);
}