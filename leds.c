/*  leds.c
 *
 *  Copyright David Haworth
 *
 *  This file is part of the STM32 playground.
 *
 *  The STM32 playground is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  The STM32 playground is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the STM32 playground.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "stm32.h"
#include "stm32-gpio.h"
#include "stm32-rcc.h"

extern volatile int delay_factor;

void init_led(void);
void led_on(void);
void led_off(void);
void delay(int);

#define PIN	13

void init_led(void)
{
	/* Turn on GPIO C
	*/
	dv_rcc.apb2en |= DV_RCC_IOPC;

	/* Select output/open drain/50 MHz
	*/
	int cr = PIN / 8;
	int shift = (PIN % 8) * 4;
	dv_u32_t mask = 0xf << shift;
	dv_u32_t val = DV_GPIO_OUT_OD_50 << shift;
	dv_gpio_c.cr[cr] = (dv_gpio_c.cr[cr] & mask) | val;
}

void led_off(void)
{
	dv_gpio_c.bsrr = 0x1 << PIN;
}

void led_on(void)
{
	dv_gpio_c.brr = 0x1 << PIN;
}

void delay(int ms)
{
	volatile int count = ms * delay_factor;

	do {
		count--;
	} while ( count > 0 );
}
