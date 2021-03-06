#ifndef STRATEGYPART_SECTION_H
#define STRATEGYPART_SECTION_H

#include "../StrategyPart/RunningMethod.h"
#include "../StrategyPart/TargetValues.h"

/**
 * 区間
 */

typedef struct {
	struct Section *nextSection;
	int current_running_method_number;
	int number_of_running_method;
	RunningMethod *running_methods;
	TargetValues target_values;
}Section;

	/**
	 * 次区間を取得する
	 */
	struct Section* Section_get_next_section(Section *self);

	int Section_run(Section *self);

	void  Section_init(Section *self,Section *nextSection,int number_of_running_method,RunningMethod *running_methods,TargetValues target_values);

	void Section_reset(Section *self);

#endif
