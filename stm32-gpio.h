/* stm32-gpio.h
*/
#ifndef STM32_GPIO_H
#define STM32_GPIO_H

#include "stm32.h"

/* ===== GPIO ===== */

typedef struct dv_gpio_s dv_gpio_t;

struct dv_gpio_s
{
	dv_reg32_t cr[2];		/* Control registers - 4 bits per pin; pins 0..7 in cr[0], pins 8..15 in cr[1] */
	dv_reg32_t idr;			/* Input data */
	dv_reg32_t odr;			/* Output data */
	dv_reg32_t bsrr;		/* Bit set/reset - write 1 to set or clear pin; upper half is clear, lower half set */
	dv_reg32_t brr;			/* Bit reset - write 1 to clear pin */
	dv_reg32_t lock;		/* Configuration lock */
};

#define DV_GPIO_BASE		0x40010800

#define DV_GPIOA_BASE		(DV_GPIO_BASE + 0x0000)
#define DV_GPIOB_BASE		(DV_GPIO_BASE + 0x0400)
#define DV_GPIOC_BASE		(DV_GPIO_BASE + 0x0800)
#define DV_GPIOD_BASE		(DV_GPIO_BASE + 0x0c00)
#define DV_GPIOE_BASE		(DV_GPIO_BASE + 0x1000)
#define DV_GPIOF_BASE		(DV_GPIO_BASE + 0x1400)
#define DV_GPIOG_BASE		(DV_GPIO_BASE + 0x1800)

#define dv_gpio_a			((dv_gpio_t *)DV_GPIOA_BASE)[0]
#define dv_gpio_b			((dv_gpio_t *)DV_GPIOB_BASE)[0]
#define dv_gpio_c			((dv_gpio_t *)DV_GPIOC_BASE)[0]

#define DV_GPIO_IN_ANALOG	(0x0 | 0x0)
#define DV_GPIO_IN_FLOAT	(0x4 | 0x0)
#define DV_GPIO_IN_PUD		(0x8 | 0x0)		/* Pullup/pulldown selected by setting odr bit to 1/0 */
#define DV_GPIO_IN_RES		(0xc | 0x0)		/* Reserved; don't use */

#define DV_GPIO_OUT_PP_10	(0x0 | 0x1)
#define DV_GPIO_OUT_OD_10	(0x4 | 0x1)
#define DV_GPIO_ALT_PP_10	(0x8 | 0x1)
#define DV_GPIO_ALT_OD_10	(0xc | 0x1)

#define DV_GPIO_OUT_PP_2	(0x0 | 0x2)
#define DV_GPIO_OUT_OD_2	(0x4 | 0x2)
#define DV_GPIO_ALT_PP_2	(0x8 | 0x2)
#define DV_GPIO_ALT_OD_2	(0xc | 0x2)

#define DV_GPIO_OUT_PP_50	(0x0 | 0x3)
#define DV_GPIO_OUT_OD_50	(0x4 | 0x3)
#define DV_GPIO_ALT_PP_50	(0x8 | 0x3)
#define DV_GPIO_ALT_OD_50	(0xc | 0x3)

#endif
