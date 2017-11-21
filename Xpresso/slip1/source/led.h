/*
 * led.h
 *
 *  Created on: 21 Nov 2017
 *      Author: Joel
 */

#ifndef LED_H_
#define LED_H_

#define NUM_LEDS  (4)

int32_t LED_Initialize (void);
int32_t LED_On (uint32_t num);
int32_t LED_Off (uint32_t num);

#endif /* LED_H_ */
