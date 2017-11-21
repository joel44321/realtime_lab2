/*
 * uart.c
 *
 *  Created on: 21 Nov 2017
 *      Author: Joel
 */

#include "board.h"
#include "fsl_lpuart.h"
#include "pin_mux.h"

void init_uart()
{
	// Setup Pins and Clock
    BOARD_InitPins();
    BOARD_BootClockRUN();
	CLOCK_SetLpuartClock(0x1U);

	// Configure UART
	lpuart_config_t lpuart_config;
	LPUART_GetDefaultConfig(&lpuart_config);
	lpuart_config.baudRate_Bps = 115200U;
	lpuart_config.enableTx = true;
	lpuart_config.enableRx = true;
	LPUART_Init(LPUART0, &lpuart_config, CLOCK_GetFreq(kCLOCK_CoreSysClk));
}

void put_char(char ch)
{
    LPUART_WriteBlocking(LPUART0, &ch, 1);
}

uint8_t get_char()
{
	uint8_t ch;
    LPUART_ReadBlocking(LPUART0, &ch, 1);

    return ch;
}
