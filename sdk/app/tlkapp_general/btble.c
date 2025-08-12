/*
 * btble.c
 *
 *  Created on: 12-Jul-2025
 *      Author: saurabh
 */
#include "btble.h"
#include "bp_uart.h"
#include "spp_serial.h"
#include "tlkdrv/B91/gpio.h"
#include "tlkdrv/B91/uart.h"
#include "string.h"
#include "tlkstk/bt/btc/btc_hci.h"
#include "tlkdrv/B91/compatibility_pack/cmpt.h"
#include "tlkstk/bt/bth/bth_event.h"
#include "tlkstk/bt/bth/bth_acl.h"

volatile bool btc_conn_flag = 0;
volatile bool blec_conn_flag = 0;
uint16 g_aclHandle = 0;
uint08 g_rfcHandle = 0;
uint08 temp[128];
typedef void (*BtpSppRecvDataCB)(uint16 aclHandle, uint08 rfcHandle, uint08 *pData, uint16 dataLen);
typedef void(*TlkMmiBtMgrAclConnectCallback)(uint16 handle, uint08 status, uint08 *pBtAddr);
typedef void(*TlkMmiBtMgrAclDisconnCallback)(uint16 handle, uint08 reason, uint08 *pBtAddr);
extern void btp_spp_regDataCB(BtpSppRecvDataCB dataCB);
extern void tlkbt_hci_setC2hSppFlowCtrl(uint8_t isEnable);
extern uint08 btp_spp_getConnCount(void);
extern int blc_ll_getCurrentConnectionNumber(void);
//extern uint08 *tlkmmi_btmgr_getAddr(void);
//extern int bth_hci_sendPinCodeReqReplyCmd(uint08 mac[6], uint08 *pPinCode, uint08 pinlen);
//extern int bth_hci_sendPinCodeReqNegReplyCmd(uint08 mac[6]);
//extern int bth_hci_sendWriteSimplePairingModeCmd(uint08 spMode);
//extern int bth_hci_sendWriteSecureConnHostSupportCmd(uint08 isSupport);
//data callback for the classic data
//extern volatile uint08 uart_busy_flag;
uint08 pcode[6] = {1,2,3,4};
void spp_rx_callback(uint16 aclHandle, uint08 rfcHandle, uint08 *pData, uint16 dataLen)
{

    g_aclHandle = aclHandle;
    g_rfcHandle = rfcHandle;
	ringbuffer_t *used_buffer = (rfcHandle == 1)? &spp_rb_rx_1: &spp_rb_rx_2;
	for (uint16 i = 0; i < dataLen; i++) {
    	if(!rb_is_full(used_buffer))
    	{
    			rb_push(used_buffer, pData[i]);
    	}
    	else
    	{
    		//do something
    		uart_send(UART1,"DATA DROPPED",12);
//   		tlkbt_hci_setC2hSppFlowCtrl(1);
    	}
    }
    if(rb_count(used_buffer) > RTS_THRESHOLD)
    {
    	tlkbt_hci_setC2hSppFlowCtrl(1);
    	gpio_set_high_level(GPIO_PB4);
    }

}

void spp_init(void) {
    btp_spp_regDataCB(spp_rx_callback);
//    uint08 *p_addr = (uint08*)tlkmmi_btmgr_getAddr();
//    int i = sprintf(temp,"MAC_INIT=%02x:%02x:%02x:%02x:%02x:%02x\r\n",p_addr[0],p_addr[1],p_addr[2],p_addr[3],p_addr[4],p_addr[5]);
//    bth_acl_setPinCode(p_addr,pcode);
    uart_send(UART1, "STARTING\r\n", 10);
//    uart_send(UART1,temp,i);
//    flash_erase_chip();
//    flash_erase_chip_ram();
//    tlkmmi_sys_restoreFactorySettings();
}

void btble_conn_on_off() // indicate BT/BLE connection status
{
	int bt_conn = btp_spp_getConnCount();
	int ble_conn = blc_ll_getCurrentConnectionNumber();

	if (bt_conn > 0 || ble_conn > 0) {
		gpio_set_high_level(GPIO_PB7);
	} else {
		gpio_set_low_level(GPIO_PB7);
	}

	btc_conn_flag = (bt_conn > 0);
	blec_conn_flag = (ble_conn > 0);
}

