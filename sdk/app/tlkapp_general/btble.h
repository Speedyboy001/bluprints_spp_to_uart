/*
 * btble.h
 *
 *  Created on: 12-Jul-2025
 *      Author: saurabh
 */

#ifndef BTBLE_H_
#define BTBLE_H_

#include "types.h"

// Connection flags
extern volatile bool btc_conn_flag;
extern volatile bool blec_conn_flag;
extern uint16 g_aclHandle;
extern uint08 g_rfcHandle;


#endif /* BTBLE_H_ */
