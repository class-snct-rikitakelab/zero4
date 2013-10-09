#include "Area.h"
#include "../Factory.h"

int Area_end(Area *self);

int Area_end(Area *self){

}

struct Area* Area_get_next_area(Area *self){
	return self->nextArea;
}

int Area_run(Area *self){
	if(Section_run(self->current_section)==1){
		Section_reset(self->current_section);
		self->current_section = Section_get_next_section(self->current_section);
	}

	if(Area_end(self)){
		return 1;
	}
	return 0;
}

void  Area_init(Area *self,Area *nextArea,Section *start_section,int number_of_section){
	self->nextArea = nextArea;
	self->number_of_section = number_of_section;
	self->current_section = start_section;
}

void Area_reset(Area *self){

}