
#ifndef __CoordinateEncoder
#define __CoordinateEncoder

#include "../EncoderPart/DistanceEncoder.h"
#include "../EncoderPart/DirectionEncoder.h"
#include "../lib/mymath.h"


typedef struct{
	float xCoo;
	float yCoo;
	float distance_buf;
}CoordinateEncoder;


void CoordinateEncoder_init(CoordinateEncoder *self);


float CoordinateEncoder_get_xCoo(CoordinateEncoder *self);
float CoordinateEncoder_get_yCoo(CoordinateEncoder *self);
void CoordinateEncoder_calc_coordinate(CoordinateEncoder *self);
void CoordinateEncoder_reset_Encoder(CoordinateEncoder *self);

#endif

