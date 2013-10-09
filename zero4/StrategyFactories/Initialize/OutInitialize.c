#include "CommonInitializeInterface.h"
#include "../../Factory.h"

#include "../Out/StartUpWithTailFactory.h"

//OutCourse
#include "../Out/FiststStraightFactory.h"




void strategies_init(){
	
	first_straight_speedUp_factory_init();
	
	start_up_with_tail_factory_init();

	startSection = &startUpWithTail;

}

