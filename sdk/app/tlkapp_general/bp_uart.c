/*
 * bp_uart.c
 *
 *  Created on: 12-Jul-2025
 *      Author: saurabh
 */

#include "bp_uart.h"
#include "tlkdrv/B91/uart.h"
#include "clock.h"
#include "string.h"
#include "core/tlk_config.h"
#include <stdlib.h>
extern uint32 tlkcfg_getSerialBaudrate(void);

//functions for the ring buffer
int rb_init(ringbuffer_t *rb) {
	rb->head = 0;
	rb->tail = 0;
	return 1;
}

bool rb_is_empty(ringbuffer_t *rb) {
	return rb->head == rb->tail;
}

bool rb_is_full(ringbuffer_t *rb) {
	return ((rb->head + 1) % RX_TX_FIFO_SIZE) == rb->tail;
}

void rb_push(ringbuffer_t *rb, char c) {
	if (!rb_is_full(rb)) {
		rb->buffer[rb->head] = c;
		rb->head = (rb->head + 1) % RX_TX_FIFO_SIZE;
	}
}

bool rb_pop(ringbuffer_t *rb, uint08 *c) {
	if (!rb_is_empty(rb)) {
		*c = rb->buffer[rb->tail];
		rb->tail = (rb->tail + 1) % RX_TX_FIFO_SIZE;
		return true;
	}
	return false;
}

void uart_ringbuf_clear(ringbuffer_t *rb) {
	rb->head = 0;
	rb->tail = 0;
}

bool rb_buff_available(void) {
	return !rb_is_empty(&spp_rb_rx_1);
}

int rb_count(ringbuffer_t *rb) {
	if (rb->head >= rb->tail)
		return rb->head - rb->tail;
	else
		return RX_TX_FIFO_SIZE - (rb->tail - rb->head);
}

ringbuffer_t spp_rb_rx_1;
ringbuffer_t ble_rb_rx;
ringbuffer_t spp_rb_rx_2;

/*function that initialize the uart */

void usr_serial_init(void) {
	unsigned short div = 0;
	unsigned char bwpc = 0;
	/**********for bt conn/disconnect indication*************/
	gpio_function_en(GPIO_PB7);
	gpio_output_en(GPIO_PB7);
	gpio_input_dis(GPIO_PB7);
	uint32 baud_rate = tlkcfg_getSerialBaudrate(); //used to get the last used baudrate
	if (baud_rate == 0xFFFFFFFF) {
		baud_rate = 9600;
	}
	uart_reset(UART1);
	uart_clr_tx_index(UART1);
	uart_clr_rx_index(UART1);
	uart_set_pin(UART1_TX_PC6, UART1_RX_PC7);
	uart_cts_config(UART1, UART1_CTS_PC4, 0);  // Active LOW
	uart_cal_div_and_bwpc(baud_rate, sys_clk.pclk * 1000 * 1000, &div, &bwpc);
	uart_init(UART1, div, bwpc, UART_PARITY_NONE, UART_STOP_BIT_ONE);
	uart_set_cts_dis(UART1);
	uart_rx_irq_trig_level(UART1, 1);
	uart_set_irq_mask(UART1, UART_RX_IRQ_MASK | UART_ERR_IRQ_MASK);
	// plic_set_priority(IRQ19_UART1, IRQ_PRI_LEV3);
	plic_interrupt_enable(IRQ18_UART1);
	core_enable_interrupt();
	rb_init(&spp_rb_rx_1); //initialize buffer for spp 1
	rb_init(&spp_rb_rx_2); //initialize buffer for spp 2
	rb_init(&ble_rb_rx); //initialize ble buffer

}
