// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2022, Alex Taradov <alex@taradov.com>. All rights reserved.

#ifndef _HAL_CONFIG_H_
#define _HAL_CONFIG_H_

/*- Includes ----------------------------------------------------------------*/
#include "hal_gpio.h"

/*- Definitions -------------------------------------------------------------*/
#ifdef XIAO_PINOUT
/* XIAO

A0 26 | 5V
A1 27 | GND
A2 28 | 3V3
A3 29 | 3 SWCLK
D4  6 | 4 SWDIO
D5  7 | 2 nRESET
TX  0 | 1 RX

*/
HAL_GPIO_PIN(SWCLK_TCK,      0,  3, sio_3 )
HAL_GPIO_PIN(SWDIO_TMS,      0,  4, sio_4 )
HAL_GPIO_PIN(TDI,            0, 28, sio_28)
HAL_GPIO_PIN(TDO,            0, 29, sio_29)
HAL_GPIO_PIN(nRESET,         0,  2, sio_2 )

HAL_GPIO_PIN(VCP_STATUS,     0, 17, sio_17)
HAL_GPIO_PIN(DAP_STATUS,     0, 25, sio_25)

HAL_GPIO_PIN(UART_TX,        0, 0, uart0_tx)
HAL_GPIO_PIN(UART_RX,        0, 1, uart0_rx)

#elif defined(ZERO_PINOUT)
/* ZERO

5V
GND
3V3
29 : SWCLK
28 : SWIO
27 : nRESET
26
15
14

0 : TX
1 : RX
2

*/
HAL_GPIO_PIN(SWCLK_TCK,      0, 29, sio_29)
HAL_GPIO_PIN(SWDIO_TMS,      0, 28, sio_28)
HAL_GPIO_PIN(TDI,            0, 15, sio_15)
HAL_GPIO_PIN(TDO,            0, 14, sio_14)
HAL_GPIO_PIN(nRESET,         0, 27, sio_27)

HAL_GPIO_PIN(VCP_STATUS,     0,  2, sio_2 )
HAL_GPIO_PIN(DAP_STATUS,     0, 26, sio_26)

HAL_GPIO_PIN(UART_TX,        0, 0, uart0_tx)
HAL_GPIO_PIN(UART_RX,        0, 1, uart0_rx)

#else
HAL_GPIO_PIN(SWCLK_TCK,      0, 11, sio_11)
HAL_GPIO_PIN(SWDIO_TMS,      0, 12, sio_12)
HAL_GPIO_PIN(TDI,            0, 13, sio_13)
HAL_GPIO_PIN(TDO,            0, 14, sio_14)
HAL_GPIO_PIN(nRESET,         0, 15, sio_15)

HAL_GPIO_PIN(VCP_STATUS,     0, 2, sio_2);
HAL_GPIO_PIN(DAP_STATUS,     0, 25, sio_25);

HAL_GPIO_PIN(UART_TX,        0, 0, uart0_tx)
HAL_GPIO_PIN(UART_RX,        0, 1, uart0_rx)

#endif

#define UART_PER             UART0
#define UART_RESET_MASK      RESETS_RESET_uart0_Msk
#define UART_IRQ_INDEX       UART0_IRQ_IRQn
#define UART_IRQ_HANDLER     irq_handler_uart0
#define UART_CLOCK           120000000

#endif // _HAL_CONFIG_H_


