/*  play.c
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
#include "cortex-m3.h"
#include "stm32-uart.h"
#include "nvic.h"

/* Let's have something in .data and .bss to check that the linker script is working
*/
volatile unsigned initialized_array[4] = { 0xf00, 0xbaa, 0xba2, 0xb10b };
volatile unsigned char floom = 42u;

volatile unsigned uninitialized_array[8];
volatile int delay_factor;

extern unsigned dv_start_data, dv_end_data, dv_start_bss, dv_end_bss, dv_idata;

void pass(void);
void fail(void);
void dv_init_data(void);
void init_led(void);
void led_on(void);
void led_off(void);
void delay(int);
void dv_init_rcc();
void play_putc(int);
void dv_irq_ext0(void);
void putstr(char *);

/* Entry point
*/
void dv_reset(void)
{
	dv_init_rcc();
	dv_init_data();

/*	Copy the initialised array to the uninitialised array (twice)
 * 	This is a test (kind of) that the .data/.bss initialisation has worked.
*/
	for ( int i = 0; i < 8; i++ )
	{
		uninitialized_array[i] = initialized_array[i % 4];
	}

	if ( floom == 42 )
		pass();
	else
		fail();

	dv_nvic_init();

	if ( dv_uart1_init(115200, "8N1") != 0 )
		fail();

	dv_nvic_setprio(0, 12);
	dv_nvic_enableirq(0);

	init_led();
	led_off();
	delay_factor = 800;

	for (;;)
	{
		play_putc('*');
		led_on();
		delay(50);
		led_off();
		delay(2000-50);
	}
}

void pass(void)
{
	floom = 66u;
}

void fail(void)
{
	floom = 99u;
}

/*	Initialise the .data and .bss sections
*/
void dv_init_data(void)
{
	unsigned *s = &dv_idata;
	unsigned *d = &dv_start_data;

	while ( d < &dv_end_data )
	{
		*d++ = *s++;
	}

	d = &dv_start_bss;
	while ( d < &dv_end_bss )
	{
		*d++ = 0x00;
	}
}

void putstr(char *s)
{
	while ( *s != '\0' )
	{
		play_putc(*s++);
	}
}

void dv_irq_ext0(void)
{
	putstr("dv_irq_ext0()\n");
}

/* Below this line are stub functions to satisfy the vector addresses
*/
void dv_nmi(void)
{
	putstr("dv_nmi()\n");
	for (;;)	{ }
}

void dv_hardfault(void)
{
	putstr("dv_hardfault()\n");
	for (;;)	{ }
}

void dv_memfault(void)
{
	putstr("dv_memfault()\n");
	for (;;)	{ }
}

void dv_busfault(void)
{
	putstr("dv_busfault()\n");
	for (;;)	{ }
}

void dv_usagefault(void)
{
	putstr("dv_usagefault()\n");
	for (;;)	{ }
}

void dv_svctrap(void)
{
	putstr("dv_svctrap()\n");
	for (;;)	{ }
}

void dv_pendsvtrap(void)
{
	putstr("dv_pendsvtrap()\n");
}

void dv_systickirq(void)
{
	putstr("dv_systickirq()\n");
	for (;;)	{ }
}

void dv_irq(void)
{
	putstr("dv_irq()\n");
	for (;;)	{ }
}

void dv_unknowntrap(void)
{
	putstr("dv_unknowntrap()\n");
	for (;;)	{ }
}

