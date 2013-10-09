#include "ParameterReceiver.h"
#include "../lib/MyString.h"

#define BUF_SIZE 11

static void ParameterReceiver_init_buf(char *buf,int buf_size );
static int ParameterReceiver_check_receive_data_number(char *buf);
static void ParameterReceiver_adjust_value(ParameterReceiver *self,char *buf);
static void ParameterReceiver_switch_adujusting_value(ParameterReceiver *self,char *buf);

ADJUSTING_PARAMETER ParameterReceiver_ato_ADJUSTING_PARAMETER(ParameterReceiver *self,char *buf);


void ParameterReceiver_init(ParameterReceiver *self,LightValCtrl *lightValCtrl,SpeedCtrl *speedCtrl,CurvatureCtrl *curvatureCtrl)
{
	self->lightValCtrl = lightValCtrl;
	self->curvatureCtrl = curvatureCtrl;
	self->speedCtrl = speedCtrl;
}

void ParamterReceiver_parameter_adjust(ParameterReceiver *self){
	int receive_length=0;
	char buf[ BUF_SIZE];

	ParameterReceiver_init_buf(buf,BUF_SIZE);

	receive_length = ecrobot_read_bt(buf, 0,  BUF_SIZE);
	if (receive_length > 0)
	{
		if(ParameterReceiver_check_receive_data_number(buf)==1){
			ParameterReceiver_adjust_value(self,buf);
		}
		else {
			ParameterReceiver_switch_adujusting_value(self,buf);
			ecrobot_sound_tone(449,40,30);
			}
	}
}
static void ParameterReceiver_init_buf(char *buf,int buf_size ){
	int i=0;
	for (i=0; i< buf_size ; i++)
	{
		buf[i] = '\0';
	}
}

static int ParameterReceiver_check_receive_data_number(char *buf){
	if(buf[0] == '0' || buf[0] == '1' ||buf[0] == '2' ||buf[0] == '3' ||buf[0] == '4' ||buf[0] == '5' ||buf[0] == '6' ||buf[0] == '7' ||buf[0] == '8' ||buf[0] == '09')
		{//my_atof(buf)!=0){
		return 1;
	}
	else {
		return 0;
	
	}
}


static void ParameterReceiver_adjust_value(ParameterReceiver *self,char *buf){
	
	PIDLightValCtrlParm *parameter = LVC_getCtrlParm(self->lightValCtrl);
	float new_value = my_atof(buf);

	switch (self->adjusing_paramter) {
		case KP :
			parameter->lKp = new_value;		
		break;

		case KI :
			parameter->lKi = new_value;
		break;

		case KD :
			parameter->lKd = new_value;
		break;
	}

	LVC_setCtrlParm(self->lightValCtrl,parameter);
	Display_print_PID_paramteres(parameter->lKp,parameter->lKi,parameter->lKd);
}

static void ParameterReceiver_switch_adujusting_value(ParameterReceiver *self,char *buf){
	self->adjusing_paramter = ParameterReceiver_ato_ADJUSTING_PARAMETER(self,buf);
}


ADJUSTING_PARAMETER ParameterReceiver_ato_ADJUSTING_PARAMETER(ParameterReceiver *self,char *buf){
	
	if(my_strcmp(buf,"KP")==0){
		return KP;
	}
	else if(my_strcmp(buf,"KI")==0){
		return KI;
	}
	else if(my_strcmp(buf,"KD")==0){
		return KD;
	}
}


