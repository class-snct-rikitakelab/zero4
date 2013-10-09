

#include "SystemTimer.h"


U32 SystemTimer_get_ms(){
	
	return (U32)systick_get_ms();
}

