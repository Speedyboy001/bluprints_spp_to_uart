/*
 * app_serial.h
 *
 *  Created on: 22-Jun-2025
 *      Author: saurabh
 */

#ifndef APP_TLKAPP_GENERAL_SPP_SERIAL_H_
#define APP_TLKAPP_GENERAL_SPP_SERIAL_H_
#include "types.h"
#include "bp_uart.h"
typedef struct{
	uint08 hw_flow_ctrl_flg;
	uint08 pin_en_flag;
	uint08 pincode[6];
	uint08 pinlen;
	uint08 service_uuid[16];
	uint08 characteristic_notify_uuid[16];
	uint08 characteristic_write_uuid[16];
//	uint08 reserved[254];
}flag_typedef_t;
//typedef unsigned char flag_buffer[2];
//extern flag_buffer fc_hw_flag;
extern flag_typedef_t fc_hw_flag;

#endif /* APP_TLKAPP_GENERAL_SPP_SERIAL_H_ */
