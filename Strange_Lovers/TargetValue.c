#include "TargetValue.h"
#include "Factory.h"

void TargetValue_init(TargetValue *this_Target_value){
	this_Target_value->target_brightness = 0;
	this_Target_value->angle_of_aim = 0;
}

void TargetValue_set_target_value_brightness(TargetValue *this_Target_value , int target_value){
	this_Target_value->target_brightness = target_value;
}

void TargetValue_set_anglr_of_aim(TargetValue *this_Target_value , int target_value){
	this_Target_value->angle_of_aim = target_value;
}

extern int TargetValue_Target_value_get(TargetValue *this_Target_value){
return 0;
}

