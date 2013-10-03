#include "CommonInitializeInterface.h"
#include "../../Factory.h"


//InCourse
#include "../In/FiststStraightFactory.h"
#include "../In/SlopeFactory.h"
#include "../In/StartUpFactory.h"
#include "../In/SecondStraightFactory.h"
#include "../In/SecondCurveFactory.h"
#include "../In/ThurdStraightFactory.h"
#include "../In/ThurdCurveFactory.h"
#include "../In/ForthStraightFactory.h"
#include "../In/ForthCurveFactory.h"
#include "../In/InFifthStraightFactory.h"
#include "../In/InFifthCurveFactory.h"
#include "../In/AfterInFifthCurveStraight.h"
#include "../In/InSixthCurveFactory.h"
#include "../In/BalanceStopFactory.h"
#include "../In/LookUpGate.h"
#include "../In/LookUpGate2.h"
#include "../In/LookUpGate3.h"
#include "../In/LookUpGate4.h"
#include "../In/LookUpGate5.h"
#include "../In/GarageIn.h"
#include "../In/Stop.h"


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
	In_fifth_straight_factory_init();
	In_fifth_curve_factory_init();
	after_In_fifth_curve_straight_factory_init();
	In_sixth_curve_factory_init();
	
	look_up_factory_init();
	look_up2_factory_init();
	look_up3_factory_init();
	look_up4_factory_init();
	look_up5_factory_init();
	garage_factory_init();
	balance_stop_factory_init();
	stop_factory_init();

	startSection = &startUp;
}

