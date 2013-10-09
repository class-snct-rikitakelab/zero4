#include "Curvature.h"
#include "../../Factory.h"

void C_init(Curvature *this_Curvature){

}

float C_getCurvature(Curvature *this_Curvature,int time){

	return CurvatureEncoder_get_curvature(&curvatureEncoder);
}

float C_getTargCurvature(Curvature *this_Curvature){
	return this_Curvature->targCurvature;
}

void C_setTargCurvature(Curvature *this_Curvature,float parm){
	this_Curvature->targCurvature = parm;
}
