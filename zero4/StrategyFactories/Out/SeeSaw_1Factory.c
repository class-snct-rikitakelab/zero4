#include "SeeSaw_1Factory.h"


void seesaw_1_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop;
	MovementDirection movementDirection = FORWARD;
	int (*fp_SwitchJudge)(SwitchTerm);

	use_controller.target_curvature_controller_weight =0.0; //曲率制御の重み付け
	use_controller.target_light_controller_weight =1.0;	//輝度制御の重み付け
	switch_term.distance = 500; //距離切替を採用した際の切替条件 [mm]
	switch_term.inclination = 0; //傾き切替を採用した際の切替条件
	switch_term.speed = 50; //速度切替条件 [mm/s]
	switch_term.time =5000; //時間切替条件 [ms]
	balancing_requrement = 0; //倒立制御の有無 1:倒立走行 0:尻尾走行 合わせて尻尾角度を９５度程度にする必要あり
	target_tail_angle=100; //尻尾の目標角度
	gyroOffsetRevise=0; //ジャイロオフセット変更量　+方向に増やすと急加速 -方向に増やすと急原則　ただし数センチ程度進んだ段階でオフセットを戻さないとバランスを崩して転倒する
	request_forced_stop= 0; //完全に停止したい場合に1 通常の制御を掛ける場合は0
	movementDirection = FORWARD; //進行方向に従って設定する　前進 FORWARD 後退BACKWARD
	fp_SwitchJudge = SpeedTimerMultipleSwitch_judge_switch_method; //切替を判定する関数名を指定　
	/*
	距離切替 DistanceSwitch_judge_switch_method
	時間切替 TimeSwitch_judge_switch_method
	など
	*/

	RunningMethod_init(&SeesawFirstLineTraceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);


	seesaw_1_running_method_array[0]=SeesawFirstLineTraceMethod; //実施する走法を配列順番に格納

	int number_of_running_method=1; //区間で実施する走法の個数
	TargetValues target_values;  
	target_values.target_brightness = 0.5; //目標輝度
	target_values.target_curvature = 0.0; //目標曲率 [1/mm]
	target_values.target_speed = 100;  //目標速度 [mm/s]
	Section *nextSection = &seesaw_stop; //次の区間
	RunningMethod *runningMethod = seesaw_1_running_method_array;
	Section_init(&seesaw_1,nextSection,number_of_running_method,runningMethod,target_values);
}
