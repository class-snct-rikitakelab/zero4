#include "StartSignalRecieveSwitch.h"
#include "../../Factory.h"
#define BUF_SIZE 11

int StartSignalRecieveSwitch_judge_switch_method(SwitchTerm switch_term)
{			
	int start_flag = 0;
	int bt_flg=0;
	unsigned int rx_length;
	char rx_buf[BUF_SIZE];
	rx_buf[0] == 0;

	rx_length = ecrobot_read_bt(rx_buf, 0, BUF_SIZE);

	if(rx_length>0){
		if(rx_buf[0]=='1')
			bt_flg=1;
	}
	

	
	if(PushButton_detect_push_button(&pushButton) == TRUE || bt_flg==1){
		start_flag = 1;

	}
	
		return start_flag;
}

