#include "CommonFunction.h"

float cutoff(float value, int criterion){
	
	float cut_offed;
	
	if(value>criterion){
		cut_offed = criterion;
	}
	else if(value<-criterion){
		cut_offed = -criterion;
	}
	else {
	cut_offed = value;
	}

	return cut_offed;
}

