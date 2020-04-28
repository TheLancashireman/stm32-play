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

/* The vector table is an array of addresses.
 * This table has 64 vectors:
 *	- 16 are the armv7m exception/reset vectors (including reset SP)
 *	- 48 are for the NVIC interrupts. They are all mappped to dv_irq
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
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
	(unsigned)&dv_irq,
};
