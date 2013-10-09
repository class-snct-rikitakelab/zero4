#include "MovingAverage.h"

void MovingAverage_init(MovingAverage *self,int max_count){
	self->index = 0;
	self->max_count = max_count;	
	int i = 0;
	for(i=0;i<MAX_ARRAY_NUMBER;++i){
		self->buf[i]=0;
	}
}

float MovingAverage_get_averaged_value(MovingAverage *self,float mesured_value){
	
	int i=0;
	float average=0,sum=0;
	
	if(self->index>=self->max_count){
		self->index=0;
	}

	for(i=0;i<self->max_count;++i){
		sum += self->buf[i];
	}

	self->buf[self->index]=mesured_value;
	
	self->index++;
	
	average = (float)sum /  self->max_count;
	
	return average;
}

