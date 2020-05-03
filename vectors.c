/*  vectors.c - vector table for Cortex-M devices
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
extern unsigned dv_stacktop;
extern void dv_reset(void);
extern void dv_nmi(void);
extern void dv_hardfault(void);
extern void dv_memfault(void);
extern void dv_busfault(void);
extern void dv_usagefault(void);
extern void dv_svctrap(void);
extern void dv_pendsvtrap(void);
extern void dv_systickirq(void);
extern void dv_irq(void);
extern void dv_unknowntrap(void);

extern void dv_irq_ext0(void);

/* The vector table is an array of addresses.
 * This table has 84 vectors:
 *	- 16 are the armv7m exception/reset vectors (including reset SP)
 *	- 68 are for the NVIC interrupts. They are all mappped to dv_irq
*/
const unsigned vectors[] =
{	(unsigned)&dv_stacktop,
	(unsigned)&dv_reset,
	(unsigned)&dv_nmi,
	(unsigned)&dv_hardfault,
	(unsigned)&dv_memfault,
	(unsigned)&dv_busfault,
	(unsigned)&dv_usagefault,
	(unsigned)&dv_unknowntrap,
	(unsigned)&dv_unknowntrap,
	(unsigned)&dv_unknowntrap,
	(unsigned)&dv_unknowntrap,
	(unsigned)&dv_svctrap,
	(unsigned)&dv_unknowntrap,
	(unsigned)&dv_unknowntrap,
	(unsigned)&dv_pendsvtrap,
	(unsigned)&dv_systickirq,
	(unsigned)&dv_irq_ext0,	/* 00 */
	(unsigned)&dv_irq,	/* 01 */
	(unsigned)&dv_irq,	/* 02 */
	(unsigned)&dv_irq,	/* 03 */
	(unsigned)&dv_irq,	/* 04 */
	(unsigned)&dv_irq,	/* 05 */
	(unsigned)&dv_irq,	/* 06 */
	(unsigned)&dv_irq,	/* 07 */
	(unsigned)&dv_irq,	/* 08 */
	(unsigned)&dv_irq,	/* 09 */
	(unsigned)&dv_irq,	/* 10 */
	(unsigned)&dv_irq,	/* 11 */
	(unsigned)&dv_irq,	/* 12 */
	(unsigned)&dv_irq,	/* 13 */
	(unsigned)&dv_irq,	/* 14 */
	(unsigned)&dv_irq,	/* 15 */
	(unsigned)&dv_irq,	/* 16 */
	(unsigned)&dv_irq,	/* 17 */
	(unsigned)&dv_irq,	/* 18 */
	(unsigned)&dv_irq,	/* 19 */
	(unsigned)&dv_irq,	/* 20 */
	(unsigned)&dv_irq,	/* 21 */
	(unsigned)&dv_irq,	/* 22 */
	(unsigned)&dv_irq,	/* 23 */
	(unsigned)&dv_irq,	/* 24 */
	(unsigned)&dv_irq,	/* 25 */
	(unsigned)&dv_irq,	/* 26 */
	(unsigned)&dv_irq,	/* 27 */
	(unsigned)&dv_irq,	/* 28 */
	(unsigned)&dv_irq,	/* 29 */
	(unsigned)&dv_irq,	/* 30 */
	(unsigned)&dv_irq,	/* 31 */
	(unsigned)&dv_irq,	/* 32 */
	(unsigned)&dv_irq,	/* 33 */
	(unsigned)&dv_irq,	/* 34 */
	(unsigned)&dv_irq,	/* 35 */
	(unsigned)&dv_irq,	/* 36 */
	(unsigned)&dv_irq,	/* 37 */
	(unsigned)&dv_irq,	/* 38 */
	(unsigned)&dv_irq,	/* 39 */
	(unsigned)&dv_irq,	/* 40 */
	(unsigned)&dv_irq,	/* 41 */
	(unsigned)&dv_irq,	/* 42 */
	(unsigned)&dv_irq,	/* 43 */
	(unsigned)&dv_irq,	/* 44 */
	(unsigned)&dv_irq,	/* 45 */
	(unsigned)&dv_irq,	/* 46 */
	(unsigned)&dv_irq,	/* 47 */
	(unsigned)&dv_irq,	/* 48 */
	(unsigned)&dv_irq,	/* 49 */
	(unsigned)&dv_irq,	/* 50 */
	(unsigned)&dv_irq,	/* 51 */
	(unsigned)&dv_irq,	/* 52 */
	(unsigned)&dv_irq,	/* 53 */
	(unsigned)&dv_irq,	/* 54 */
	(unsigned)&dv_irq,	/* 55 */
	(unsigned)&dv_irq,	/* 56 */
	(unsigned)&dv_irq,	/* 57 */
	(unsigned)&dv_irq,	/* 58 */
	(unsigned)&dv_irq,	/* 59 */
	(unsigned)&dv_irq,	/* 60 */
	(unsigned)&dv_irq,	/* 61 */
	(unsigned)&dv_irq,	/* 62 */
	(unsigned)&dv_irq,	/* 63 */
	(unsigned)&dv_irq,	/* 64 */
	(unsigned)&dv_irq,	/* 65 */
	(unsigned)&dv_irq,	/* 66 */
	(unsigned)&dv_irq,	/* 67 */
};
