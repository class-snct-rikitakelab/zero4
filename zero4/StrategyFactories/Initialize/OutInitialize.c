#include "CommonInitializeInterface.h"
#include "../../Factory.h"

#include "../Out/StartUpFactory.h"
#include "../Out/StartUpWithTailFactory.h"

//OutCourse
#include "../Out/FiststStraightFactory.h"
#include "../Out/SlopeFactory.h"

#include "../Out/SecondStraightFactory.h"
#include "../Out/SecondCurveFactory.h"
#include "../Out/ThurdStraightFactory.h"
#include "../Out/ThurdCurveFactory.h"
#include "../Out/ForthStraightFactory.h"
#include "../Out/ForthCurveFactory.h"
#include "../Out/OutFifthStraightFactory.h"
#include "../Out/OutFifthCurveFactory.h"
#include "../Out/AfterOutFifthCurveStraight.h"
#include "../Out/OutSixthCurveFactory.h"

#include "../Out/SeeSaw_stopFactory.h"
#include "../Out/SeeSaw_1Factory.h"
#include "../Out/SeeSaw_stopFactory.h"
#include "../Out/SeeSaw_2Factory.h"
#include "../Out/SeeSaw_2_2Factory.h"
#include "../Out/SeeSaw_3Factory.h"
#include "../Out/SeeSaw_4Factory.h"
#include "../Out/SeeSaw_5Factory.h"
#include "../Out/SeeSaw_UpslopeFactory.h"




void strategies_init(){
	
	first_straight_speedUp_factory_init();
	
	first_curve_factory_init();
	after_slope_straight_factory_init();
	slope_factory_init();
	first_straight_factory_init();
	start_up__factory_init();
	second_straight_factory_init();
	second_curve_factory_init();
	thurd_straight_factory_init();
	thurd_curve_factory_init();
	forth_straight_factory_init();
	forth_curve_factory_init();
	start_up_with_tail_factory_init();
	out_fifth_straight_factory_init();
	out_fifth_curve_factory_init();
	after_out_fifth_curve_straight_factory_init();
	out_sixth_curve_factory_init();

	
	seesaw_1_factory_init();
	seesaw_stop_factory_init();
	seesaw_2_factory_init();
	seesaw_2_2factory_init();
	seesaw_2_3factory_init();
	seesaw_3_factory_init();
	seesaw_Upslope_factory_init();
	seesaw_4_factory_init();

	startSection = &startUpWithTail;

}

