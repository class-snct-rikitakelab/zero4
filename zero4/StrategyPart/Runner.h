#ifndef _RUNNER_
#define _RUNNER_

#include "../UI/PushButton.h"
#include "Section.h"
#include "RunnerState.h"

typedef struct{
Section *current_section;
RunnerState runner_state;
}Runner;


void Runner_init(Runner *self,Section *start_section);
void Runner_run(Runner *self);
void Runner_execute(Runner *self);
void Runner_start_run(Runner *self);
void Runner_stop_run(Runner *self);
RunnerState Runner_get_runner_state(Runner *self);


#endif

