#ifndef __MovingAverage
#define __MovingAverage
#define MAX_ARRAY_NUMBER 30

typedef struct {
	int index;
	float buf[MAX_ARRAY_NUMBER];
	int max_count;
}MovingAverage;

void MovingAverage_init(MovingAverage *self,int max_count);
void MovingAverage_finish(MovingAverage *self);
float MovingAverage_get_averaged_value(MovingAverage *self,float mesured_value);

#endif
