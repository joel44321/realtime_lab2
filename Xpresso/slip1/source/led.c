/*
 * led.c
 *
 *  Created on: 21 Nov 2017
 *      Author: Joel
 */


#include <stdio.h>
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKW41Z4.h"
#include "led.h"
							/*   rgb_red,   rgb_blue,  rgb_green,        red */
const uint32_t led_pin[]  = {         1,         18,         19,          0};
const uint32_t led_port[] = {PORTC_BASE, PORTA_BASE, PORTA_BASE, PORTB_BASE};
const uint32_t led_gpio[] = {GPIOC_BASE, GPIOA_BASE, GPIOA_BASE, GPIOB_BASE};

// Initialise LEDs
int32_t LED_Initialize (void) {
  uint32_t i;

  SIM->SCGC5 |= ((1U << SIM_SCGC5_PORTA_SHIFT) |
                 (1U << SIM_SCGC5_PORTB_SHIFT) |
                 (1U << SIM_SCGC5_PORTC_SHIFT)  );

  /* Port Initialization */
  for (i = 0; i < NUM_LEDS; i++) {
    ((PORT_Type *)led_port[i])->PCR[led_pin[i]] = (1U << 8);
    ((PORT_Type *)led_port[i])->ISFR           &= (1U << led_pin[i]);
  }

  /* GPIO Initialization */
  for (i = 0; i < NUM_LEDS; i++) {
    ((GPIO_Type *)led_gpio[i])->PDOR           |=  (1U << led_pin[i]);
    ((GPIO_Type *)led_gpio[i])->PDDR           |=  (1U << led_pin[i]);
  }

  return 0;
}

// Turn LED num on
int32_t LED_On (uint32_t num) {

  if (num < NUM_LEDS) {
    ((GPIO_Type *)led_gpio[num])->PCOR  =  (1U << led_pin[num]);
  }

  return 0;
}

// Turn LED num off
int32_t LED_Off (uint32_t num) {

  if (num < NUM_LEDS) {
    ((GPIO_Type *)led_gpio[num])->PSOR  =  (1U << led_pin[num]);
  }

  return 0;
}
