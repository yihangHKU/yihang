/************************************************************************************
 * arch/arm/src/stm32/stm32f0_uart.h
 *
 *   Copyright (C) 2017 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *           Alan Carvalho de Assis <acassis@gmail.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************/

#ifndef __ARCH_ARM_STC_STM32F0_STM32F0_UART_H
#define __ARCH_ARM_STC_STM32F0_STM32F0_UART_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

#include "chip.h"

#include "chip/stm32f0_uart.h"

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/
/* Make sure that we have not enabled more U[S]ARTs than are supported by the
 * device.
 */

#if STM32F0_NUSART < 8 || !defined(CONFIG_STM32F0_HAVE_USART8)
#  undef CONFIG_STM32F0_USART8
#endif
#if STM32F0_NUSART < 7 || !defined(CONFIG_STM32F0_HAVE_USART7)
#  undef CONFIG_STM32F0_USART7
#endif
#if STM32F0_NUSART < 6 || !defined(CONFIG_STM32F0_HAVE_USART6)
#  undef CONFIG_STM32F0_USART6
#endif
#if STM32F0_NUSART < 5 || !defined(CONFIG_STM32F0_HAVE_USART5)
#  undef CONFIG_STM32F0_USART5
#endif
#if STM32F0_NUSART < 4 || !defined(CONFIG_STM32F0_HAVE_USART4)
#  undef CONFIG_STM32F0_USART4
#endif
#if STM32F0_NUSART < 3 || !defined(CONFIG_STM32F0_HAVE_USART3)
#  undef CONFIG_STM32F0_USART3
#endif
#if STM32F0_NUSART < 2
#  undef CONFIG_STM32F0_USART2
#endif
#if STM32F0_NUSART < 1
#  undef CONFIG_STM32F0_USART1
#endif

/* USART 3-8 are multiplexed to the same interrupt.  Current interrupt
 * handling logic will support only one USART in that range.  That is
 * not an issue for currently supported chips but could become an
 * issue in the future.
 */

#if defined(CONFIG_STM32F0_USART3)
#  undef CONFIG_STM32F0_USART4
#  undef CONFIG_STM32F0_USART5
#  undef CONFIG_STM32F0_USART6
#  undef CONFIG_STM32F0_USART7
#  undef CONFIG_STM32F0_USART8
#elif defined(CONFIG_STM32F0_USART4)
#  undef CONFIG_STM32F0_USART5
#  undef CONFIG_STM32F0_USART6
#  undef CONFIG_STM32F0_USART7
#  undef CONFIG_STM32F0_USART8
#elif defined(CONFIG_STM32F0_USART5)
#  undef CONFIG_STM32F0_USART6
#  undef CONFIG_STM32F0_USART7
#  undef CONFIG_STM32F0_USART8
#elif defined(CONFIG_STM32F0_USART6)
#  undef CONFIG_STM32F0_USART7
#  undef CONFIG_STM32F0_USART8
#elif defined(CONFIG_STM32F0_USART7)
#  undef CONFIG_STM32F0_USART8
#endif

/* Is there a USART enabled? */

#if defined(CONFIG_STM32F0_USART1) || defined(CONFIG_STM32F0_USART2) || \
    defined(CONFIG_STM32F0_USART3) || defined(CONFIG_STM32F0_USART4) || \
    defined(CONFIG_STM32F0_USART5) || defined(CONFIG_STM32F0_USART6) || \
    defined(CONFIG_STM32F0_USART7) || defined(CONFIG_STM32F0_USART8)
#  define HAVE_USART 1
#endif

/* Sanity checks */

#if !defined(CONFIG_STM32F0_USART1)
#  undef CONFIG_STM32F0_USART1_SERIALDRIVER
#  undef CONFIG_STM32F0_USART1_1WIREDRIVER
#endif
#if !defined(CONFIG_STM32F0_USART2)
#  undef CONFIG_STM32F0_USART2_SERIALDRIVER
#  undef CONFIG_STM32F0_USART2_1WIREDRIVER
#endif
#if !defined(CONFIG_STM32F0_USART3)
#  undef CONFIG_STM32F0_USART3_SERIALDRIVER
#  undef CONFIG_STM32F0_USART3_1WIREDRIVER
#endif
#if !defined(CONFIG_STM32F0_USART4)
#  undef CONFIG_STM32F0_USART4_SERIALDRIVER
#  undef CONFIG_STM32F0_USART4_1WIREDRIVER
#endif
#if !defined(CONFIG_STM32F0_USART5)
#  undef CONFIG_STM32F0_USART5_SERIALDRIVER
#  undef CONFIG_STM32F0_USART5_1WIREDRIVER
#endif
#if !defined(CONFIG_STM32F0_USART6)
#  undef CONFIG_STM32F0_USART6_SERIALDRIVER
#  undef CONFIG_STM32F0_USART6_1WIREDRIVER
#endif
#if !defined(CONFIG_STM32F0_USART7)
#  undef CONFIG_STM32F0_USART7_SERIALDRIVER
#  undef CONFIG_STM32F0_USART7_1WIREDRIVER
#endif
#if !defined(CONFIG_STM32F0_USART8)
#  undef CONFIG_STM32F0_USART8_SERIALDRIVER
#  undef CONFIG_STM32F0_USART8_1WIREDRIVER
#endif

/* Check 1-Wire and U(S)ART conflicts */

#if defined(CONFIG_STM32F0_USART1_1WIREDRIVER) && defined(CONFIG_STM32F0_USART1_SERIALDRIVER)
#  error Both CONFIG_STM32F0_USART1_1WIREDRIVER and CONFIG_STM32F0_USART1_SERIALDRIVER defined
#  undef CONFIG_STM32F0_USART1_1WIREDRIVER
#endif
#if defined(CONFIG_STM32F0_USART2_1WIREDRIVER) && defined(CONFIG_STM32F0_USART2_SERIALDRIVER)
#  error Both CONFIG_STM32F0_USART2_1WIREDRIVER and CONFIG_STM32F0_USART2_SERIALDRIVER defined
#  undef CONFIG_STM32F0_USART2_1WIREDRIVER
#endif
#if defined(CONFIG_STM32F0_USART3_1WIREDRIVER) && defined(CONFIG_STM32F0_USART3_SERIALDRIVER)
#  error Both CONFIG_STM32F0_USART3_1WIREDRIVER and CONFIG_STM32F0_USART3_SERIALDRIVER defined
#  undef CONFIG_STM32F0_USART3_1WIREDRIVER
#endif
#if defined(CONFIG_STM32F0_USART4_1WIREDRIVER) && defined(CONFIG_STM32F0_USART4_SERIALDRIVER)
#  error Both CONFIG_STM32F0_USART4_1WIREDRIVER and CONFIG_STM32F0_USART4_SERIALDRIVER defined
#  undef CONFIG_STM32F0_USART4_1WIREDRIVER
#endif
#if defined(CONFIG_STM32F0_USART5_1WIREDRIVER) && defined(CONFIG_STM32F0_USART5_SERIALDRIVER)
#  error Both CONFIG_STM32F0_USART5_1WIREDRIVER and CONFIG_STM32F0_USART5_SERIALDRIVER defined
#  undef CONFIG_STM32F0_USART5_1WIREDRIVER
#endif
#if defined(CONFIG_STM32F0_USART6_1WIREDRIVER) && defined(CONFIG_STM32F0_USART6_SERIALDRIVER)
#  error Both CONFIG_STM32F0_USART6_1WIREDRIVER and CONFIG_STM32F0_USART6_SERIALDRIVER defined
#  undef CONFIG_STM32F0_USART6_1WIREDRIVER
#endif
#if defined(CONFIG_STM32F0_USART7_1WIREDRIVER) && defined(CONFIG_STM32F0_USART7_SERIALDRIVER)
#  error Both CONFIG_STM32F0_USART7_1WIREDRIVER and CONFIG_STM32F0_USART7_SERIALDRIVER defined
#  undef CONFIG_STM32F0_USART7_1WIREDRIVER
#endif
#if defined(CONFIG_STM32F0_USART8_1WIREDRIVER) && defined(CONFIG_STM32F0_USART8_SERIALDRIVER)
#  error Both CONFIG_STM32F0_USART8_1WIREDRIVER and CONFIG_STM32F0_USART8_SERIALDRIVER defined
#  undef CONFIG_STM32F0_USART8_1WIREDRIVER
#endif

/* Is the serial driver enabled? */

#if defined(CONFIG_STM32F0_USART1_SERIALDRIVER) || defined(CONFIG_STM32F0_USART2_SERIALDRIVER) || \
    defined(CONFIG_STM32F0_USART3_SERIALDRIVER) || defined(CONFIG_STM32F0_USART4_SERIALDRIVER)  || \
    defined(CONFIG_STM32F0_USART5_SERIALDRIVER)  || defined(CONFIG_STM32F0_USART6_SERIALDRIVER) || \
    defined(CONFIG_STM32F0_USART7_SERIALDRIVER)  || defined(CONFIG_STM32F0_USART8_SERIALDRIVER)
#  define HAVE_SERIALDRIVER 1
#endif

/* Is the 1-Wire driver? */

#if defined(CONFIG_STM32F0_USART1_1WIREDRIVER) || defined(CONFIG_STM32F0_USART2_1WIREDRIVER) || \
    defined(CONFIG_STM32F0_USART3_1WIREDRIVER) || defined(CONFIG_STM32F0_USART4_1WIREDRIVER) || \
    defined(CONFIG_STM32F0_USART5_1WIREDRIVER) || defined(CONFIG_STM32F0_USART6_1WIREDRIVER) || \
    defined(CONFIG_STM32F0_USART7_1WIREDRIVER) || defined(CONFIG_STM32F0_USART8_1WIREDRIVER)
#  define HAVE_1WIREDRIVER 1
#endif

/* Is there a serial console? */

#if defined(CONFIG_USART1_SERIAL_CONSOLE) && defined(CONFIG_STM32F0_USART1_SERIALDRIVER)
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_USART4_SERIAL_CONSOLE
#  undef CONFIG_USART5_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_USART7_SERIAL_CONSOLE
#  undef CONFIG_USART8_SERIAL_CONSOLE
#  define CONSOLE_USART 1
#  define HAVE_CONSOLE 1
#elif defined(CONFIG_USART2_SERIAL_CONSOLE) && defined(CONFIG_STM32F0_USART2_SERIALDRIVER)
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_USART4_SERIAL_CONSOLE
#  undef CONFIG_USART5_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_USART7_SERIAL_CONSOLE
#  undef CONFIG_USART8_SERIAL_CONSOLE
#  define CONSOLE_USART 2
#  define HAVE_CONSOLE 1
#elif defined(CONFIG_USART3_SERIAL_CONSOLE) && defined(CONFIG_STM32F0_USART3_SERIALDRIVER)
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART4_SERIAL_CONSOLE
#  undef CONFIG_USART5_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_USART7_SERIAL_CONSOLE
#  undef CONFIG_USART8_SERIAL_CONSOLE
#  define CONSOLE_USART 3
#  define HAVE_CONSOLE 1
#elif defined(CONFIG_USART4_SERIAL_CONSOLE) && defined(CONFIG_STM32F0_USART4_SERIALDRIVER)
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_USART5_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_USART7_SERIAL_CONSOLE
#  undef CONFIG_USART8_SERIAL_CONSOLE
#  define CONSOLE_USART 4
#  define HAVE_CONSOLE 1
#elif defined(CONFIG_USART5_SERIAL_CONSOLE) && defined(CONFIG_STM32F0_USART5_SERIALDRIVER)
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_USART4_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_USART7_SERIAL_CONSOLE
#  undef CONFIG_USART8_SERIAL_CONSOLE
#  define CONSOLE_USART 5
#  define HAVE_CONSOLE 1
#elif defined(CONFIG_USART6_SERIAL_CONSOLE) && defined(CONFIG_STM32F0_USART6_SERIALDRIVER)
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_USART4_SERIAL_CONSOLE
#  undef CONFIG_USART5_SERIAL_CONSOLE
#  undef CONFIG_USART7_SERIAL_CONSOLE
#  undef CONFIG_USART8_SERIAL_CONSOLE
#  define CONSOLE_USART 6
#  define HAVE_CONSOLE 1
#elif defined(CONFIG_USART7_SERIAL_CONSOLE) && defined(CONFIG_STM32F0_USART7_SERIALDRIVER)
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_USART4_SERIAL_CONSOLE
#  undef CONFIG_USART5_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_USART5_SERIAL_CONSOLE
#  undef CONFIG_USART8_SERIAL_CONSOLE
#  define CONSOLE_USART 7
#  define HAVE_CONSOLE 1
#elif defined(CONFIG_USART8_SERIAL_CONSOLE) && defined(CONFIG_STM32F0_USART8_SERIALDRIVER)
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_USART4_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_USART7_SERIAL_CONSOLE
#  define CONSOLE_USART 8
#  define HAVE_CONSOLE 1
#else
#  undef CONFIG_USART1_SERIAL_CONSOLE
#  undef CONFIG_USART2_SERIAL_CONSOLE
#  undef CONFIG_USART3_SERIAL_CONSOLE
#  undef CONFIG_USART4_SERIAL_CONSOLE
#  undef CONFIG_USART5_SERIAL_CONSOLE
#  undef CONFIG_USART6_SERIAL_CONSOLE
#  undef CONFIG_USART7_SERIAL_CONSOLE
#  undef CONFIG_USART8_SERIAL_CONSOLE
#  define CONSOLE_USART 0
#  undef HAVE_CONSOLE
#endif

/* DMA support is only provided if CONFIG_ARCH_DMA is in the NuttX configuration */

#if !defined(HAVE_SERIALDRIVER) || !defined(CONFIG_ARCH_DMA)
#  undef CONFIG_USART1_RXDMA
#  undef CONFIG_USART2_RXDMA
#  undef CONFIG_USART3_RXDMA
#  undef CONFIG_USART4_RXDMA
#  undef CONFIG_USART5_RXDMA
#  undef CONFIG_USART6_RXDMA
#  undef CONFIG_USART7_RXDMA
#  undef CONFIG_USART8_RXDMA
#endif

/* Disable the DMA configuration on all unused USARTs */

#ifndef CONFIG_STM32F0_USART1_SERIALDRIVER
#  undef CONFIG_USART1_RXDMA
#endif

#ifndef CONFIG_STM32F0_USART2_SERIALDRIVER
#  undef CONFIG_USART2_RXDMA
#endif

#ifndef CONFIG_STM32F0_USART3_SERIALDRIVER
#  undef CONFIG_USART3_RXDMA
#endif

#ifndef CONFIG_STM32F0_USART4_SERIALDRIVER
#  undef CONFIG_USART4_RXDMA
#endif

#ifndef CONFIG_STM32F0_USART5_SERIALDRIVER
#  undef CONFIG_USART5_RXDMA
#endif

#ifndef CONFIG_STM32F0_USART6_SERIALDRIVER
#  undef CONFIG_USART6_RXDMA
#endif

#ifndef CONFIG_STM32F0_USART7_SERIALDRIVER
#  undef CONFIG_USART7_RXDMA
#endif

#ifndef CONFIG_STM32F0_USART8_SERIALDRIVER
#  undef CONFIG_USART8_RXDMA
#endif

/* Is DMA available on any (enabled) USART? */

#undef SERIAL_HAVE_DMA
#if defined(CONFIG_USART1_RXDMA) || defined(CONFIG_USART2_RXDMA) || \
    defined(CONFIG_USART3_RXDMA) || defined(CONFIG_USART4_RXDMA)  || \
    defined(CONFIG_USART5_RXDMA)  || defined(CONFIG_USART6_RXDMA) || \
    defined(CONFIG_USART7_RXDMA)  || defined(CONFIG_USART8_RXDMA)
#  define SERIAL_HAVE_DMA 1
#endif

/* Is DMA used on the console USART? */

#undef SERIAL_HAVE_CONSOLE_DMA
#if defined(CONFIG_USART1_SERIAL_CONSOLE) && defined(CONFIG_USART1_RXDMA)
#  define SERIAL_HAVE_CONSOLE_DMA 1
#elif defined(CONFIG_USART2_SERIAL_CONSOLE) && defined(CONFIG_USART2_RXDMA)
#  define SERIAL_HAVE_CONSOLE_DMA 1
#elif defined(CONFIG_USART3_SERIAL_CONSOLE) && defined(CONFIG_USART3_RXDMA)
#  define SERIAL_HAVE_CONSOLE_DMA 1
#elif defined(CONFIG_USART4_SERIAL_CONSOLE) && defined(CONFIG_USART4_RXDMA)
#  define SERIAL_HAVE_CONSOLE_DMA 1
#elif defined(CONFIG_USART5_SERIAL_CONSOLE) && defined(CONFIG_USART5_RXDMA)
#  define SERIAL_HAVE_CONSOLE_DMA 1
#elif defined(CONFIG_USART6_SERIAL_CONSOLE) && defined(CONFIG_USART6_RXDMA)
#  define SERIAL_HAVE_CONSOLE_DMA 1
#elif defined(CONFIG_USART7_SERIAL_CONSOLE) && defined(CONFIG_USART7_RXDMA)
#  define SERIAL_HAVE_CONSOLE_DMA 1
#elif defined(CONFIG_USART8_SERIAL_CONSOLE) && defined(CONFIG_USART8_RXDMA)
#  define SERIAL_HAVE_CONSOLE_DMA 1
#endif

/* Is DMA used on all (enabled) USARTs */

#define SERIAL_HAVE_ONLY_DMA 1
#if defined(CONFIG_STM32F0_USART1_SERIALDRIVER) && !defined(CONFIG_USART1_RXDMA)
#  undef SERIAL_HAVE_ONLY_DMA
#elif defined(CONFIG_STM32F0_USART2_SERIALDRIVER) && !defined(CONFIG_USART2_RXDMA)
#  undef SERIAL_HAVE_ONLY_DMA
#elif defined(CONFIG_STM32F0_USART3_SERIALDRIVER) && !defined(CONFIG_USART3_RXDMA)
#  undef SERIAL_HAVE_ONLY_DMA
#elif defined(CONFIG_STM32F0_USART4_SERIALDRIVER) && !defined(CONFIG_USART4_RXDMA)
#  undef SERIAL_HAVE_ONLY_DMA
#elif defined(CONFIG_STM32F0_USART5_SERIALDRIVER) && !defined(CONFIG_USART5_RXDMA)
#  undef SERIAL_HAVE_ONLY_DMA
#elif defined(CONFIG_STM32F0_USART6_SERIALDRIVER) && !defined(CONFIG_USART6_RXDMA)
#  undef SERIAL_HAVE_ONLY_DMA
#elif defined(CONFIG_STM32F0_USART7_SERIALDRIVER) && !defined(CONFIG_USART7_RXDMA)
#  undef SERIAL_HAVE_ONLY_DMA
#elif defined(CONFIG_STM32F0_USART8_SERIALDRIVER) && !defined(CONFIG_USART8_RXDMA)
#  undef SERIAL_HAVE_ONLY_DMA
#endif

/* Is RS-485 used? */

#if defined(CONFIG_USART1_RS485) || defined(CONFIG_USART2_RS485) || \
    defined(CONFIG_USART3_RS485) || defined(CONFIG_USART4_RS485)  || \
    defined(CONFIG_USART5_RS485)  || defined(CONFIG_USART6_RS485)  || \
    defined(CONFIG_USART7_RS485)  || defined(CONFIG_USART8_RS485)
#  define HAVE_RS485 1
#endif

#ifdef HAVE_RS485
#  define USART_CR1_USED_INTS    (USART_CR1_RXNEIE | USART_CR1_TXEIE | USART_CR1_PEIE | USART_CR1_TCIE)
#else
#  define USART_CR1_USED_INTS    (USART_CR1_RXNEIE | USART_CR1_TXEIE | USART_CR1_PEIE)
#endif

/************************************************************************************
 * Public Types
 ************************************************************************************/

/************************************************************************************
 * Public Data
 ************************************************************************************/

#ifndef __ASSEMBLY__

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/************************************************************************************
 * Public Functions
 ************************************************************************************/

/************************************************************************************
 * Name: stm32f0_serial_dma_poll
 *
 * Description:
 *   Must be called periodically if any STM32 USART is configured for DMA.  The DMA
 *   callback is triggered for each fifo size/2 bytes, but this can result in some
 *   bytes being transferred but not collected if the incoming data is not a whole
 *   multiple of half the FIFO size.
 *
 *   May be safely called from either interrupt or thread context.
 *
 ************************************************************************************/

#ifdef SERIAL_HAVE_DMA
void stm32f0_serial_dma_poll(void);
#endif

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_ARM_STC_STM32F0_STM32F0_UART_H */
