/*
 * app_serial.h
 *
 *  Created on: 22-Jun-2025
 *      Author: saurabh
 */
#include <app/tlkapp_general/spp_serial.h>
#include "core/tlk_config.h"
#include <uart.h>
#include <string.h>
#include "tlkapi/tlkapi_error.h"
#include <clock.h>
#include <stdio.h>
#include "tlkstk/ble/ble_common.h"
#include "btble.h"
#include "tlkmdi/le/tlkmdi_lemgrAtt.h"
#include <stdlib.h>
#include "stimer.h"
#include "tlkdrv/B91/compatibility_pack/cmpt.h"

/******************************MACROS FOR BUFFER**************************/

#define MAX_BAUD_RATE 921600
#define MIN_BAUD_RATE 4800
#define AT_CMD_BUFFER 128
/************************************************************************/

char release_version[20] = "BPRINTS_BT_V1.0"; //VERSIONS USED

/*******************************BUFFERS*********************************/
uint08 at_cmd_buffer[AT_CMD_BUFFER];
uint08 buff_temp[138];
uint08 idx = 0;
uint16_t g_spp_rx_len = 0;
uint08 * str_buff, * chr_buff;

/********************************FLAGS********************************/

extern volatile bool btc_conn_flag;
extern volatile bool blec_conn_flag;
volatile bool uart_rx_flg = 0;
flag_typedef_t fc_hw_flag;
extern uint16 g_aclHandle;
//extern uint08 g_rfcHandle;
extern volatile uint16 g_connHandle;

/****************************extern function******************************/

extern uint32 tlkcfg_getSerialBaudrate(void);
extern void tlkcfg_setSerialBaudrate(uint32 baudrate);
extern void tlkbt_hci_setC2hSppFlowCtrl(uint8_t isEnable);
extern int tlkmmi_btmgr_setName(uint08 * pName, uint08 nameLen);
extern int tlkmmi_btmgr_setAddr(uint08 * pAddr);
typedef void( * BtpSppRecvDataCB)(uint16 aclHandle, uint08 rfcHandle, uint08 * pData, uint16 dataLen);
extern uint08 * tlkmmi_btmgr_getAddr(void);
extern int tlkmmi_lemgr_setName(uint08 * pName, uint08 nameLen);
extern int tlkmmi_lemgr_setAddr(uint08 * pAddr);
extern uint08 * tlkmmi_lemgr_getName(void);
extern uint08 * tlkmmi_btmgr_getAddr(void);
extern uint08 * tlkmmi_lemgr_getAddr(void);
extern uint08 * tlkmmi_btmgr_getName(void);
extern int bth_acl_setPinCode(uint08 btaddr[6], uint08 pinCode[6]);
extern int btp_spp_sendData(uint16 aclHandle, uint08 * pHead, uint08 headLen, uint08 * pData, uint16 dataLen);
extern ble_sts_t blc_gatt_pushHandleValueNotify(u16 connHandle, u16 attHandle, u8 * p, int len);
extern void flash_read_page(unsigned long addr, unsigned long len, unsigned char * buf);
extern void flash_erase_sector(unsigned long addr);
extern void flash_write_page(unsigned long addr, unsigned long len, unsigned char * buf);
extern void btble_conn_on_off();
extern unsigned int tlkcfg_getFlashAddr(unsigned int offset);

static void send_data_to_uart(ringbuffer_t * rb, bool is_spp);
/****************************default value *****************************/

//BT ADDR
uint08 bt_addr[6] = {
    0x95,
    0x27,
    0x73,
    0xab,
    0xd7,
    0x6d
};

uint08 ble_addr[6] = {
    0xab,
    0x27,
    0x73,
    0x95,
    0xd7,
    0x6d
};

uint16_t c_len = 0;

//used to set the deafult values
void set_default_flag_values(void) {
    fc_hw_flag.hw_flow_ctrl_flg = 0; //HW FLOW DISABLED
    fc_hw_flag.pin_en_flag = 0; //LEGACY PIN MODE DISABLED
    fc_hw_flag.pinlen = 4; // Default 4-digit PIN
    memset(fc_hw_flag.pincode, 0, 6);
    fc_hw_flag.pincode[0] = '0';
    fc_hw_flag.pincode[1] = '0';
    fc_hw_flag.pincode[2] = '0';
    fc_hw_flag.pincode[3] = '0';

    //SERVICE UUID
    memcpy(fc_hw_flag.service_uuid, (uint8_t[]) {
        0x10,
        0x19,
        0x0D,
        0x0C,
        0x0B,
        0x0A,
        0x09,
        0x08,
        0x07,
        0x06,
        0x05,
        0x04,
        0x03,
        0x02,
        0x01,
        0x00
    }, 16);
    //NOTIFY UUID
    memcpy(fc_hw_flag.characteristic_notify_uuid, (uint8_t[]) {
        0x10,
        0x2B,
        0x0D,
        0x0C,
        0x0B,
        0x0A,
        0x09,
        0x08,
        0x07,
        0x06,
        0x05,
        0x04,
        0x03,
        0x02,
        0x01,
        0x00
    }, 16);
    //WRITE UUID
    memcpy(fc_hw_flag.characteristic_write_uuid, (uint8_t[]) {
        0x11,
        0x2B,
        0x0D,
        0x0C,
        0x0B,
        0x0A,
        0x09,
        0x08,
        0x07,
        0x06,
        0x05,
        0x04,
        0x03,
        0x02,
        0x01,
        0x00
    }, 16);

    // Set device addresses
    //    tlkmmi_btmgr_setAddr(bt_addr);
    //    tlkmmi_lemgr_setAddr(ble_addr);

    // Set default names already default set in sdk
    // tlkmmi_btmgr_setName("TELINK_SPP", 10);
    // tlkmmi_lemgr_setName("TELINK_BLE", 11);
}

//use to set the values at boot
void save_flags_to_flash(void) {
    unsigned int flash_addr = tlkcfg_getFlashAddr(TLK_CFG_FLASH_USER_DATA_ADDR);
    if (flash_addr != 0) {
        flash_erase_sector(flash_addr);
        flash_write_page(flash_addr, sizeof(flag_typedef_t), (uint08 * ) & fc_hw_flag);
    }
}

/***********************************************for hex to ascii bTname******************************************/

void print_mac_address() {
    int len = sprintf(buff_temp, "+MAC=%02x:%02x:%02x:%02x:%02x:%02x\n\r",
        bt_addr[0], bt_addr[1], bt_addr[2], bt_addr[3], bt_addr[4], bt_addr[5]);
    uart_send(UART1, buff_temp, len);
}
void print_lemac_address() {
    int len = sprintf(buff_temp, "+LEMAC=%02x:%02x:%02x:%02x:%02x:%02x\n\r",
        ble_addr[0], ble_addr[1], ble_addr[2], ble_addr[3], ble_addr[4], ble_addr[5]);
    uart_send(UART1, buff_temp, len);
}

/***********************************************for ascii to hex bTname******************************************/

int parse_mac_string(const char * str, uint08 * mac_out) {
    return sscanf(str, "%02x%02x%02x%02x%02x%02x", &
        mac_out[0], & mac_out[1], & mac_out[2], &
        mac_out[3], & mac_out[4], & mac_out[5]);
}

//parsing uuid to hex format
int parse_uuid_string(const char * str, uint08 * uuid_out) {
    if (strlen(str) != 32) return 0;
    for (int i = 0; i < 16; i++) {
        char hex_pair[3];
        hex_pair[0] = str[i * 2];
        hex_pair[1] = str[i * 2 + 1];
        hex_pair[2] = '\0';

        if (sscanf(hex_pair, "%02x", & uuid_out[i]) != 1) {
            return 0;
        }
    }
    return 1;
}

/**************************RESPONSE FUNC************************************/
void notify_cmd_ok() {
    uart_send(UART1, "OK\n\r", 4);
}
void notify_cmd_error() {
    uart_send(UART1, "Err\n\r", 5);
}

//uart irq
_attribute_ram_code_sec_
void uart1_irq_handler(void) {
    if (uart_get_irq_status(UART1, UART_RX_ERR)) {
        uart_reset(UART1);
        uart_clr_irq_status(UART1, UART_CLR_RX);
    }

    if (uart_get_irq_status(UART1, UART_RXBUF_IRQ_STATUS)) {
        while (uart_get_rxfifo_num(UART1) && idx < AT_CMD_BUFFER - 1) {
            char data = uart_read_byte(UART1);
            at_cmd_buffer[idx++] = data;
            if (data == 0x0A) {
                uart_rx_flg = 1;
            }
        }
        at_cmd_buffer[idx] = '\0';
        if (idx >= AT_CMD_BUFFER - 1) {
            idx = 0;
            uart_rx_flg = 0;
            memset(at_cmd_buffer, 0, AT_CMD_BUFFER);
        }
    }
}

void fetch_flag_flash() {
    unsigned int flash_addr = tlkcfg_getFlashAddr(TLK_CFG_FLASH_USER_DATA_ADDR);
    bool flash_data_valid = false;

    if (flash_addr != 0) {
        flash_read_page(flash_addr, sizeof(flag_typedef_t), (uint08 * ) & fc_hw_flag);
        uint08 * flash_data = (uint08 * ) & fc_hw_flag;
        for (int i = 0; i < sizeof(flag_typedef_t); i++) {
            if (flash_data[i] != 0xFF) {
                flash_data_valid = true;
                break;
            }
        }
        if (fc_hw_flag.pinlen < 4 || fc_hw_flag.pinlen > 6) {
            flash_data_valid = false;
        }
        if (!flash_data_valid) {
            set_default_flag_values();
            save_flags_to_flash();
        }
    } else {
        set_default_flag_values();
        save_flags_to_flash();
    }
}

//AT CMD PARSER
void process_at_cmd(uint08 * cmd) {
    if (cmd[0] == 'A' && cmd[1] == 'T') {
        if ((strstr((const char * ) cmd, "+DNAME=") != NULL)) //BTNAME
        {
            chr_buff = strchr(cmd, '=');
            if (!chr_buff) {
                notify_cmd_error();
                return;
            }
            chr_buff++;
            uint08 name_len = strlen((const char * ) chr_buff);
            if (name_len > 0) {
                if (tlkmmi_btmgr_setName(chr_buff, name_len) == TLK_ENONE) {
                    notify_cmd_ok();
                } else {
                    notify_cmd_error();
                }
            } else {
                uart_send(UART1, (uint08 * )
                    "ERROR: Empty name\r\n", 19);
            }
        } else if (strstr((const char * ) cmd, "+LENAME=") != NULL) //LENAME
        {
            chr_buff = strchr(cmd, '=');
            if (!chr_buff) {
                notify_cmd_error();
                return;
            }
            chr_buff++;
            uint08 name_len = strlen((const char * ) chr_buff);
            if (name_len > 0) {
                if (tlkmmi_lemgr_setName(chr_buff, name_len) == TLK_ENONE) {
                    notify_cmd_ok();
                } else {
                    notify_cmd_error();
                }
            } else {
                uart_send(UART1, (uint08 * )
                    "ERROR: Empty name\r\n", 19);
            }
        } else if ((strstr((const char * ) cmd, "+MAC=") != NULL)) //BTADDRESS
        {
            chr_buff = strchr(cmd, '=');
            chr_buff++;
            // parse_mac_string((const char * ) chr_buff, bt_addr);
            if (!parse_mac_string((const char * ) chr_buff, bt_addr)) {
                notify_cmd_error();
                return;
            }
            if (tlkmmi_btmgr_setAddr(bt_addr) == TLK_ENONE) {
                notify_cmd_ok();
//                delay_ms(100);
//                core_reboot();

            }
        } else if ((strstr((const char * ) cmd, "+LEMAC=") != NULL)) //LEADDRESS
        {
            chr_buff = strchr(cmd, '=');
            chr_buff++;
            if (!parse_mac_string((const char * ) chr_buff, ble_addr)) {
                notify_cmd_error();
                return;
            }
            if (tlkmmi_lemgr_setAddr(ble_addr) == TLK_ENONE) {
                notify_cmd_ok();
            }
        } else if ((strstr((const char * ) cmd, "+PIN=") != NULL)) //BTPINSET
        {
            chr_buff = strchr(cmd, '=');
            if (!chr_buff) {
                notify_cmd_error();
                return;
            }
            chr_buff++;
            uint08 * dev_addr = (uint08 * ) tlkmmi_btmgr_getAddr();
            uint08 pin_len = strlen((const char * ) chr_buff);
            if (pin_len < 4 || pin_len > 6) {
                notify_cmd_error();
                return;
            }
            fc_hw_flag.pinlen = pin_len;
            memset(fc_hw_flag.pincode, 0, 6);
            memcpy(fc_hw_flag.pincode, chr_buff, pin_len);
            if (bth_acl_setPinCode(dev_addr, fc_hw_flag.pincode)) {
                unsigned int flash_addr = tlkcfg_getFlashAddr(TLK_CFG_FLASH_USER_DATA_ADDR);
                flash_erase_sector(flash_addr);
                flash_write_page(flash_addr, sizeof(flag_typedef_t), (uint08 * ) & fc_hw_flag);
                notify_cmd_ok();
            } else {
                notify_cmd_error();
            }
        } else if (strstr((const char * ) cmd, "+PINE=") != NULL) { //enable legacy pin mode
            chr_buff = strchr(cmd, '=');
            if (!chr_buff) {
                notify_cmd_error();
                return;
            }
            chr_buff++;
            uint08 fc_value = atoi((const char * ) chr_buff);
            fc_hw_flag.pin_en_flag = (fc_value == 1) ? 1 : 0;
            unsigned int flash_addr = tlkcfg_getFlashAddr(TLK_CFG_FLASH_USER_DATA_ADDR);
            flash_erase_sector(flash_addr);
            flash_write_page(flash_addr, sizeof(flag_typedef_t), (uint08 * ) & fc_hw_flag);
            notify_cmd_ok();
        } else if (strstr((const char * ) cmd, "+URATE=") != NULL) { //Baudrate change
            uint32 baudrate = 0;
            chr_buff = strchr(cmd, '=');

            chr_buff++;
            c_len = strlen((const char * ) chr_buff);
            unsigned short div = 0;
            unsigned char bwpc = 0;
            if (strstr(chr_buff, "4800")) baudrate = 4800;
            if (strstr(chr_buff, "9600")) baudrate = 9600;
            if (strstr(chr_buff, "14400")) baudrate = 14400;
            if (strstr(chr_buff, "19200")) baudrate = 19200;
            if (strstr(chr_buff, "38400")) baudrate = 38400;
            if (strstr(chr_buff, "57600")) baudrate = 57600;
            if (strstr(chr_buff, "115200")) baudrate = 115200;
            if (strstr(chr_buff, "230400")) baudrate = 230400;
            if (strstr(chr_buff, "460800")) baudrate = 460800;
            if (strstr(chr_buff, "921600")) baudrate = 921600;
            if (baudrate >= MIN_BAUD_RATE && baudrate <= MAX_BAUD_RATE) {
                notify_cmd_ok();
                tlkcfg_setSerialBaudrate(baudrate);
                while (uart_tx_is_busy(UART1));
                plic_interrupt_disable(IRQ18_UART1);
                uart_reset(UART1);
                uart_clr_tx_index(UART1);
                uart_clr_rx_index(UART1);
                uart_cal_div_and_bwpc(baudrate, sys_clk.pclk * 1000 * 1000, & div, & bwpc);
                uart_init(UART1, div, bwpc, UART_PARITY_NONE, UART_STOP_BIT_ONE);
                plic_interrupt_enable(IRQ18_UART1);
            }

        } else if (strstr((const char * ) cmd, "+FC=") != NULL) { //HW FLOW
            chr_buff = strchr(cmd, '=');
            if (!chr_buff) return;
            chr_buff++;
            uint08 fc_value = atoi(chr_buff);
            fc_hw_flag.hw_flow_ctrl_flg = (fc_value == 1) ? 1 : 0;
            unsigned int flash_addr = tlkcfg_getFlashAddr(TLK_CFG_FLASH_USER_DATA_ADDR);
            flash_erase_sector(flash_addr);
            flash_write_page(flash_addr, sizeof(flag_typedef_t), (uint08 * ) & fc_hw_flag);
            notify_cmd_ok();
        } else if (strstr((const char * ) cmd, "+SERV=")) {
            chr_buff = (uint8_t * ) strchr((const char * ) cmd, '=');
            if (chr_buff) {
                chr_buff++;
                c_len = strlen((const char * ) chr_buff);
                if (c_len == 32) {
                    if (parse_uuid_string((const char * ) chr_buff, fc_hw_flag.service_uuid)) {
                        unsigned int flash_addr = tlkcfg_getFlashAddr(TLK_CFG_FLASH_USER_DATA_ADDR);
                        if (flash_addr != 0) {
                            flash_erase_sector(flash_addr);
                            flash_write_page(flash_addr, sizeof(flag_typedef_t), (uint08 * ) & fc_hw_flag);
                            notify_cmd_ok();
                        } else {
                            notify_cmd_error();
                        }
                        return;
                    } else {
                        uart_send(UART1, "ERROR: Invalid UUID format\r\n", 26);
                        notify_cmd_error();
                        return;
                    }
                } else {
                    notify_cmd_error();
                    return;
                }
            } else {
                return;
            }
        } else if (strstr((const char * ) cmd, "+NOTIFY=")) {
            chr_buff = (uint8_t * ) strchr((const char * ) cmd, '=');
            if (chr_buff) {
                chr_buff++;
                c_len = strlen((const char * ) chr_buff);
                if (c_len == 32) {
                    if (parse_uuid_string((const char * ) chr_buff, fc_hw_flag.characteristic_notify_uuid)) {
                        unsigned int flash_addr = tlkcfg_getFlashAddr(TLK_CFG_FLASH_USER_DATA_ADDR);
                        if (flash_addr != 0) {
                            flash_erase_sector(flash_addr);
                            flash_write_page(flash_addr, sizeof(flag_typedef_t), (uint08 * ) & fc_hw_flag);
                            notify_cmd_ok();
                        } else {
                            notify_cmd_error();
                        }
                        return;
                    } else {
                        notify_cmd_error();
                        return;
                    }
                } else {
                    notify_cmd_error();
                    return;
                }
            } else {
                return;
            }
        } else if (strstr((const char * ) cmd, "+WRITE=")) {

            chr_buff = (uint8_t * ) strchr((const char * ) cmd, '=');
            if (chr_buff) {
                chr_buff++;
                c_len = strlen((const char * ) chr_buff);
                if (c_len == 32) {
                    if (parse_uuid_string((const char * ) chr_buff, fc_hw_flag.characteristic_write_uuid)) {
                        unsigned int flash_addr = tlkcfg_getFlashAddr(TLK_CFG_FLASH_USER_DATA_ADDR);
                        if (flash_addr != 0) {
                            flash_erase_sector(flash_addr);
                            flash_write_page(flash_addr, sizeof(flag_typedef_t), (uint08 * ) & fc_hw_flag);
                            notify_cmd_ok();
                        } else {
                            notify_cmd_error();
                        }
                        return;
                    } else {
                        notify_cmd_error();
                        return;
                    }
                } else {
                    notify_cmd_error();
                    return;
                }
            } else {
                return;
            }
        } else if (strstr((const char * ) cmd, "+RESET=1") != NULL) { //RESET
            core_reboot();
        } else if (strstr((const char * ) cmd, "+FLASH_ERASE=1") != NULL) { //FLASH ERASE
            notify_cmd_ok();
            flash_erase_chip();
            flash_erase_chip_ram();
            tlkmmi_sys_restoreFactorySettings();
        }
        /********************************************CHECKING AT CMDS*******************************************/
        else if ((strstr((const char * ) cmd, "+MAC?") != NULL)) {
            uint08 * dev_addr = (uint08 * ) tlkmmi_btmgr_getAddr();
            memcpy(bt_addr, dev_addr, 6);
            print_mac_address();
        } else if ((strstr((const char * ) cmd, "+LEMAC?") != NULL)) {
            uint08 * dev_addr = (uint08 * ) tlkmmi_lemgr_getAddr();
            memcpy(ble_addr, dev_addr, 6);
            print_lemac_address();
        } else if ((strstr((const char * ) cmd, "+DNAME?") != NULL)) {
            uint08 * dev_name;
            dev_name = (uint08 * ) tlkmmi_btmgr_getName();
            uart_send(UART1, "+DNAME=", 7);
            uart_send(UART1, dev_name, strlen(dev_name));
            uart_send(UART1, "\r\n", 2);
        } else if ((strstr((const char * ) cmd, "+LENAME?") != NULL)) {
            uint08 * dev_name;
            dev_name = tlkmmi_lemgr_getName();
            uart_send(UART1, "+LENAME=", 8);
            uart_send(UART1, dev_name, strlen(dev_name));
            uart_send(UART1, "\r\n", 2);
        } else if ((strstr((const char * ) cmd, "+PINE?") != NULL)) {
            uart_send(UART1, "+PINE=", 6);
            if (fc_hw_flag.pin_en_flag) {
                uart_send(UART1, "ENABLED\r\n", 9);
            } else {
                uart_send(UART1, "DISABLED\r\n", 10);
            }
        } else if (strstr((const char * ) cmd, "+VER?") != NULL) {
            uart_send(UART1, release_version, strlen(release_version));
            uart_send(UART1, "\r\n", 2);
        } else if (strstr((const char * ) cmd, "+PIN?") != NULL) {
            uart_send(UART1, "PIN=", fc_hw_flag.pinlen);
            uart_send(UART1, fc_hw_flag.pincode, fc_hw_flag.pinlen);
            uart_send(UART1, "\r\n", 2);
        } else if (strstr((const char * ) cmd, "+FC?") != NULL) {
            if (fc_hw_flag.hw_flow_ctrl_flg) {
                uart_send(UART1, "ENABLE\r\n", 8);
            } else {
                uart_send(UART1, "DISABLE\r\n", 9);
            }
        } else if (strstr((const char * ) cmd, "+SERV?") != NULL) {
            uart_send(UART1, "+SERV=", 6);
            for (int i = 0; i < 16; i++) {
                char hex_byte[3];
                sprintf(hex_byte, "%02x", fc_hw_flag.service_uuid[i]);
                uart_send(UART1, (uint08 * ) hex_byte, 2);
            }
            uart_send(UART1, "\r\n", 2);
        } else if (strstr((const char * ) cmd, "+NOTIFY?") != NULL) {
            uart_send(UART1, "+NOTIFY=", 8);
            for (int i = 0; i < 16; i++) {
                char hex_byte[3];
                sprintf(hex_byte, "%02x", fc_hw_flag.characteristic_notify_uuid[i]);
                uart_send(UART1, (uint08 * ) hex_byte, 2);
            }
            uart_send(UART1, "\r\n", 2);
        } else if (strstr((const char * ) cmd, "+WRITE?") != NULL) {
            uart_send(UART1, "+WRITE=", 7);
            for (int i = 0; i < 16; i++) {
                char hex_byte[3];
                sprintf(hex_byte, "%02x", fc_hw_flag.characteristic_write_uuid[i]);
                uart_send(UART1, (uint08 * ) hex_byte, 2);
            }
            uart_send(UART1, "\r\n", 2);
        } else if (strstr((const char * ) cmd, "+URATE?") != NULL) {
            uint32 checkbaud = tlkcfg_getSerialBaudrate();
            char response[32];
            sprintf(response, "BAUD:%lu\r\n", checkbaud);
            uart_send(UART1, (uint8_t * ) response, strlen(response));
        } else {
            uart_send(UART1, "NOT AT COMMAND\r\n", 15);
        }
    } else {
        uart_send(UART1, "ERR\r\n", 5);
    }

}

void serial_rx_handler(void) {
    if (!uart_rx_flg) return;
    else {
        core_disable_interrupt();
        if (btc_conn_flag && idx > 0) {
            btp_spp_sendData(g_aclHandle, nullptr, 0, at_cmd_buffer, idx);
        } else if (blec_conn_flag && g_connHandle != 0 && idx > 0) {
            blc_gatt_pushHandleValueNotify(g_connHandle, SPP_SERVER_TO_CLIENT_DP_H, (void * ) at_cmd_buffer, idx);
        } else {
            int clean_idx = idx;
            while (clean_idx > 0 && (at_cmd_buffer[clean_idx - 1] == 0x0D || at_cmd_buffer[clean_idx - 1] == 0x0A)) {
                clean_idx--;
            }
            at_cmd_buffer[clean_idx] = '\0';
            process_at_cmd(at_cmd_buffer);
        }
        idx = 0;
        uart_rx_flg = 0;
        memset(at_cmd_buffer, 0, 128);
        core_enable_interrupt();
    }
}

volatile uint08 uart_busy_flag = 0; //0 none, 1 spp , 2 spp, 3 ble
volatile uint32_t last_sent_tick = 0; //time SPP sent data
#define DATA_DELAY_SWITCH 500000 //500ms delay for switching buffers

static void send_data_to_uart(ringbuffer_t * data_buffer, bool is_spp) {
    uint08 p_data;
    if (fc_hw_flag.hw_flow_ctrl_flg) { //HW FLOW
        uart_set_cts_en(UART1);
        while (!rb_is_empty(data_buffer)) {
            if (rb_pop(data_buffer, & p_data)) {
                uart_send_byte(UART1, p_data);
                last_sent_tick = clock_time();
            }
        }
        if (rb_count(data_buffer) < RX_TX_FIFO_SIZE / 2 && is_spp) {
            tlkbt_hci_setC2hSppFlowCtrl(0);
        }
        //		if(rb_is_empty(data_buffer))uart_set_cts_dis(UART1); //No flow control
        if (rb_is_empty( & spp_rb_rx_1) && rb_is_empty( & spp_rb_rx_2)) {
            uart_set_cts_dis(UART1);
        }

    } else {
        while (!rb_is_empty(data_buffer)) {
            if (rb_pop(data_buffer, & p_data)) {
                uart_send_byte(UART1, p_data);
                last_sent_tick = clock_time();
            }
        }
        if (rb_count(data_buffer) < RX_TX_FIFO_SIZE / 2 && is_spp) {
            tlkbt_hci_setC2hSppFlowCtrl(0);
            gpio_set_low_level(GPIO_PB4);
        }
    }
}

void process_bt_handler() {
    if (rb_is_empty( & spp_rb_rx_1) && rb_is_empty( & ble_rb_rx) && rb_is_empty( & spp_rb_rx_2)) return;
    if (uart_busy_flag == 0) {
        if (btc_conn_flag && !rb_is_empty( & spp_rb_rx_1)) uart_busy_flag = 1;
        else if (btc_conn_flag && !rb_is_empty( & spp_rb_rx_2)) uart_busy_flag = 2;
        else if (blec_conn_flag && !rb_is_empty( & ble_rb_rx)) uart_busy_flag = 3;
    }

    if (uart_busy_flag == 1) {
        send_data_to_uart( & spp_rb_rx_1, true); // SPP 1
        if (rb_is_empty( & spp_rb_rx_1) && clock_time_exceed(last_sent_tick, DATA_DELAY_SWITCH)) {
            uart_busy_flag = 0;
        }
        return;
    }
    if (uart_busy_flag == 2) {
        send_data_to_uart( & spp_rb_rx_2, true); // SPP 2
        if (rb_is_empty( & spp_rb_rx_2) && clock_time_exceed(last_sent_tick, DATA_DELAY_SWITCH)) {
            uart_busy_flag = 0;
        }
        return;
    } else if (uart_busy_flag == 3) {
        send_data_to_uart( & ble_rb_rx, false); // BLE
        if (rb_is_empty( & ble_rb_rx) && clock_time_exceed(last_sent_tick, DATA_DELAY_SWITCH)) {
            uart_busy_flag = 0;
        }
        return;
    }
}

void main_loop() {
    process_bt_handler();
    serial_rx_handler();
    btble_conn_on_off();
}
