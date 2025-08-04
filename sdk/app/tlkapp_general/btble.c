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
void spp_rx_callback(uint16 aclHandle, uint08 rfcHandle, uint08 *pData, uint16 dataLen)
{
    g_aclHandle = aclHandle;
    g_rfcHandle = rfcHandle;
    for (uint16 i = 0; i < dataLen; i++) {
    	if(!rb_is_full(&uart_rb_rx))
    	{
    			rb_push(&uart_rb_rx, pData[i]);
    	}
    	else
    	{

    	}
    }
    if(rb_count(&uart_rb_rx) > RTS_THRESHOLD)
    {
    	tlkbt_hci_setC2hSppFlowCtrl(1);
    	gpio_set_high_level(GPIO_PB5);
    }
}

void spp_init(void) {
    btp_spp_regDataCB(spp_rx_callback);
    uart_send(UART1, "STARTING\r\n", 10);

}

void btble_conn_on_off() //indiacte bt is connected or not
{
	if (btp_spp_getConnCount() > 0) {
		gpio_set_high_level(GPIO_PB7);
		btc_conn_flag = 1;
	}
	else if(blc_ll_getCurrentConnectionNumber() > 0)
	{
		blec_conn_flag = 1;
		gpio_set_high_level(GPIO_PB7);
	}
	else
	{
		gpio_set_low_level(GPIO_PB7);
		btc_conn_flag = 0;
		blec_conn_flag = 0;
	}

}
