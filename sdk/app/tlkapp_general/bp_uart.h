/*
 * bp_uart.h
 *
 *  Created on: 12-Jul-2025
 *      Author: saurabh
 */

#ifndef APP_TLKAPP_GENERAL_BP_UART_H_
#define APP_TLKAPP_GENERAL_BP_UART_H_

#include "types.h"
#include <stdbool.h>
#define RX_TX_FIFO_SIZE 4096
#define RTS_THRESHOLD (RX_TX_FIFO_SIZE * 3 / 4)
#define RTS_THRESHOLD_BLE (RX_TX_FIFO_SIZE * 3 / 4)
//volatile uint16_t head = 0, tail = 0;
typedef struct {
    volatile char buffer[RX_TX_FIFO_SIZE];
    volatile uint16_t head;
    volatile uint16_t tail;
//    uint32 count;
}
ringbuffer_t;

 int rb_init(ringbuffer_t * rb);
 bool rb_is_empty(ringbuffer_t * rb);
 bool rb_is_full(ringbuffer_t * rb);
 void rb_push(ringbuffer_t * rb, char c);
 bool rb_pop(ringbuffer_t * rb, uint08 * c) ;
 void uart_ringbuf_clear(ringbuffer_t * rb);
bool rb_buff_available(void) ;
 int rb_count(ringbuffer_t *rb);

 extern ringbuffer_t spp_rb_rx_1;
 extern ringbuffer_t ble_rb_rx;
 extern ringbuffer_t spp_rb_rx_2;
// inline uint8_t rb_is_full(ringbuffer_t *rb);
//char uart_read_char(void) ;

#endif /* APP_TLKAPP_GENERAL_BP_UART_H_ */
