
#include "stm32.h"
#include "stm32-rcc.h"

void dv_init_rcc(void)
{
#if 1
	/* Set up the PLL config
	*/
	dv_rcc.cfg = DV_RCC_PLLSRC		/* PLLSRC = 1 --> HSE */
				 | (0x7<<18)		/* PLLMUL = 7 --> Multiply by 9 */
				 | 0x0				/* SW = 0     --> System clock = HSI */
				 | (0x4<<8);		/* PPRE1 = 4  --> APB1 = SYSCLK/2 */

	dv_rcc.cc = DV_RCC_HSION		/* HSI on */
				| DV_RCC_HSEON		/* HSE ON */
				| (0x10<<3)			/* HSITRIM = 16 --> 8 MHz +/- 1% */
				| DV_RCC_PLLON;

	/* Wait for lock
	*/
	do {
		asm("nop");
	} while ( (dv_rcc.cc & DV_RCC_PLLRDY ) == 0 );

	/* 2 wait states on flash; enable prefetch
	*/
	dv_flash.ac = DV_FLASH_PREFETCH | 0x2;		/* 2 wait states, prefetch */

	/* Switch to PLL
	*/
	dv_rcc.cfg = DV_RCC_PLLSRC		/* PLLSRC = 1 --> HSE */
				 | (0x7<<18)		/* PLLMUL = 7 --> Multiply by 9 */
				 | 0x2				/* SW = 2     --> System clock = PLL */
				 | (0x4<<8);		/* PPRE1 = 4  --> APB1 = SYSCLK/2 */
#endif
}
