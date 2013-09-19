#include "SeeSaw_2_2Factory.h"


void seesaw_2_2factory_init(){

	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop;
	MovementDirection movementDirection = FORWARD;
	int (*fp_SwitchJudge)(SwitchTerm);

	/*できないっす

	use_controller.target_curvature_controller_weight =0.0; //曲率制御の重み付け
	use_controller.target_light_controller_weight =1.0;	//輝度制御の重み付け
	switch_term.distance = 50; //距離切替を採用した際の切替条件 [mm]
	switch_term.inclination = 0; //傾き切替を採用した際の切替条件
	switch_term.speed = 40; //速度切替条件 [mm/s]
	switch_term.time =2000; //時間切替条件 [ms]
	balancing_requrement = 0; //倒立制御の有無 1:倒立走行 0:尻尾走行 合わせて尻尾角度を９５度程度にする必要あり
	target_tail_angle=100; //尻尾の目標角度
	gyroOffsetRevise=0; //ジャイロオフセット変更量　+方向に増やすと急加速 -方向に増やすと急原則　ただし数センチ程度進んだ段階でオフセットを戻さないとバランスを崩して転倒する
	request_forced_stop= 0; //完全に停止したい場合に1 通常の制御を掛ける場合は0
	movementDirection = FORWARD; //進行方向に従って設定する　前進 FORWARD 後退BACKWARD
	fp_SwitchJudge = DistanceSwitch_judge_switch_method; //切替を判定する関数名を指定　
	/*
	距離切替 DistanceSwitch_judge_switch_method
	時間切替 TTimeSwitch_judge_switch_method
	など
	*/

	//RunningMethod_init(&runningforwardMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);

	//智之さんのやつからコピペ

	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.time =1000;
	balancing_requrement = 0;
	target_tail_angle=100;
	gyroOffsetRevise=0;
	request_forced_stop= 1;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&stopMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	
	
	//tailMoveRunningMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance =0 ;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time =250;
	//switch_term.tail_angle=130;		//119;
	balancing_requrement = 0;
	target_tail_angle=125;

	gyroOffsetRevise=0;
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&tailplusmovingMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

	//tailBackRunningMethod

	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance =0 ;
	switch_term.inclination = 0;
	switch_term.inPushed = 0;
	switch_term.speed = 0;
	switch_term.time = 200;
	//switch_term.tail_angle=0;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;		
	request_forced_stop = 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&tailbackMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	

/*
	
	//tailplusmovingMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance = 0;
	switch_term.inclination = 0;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time =200;
	switch_term.tail_angle =119;
	balancing_requrement = 0;
	target_tail_angle=119;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&tailplusmovingMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	
	//tailbackMethod
	use_controller.target_curvature_controller_weight = 0.0;
	use_controller.target_light_controller_weight = 0.0;
	switch_term.distance = 0;
	switch_term.inclination = 0;
	switch_term.inPushed = 1;
	switch_term.speed = 0;
	switch_term.time =200;
	balancing_requrement = 1;
	target_tail_angle=0;
	gyroOffsetRevise=0;
	request_forced_stop= 0;
	movementDirection = FORWARD;
	fp_SwitchJudge = TimeSwitch_judge_switch_method;
	RunningMethod_init(&tailbackMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);
	
	*/

	seesaw_2_2running_method_array[0]=stopMethod;
	seesaw_2_2running_method_array[1]=tailplusmovingMethod;
	seesaw_2_2running_method_array[2]=tailbackMethod;


	int number_of_running_method=3;
	TargetValues target_values; 
	target_values.target_brightness = 0.5;
	target_values.target_curvature = 0.0;
	target_values.target_speed = 0;
	Section *nextSection = &seesaw_3;
	RunningMethod *runningMethod = seesaw_2_2running_method_array;
	Section_init(&seesaw_2_2,nextSection,number_of_running_method,runningMethod,target_values);
	
}
