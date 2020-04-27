
#include "stm32.h"

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

/* Entry point
*/
void dv_reset(void)
{
	dv_init_rcc();
	dv_init_data();

/*	Copy the initialised array to the uninitialised array (twice)
*/
	for ( int i = 0; i < 8; i++ )
	{
		uninitialized_array[i] = initialized_array[i % 4];
	}

	if ( floom == 42 )
		pass();
	else
		fail();

	init_led();
	led_off();
	delay_factor = 800;

	for (;;)
	{
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

/* Below this line are stub functions to satisfy the vector addresses
*/
void dv_nmi(void)
{
	for (;;)	{ }
}

void dv_hardfault(void)
{
	for (;;)	{ }
}

void dv_memfault(void)
{
	for (;;)	{ }
}

void dv_busfault(void)
{
	for (;;)	{ }
}

void dv_usagefault(void)
{
	for (;;)	{ }
}

void dv_svctrap(void)
{
	for (;;)	{ }
}

void dv_pendsvtrap(void)
{
	for (;;)	{ }
}

void dv_systickirq(void)
{
	for (;;)	{ }
}

void dv_irq(void)
{
	for (;;)	{ }
}

void dv_unknowntrap(void)
{
	for (;;)	{ }
}
