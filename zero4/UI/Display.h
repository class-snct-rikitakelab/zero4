#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "Calibration.h"
#include "ecrobot_interface.h"

#define MULTIPLE_TIME 100000 //PIDパラメータを何倍して表示したいかに応じて修正してください

typedef struct{
}Display;

extern void Display_init(Display *this_Display);
extern void Display_print_calibrate_value(int black_value,int white_value,int gyro_offset);
extern void Display_print_PID_paramteres(float Kp,float Ki,float Kd);
void Display_print_string(char* string,int x,int y);
void Display_clear();
#endif

