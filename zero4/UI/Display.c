#include "Display.h"
#include "../Factory.h"

#define STRING_LENGTH 20
#define ONE_LINE_STRING_LENGTH 20


void Display_init(Display *this_Display){
//	display_clear(0);	
}

void Display_print_calibrate_value(int black_value,int white_value,int gyro_offset){
	display_update();
}

void Display_print_PID_paramteres(float Kp,float Ki,float Kd){

	ecrobot_debug1(Kp*MULTIPLE_TIME,Ki*MULTIPLE_TIME,Kd*MULTIPLE_TIME);
}

void Display_print_string(char* string,int x,int y){

	display_goto_xy(x, y);
	display_string(string);
	display_update();
	
}
void Display_clear(){

	display_clear(1);
}

