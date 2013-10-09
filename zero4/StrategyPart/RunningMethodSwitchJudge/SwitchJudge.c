#include "SwitchJudge.h"

int SwitchJudge_judge_switch_method(int (*switch_judge_fp)(SwitchTerm),SwitchTerm switch_term){
	return (*switch_judge_fp)(switch_term);
}

