#ifndef STRATEGYPART_RUNNING_METHOD_H
#define STRATEGYPART_RUNNING_METHOD_H


#include "../DrivenPart/DrivenDirector.h"
#include "SwitchTerm.h"
#include "TargetValues.h"
#include "../DrivenPart/ControllerWeight.h"

#include "../StrategyPart/RunningMethodSwitchJudge/SwitchJudge.h"
#include "../NXTSettings.h"

typedef struct {
	
	/**
	 * 倒立制御の有無
	 */
	int balancing_requrement;

	/**
	 * 使用制御器
	 */
	ControllerWeight use_controller;

	/**
	 * 尻尾角度
	 */
	int target_tail_angle;

	/**
	 * ジャイロオフセット補正値
	 */
	int gyroOffsetRevise;

	/**
	 * 走法切り替え判定値
	 */
	SwitchTerm switch_term;
	
	//走法切り替えの関数へのポインタ
	 int (*fp_SwitchJudge)(SwitchTerm);

	 int request_forced_stop;

	 MovementDirection movementDirection;

}RunningMethod;

void RunningMethod_init(RunningMethod *self,int balancing_requrement,ControllerWeight use_controller,int target_tail_angle,
					int gyroOffsetRevise,SwitchTerm switch_term,int (*fp_SwitchJudge)(SwitchTerm),int request_forced_stop,MovementDirection movementDirection);


	/**
	 * 走法切り替え判断
	 */
	int  RunningMethod_check_executed(RunningMethod *self);

	/**
	 * 走法を実行する
	 */
	void RunningMethod_execute_method(RunningMethod *self,TargetValues target_value);


#endif
