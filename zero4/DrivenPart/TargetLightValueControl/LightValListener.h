#ifndef _LIGHT_VAL_LISTENER_H
#define _LIGHT_VAL_LISTENER_H

#include "ecrobot_interface.h"

typedef struct{
	int lvlState;
}LightValListener;

extern void LVL_init(LightValListener *this_LightValListener);
extern void LVL_emergency(LightValListener *this_LightValListener,int parm);
extern int LVL_getState(LightValListener *this_LightValListener);

#endif
