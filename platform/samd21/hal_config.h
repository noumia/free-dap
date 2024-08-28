// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2024, Alex Taradov <alex@taradov.com>. All rights reserved.

#ifndef _HAL_CONFIG_H_
#define _HAL_CONFIG_H_

/*- Includes ----------------------------------------------------------------*/
#include "samd21.h"
#include "hal_gpio.h"

/*- Definitions -------------------------------------------------------------*/
#define HAL_BOARD_GENERIC

#if defined(XIAO_PINOUT)
/* XIAO

A0 A02 | 5V
A1 A04 | GND
A2 A10 | 3V3
A3 A11 | PA6 SWCLK
D4 PA8 | PA5 SWDIO
D5 PA9 | PA7 nRESET
TX PB8 | PB9 RX

PA18 RX_LED (DAP_STATUS)
PA19 TX_LED (VCP_STATUS)
*/

  #define HAL_CONFIG_ENABLE_VCP
  #define DAP_CONFIG_ENABLE_JTAG

  HAL_GPIO_PIN(SWCLK_TCK,          A, 6)
  HAL_GPIO_PIN(SWDIO_TMS,          A, 5)
  HAL_GPIO_PIN(TDI,                A, 10)
  HAL_GPIO_PIN(TDO,                A, 11)
  HAL_GPIO_PIN(nRESET,             A, 7)

  HAL_GPIO_PIN(VCP_STATUS,         A, 19);
  HAL_GPIO_PIN(DAP_STATUS,         A, 18);
  HAL_GPIO_PIN(BOOT_ENTER,         A, 2);

  HAL_GPIO_PIN(UART_TX,            B, 8);
  HAL_GPIO_PIN(UART_RX,            B, 9);

  #define UART_SERCOM              SERCOM4
  #define UART_SERCOM_PMUX         PORT_PMUX_PMUXE_D_Val
  #define UART_SERCOM_GCLK_ID      SERCOM4_GCLK_ID_CORE
  #define UART_SERCOM_APBCMASK     PM_APBCMASK_SERCOM4
  #define UART_SERCOM_IRQ_INDEX    SERCOM4_IRQn
  #define UART_SERCOM_IRQ_HANDLER  irq_handler_sercom4
  #define UART_SERCOM_TXPO         0 // PAD[0]
  #define UART_SERCOM_RXPO         1 // PAD[1]

#elif defined(QTPY_PINOUT)
/* QTPY

A0 PA02 | 5V
A1 PA03 | GND
A2 PA04 | 3V3
A3 PA05 | PA10 SWCLK
D4 PA16 | PA09 SWDIO
D5 PA17 | PA11 nRESET
TX PA06 | PA07 RX

*/

  #define HAL_CONFIG_ENABLE_VCP
  #define DAP_CONFIG_ENABLE_JTAG

  HAL_GPIO_PIN(SWCLK_TCK,          A, 10)
  HAL_GPIO_PIN(SWDIO_TMS,          A,  9)
  HAL_GPIO_PIN(TDI,                A,  4)
  HAL_GPIO_PIN(TDO,                A,  5)
  HAL_GPIO_PIN(nRESET,             A, 11)

  HAL_GPIO_PIN(VCP_STATUS,         A, 16)
  HAL_GPIO_PIN(DAP_STATUS,         A, 17)
  HAL_GPIO_PIN(BOOT_ENTER,         A, 2)

  HAL_GPIO_PIN(UART_TX,            A, 6)
  HAL_GPIO_PIN(UART_RX,            A, 7)

  #define UART_SERCOM              SERCOM0
  #define UART_SERCOM_PMUX         PORT_PMUX_PMUXE_D_Val
  #define UART_SERCOM_GCLK_ID      SERCOM0_GCLK_ID_CORE
  #define UART_SERCOM_APBCMASK     PM_APBCMASK_SERCOM0
  #define UART_SERCOM_IRQ_INDEX    SERCOM0_IRQn
  #define UART_SERCOM_IRQ_HANDLER  irq_handler_sercom0
  #define UART_SERCOM_TXPO         2 // PAD[2]
  #define UART_SERCOM_RXPO         3 // PAD[3]

#elif defined(HAL_BOARD_CUSTOM)
  // Externally supplied board configuration takes precedence
  #include HAL_BOARD_CUSTOM

#elif defined(HAL_BOARD_GENERIC)
  #define HAL_CONFIG_ENABLE_VCP
  #define DAP_CONFIG_ENABLE_JTAG

  HAL_GPIO_PIN(SWCLK_TCK,          B, 0)
  HAL_GPIO_PIN(SWDIO_TMS,          B, 1)
  HAL_GPIO_PIN(TDI,                B, 2)
  HAL_GPIO_PIN(TDO,                B, 3)
  HAL_GPIO_PIN(nRESET,             B, 4)

  HAL_GPIO_PIN(VCP_STATUS,         A, 10);
  HAL_GPIO_PIN(DAP_STATUS,         B, 30);
  HAL_GPIO_PIN(BOOT_ENTER,         A, 31);

  HAL_GPIO_PIN(UART_TX,            A, 4);
  HAL_GPIO_PIN(UART_RX,            A, 5);

  #define UART_SERCOM              SERCOM0
  #define UART_SERCOM_PMUX         PORT_PMUX_PMUXE_D_Val
  #define UART_SERCOM_GCLK_ID      SERCOM0_GCLK_ID_CORE
  #define UART_SERCOM_APBCMASK     PM_APBCMASK_SERCOM0
  #define UART_SERCOM_IRQ_INDEX    SERCOM0_IRQn
  #define UART_SERCOM_IRQ_HANDLER  irq_handler_sercom0
  #define UART_SERCOM_TXPO         0 // PAD[0]
  #define UART_SERCOM_RXPO         1 // PAD[1]

#else
  #error No board defined
#endif

#endif // _HAL_CONFIG_H_

