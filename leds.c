
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
