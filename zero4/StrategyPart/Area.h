#ifndef STRATEGYPART_AREA
#define STRATEGYPART_AREA

#include "../StrategyPart/Section.h"



typedef struct {
	struct Area *nextArea;
	int number_of_section;
	Section  *current_section;
}Area;

	
	struct Area* Area_get_next_area(Area *self);

	int Area_run(Area *self);

	void  Area_init(Area *self,Area *nextArea,Section *start_section,int number_of_section);

	void Area_reset(Area *self);

#endif
