/*  dv-cortexm-vectors.S - vector table for Cortex-M devices
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
#define DV_ASM  1

	.globl	dv_vectors

	.extern	dv_stacktop
	.extern	dv_reset
	.extern	dv_nmi
	.extern	dv_hardfault
	.extern	dv_memfault
	.extern	dv_busfault
	.extern	dv_usagefault
	.extern	dv_svctrap
	.extern	dv_pendsvtrap
	.extern	dv_systickirq
	.extern	dv_irq
	.extern	dv_unknowntrap

/* The vector table is an array of addresses. In theory we might be able to define it in C,
 * but locating it at the correct place could be fun.
 * This table has 64 vectors:
 *	- 16 are the armv7m exception/reset vectors (including reset SP)
 *	- 48 are for the NVIC interrupts. They are all mappped to dv_irq
*/
	.section	.vectors, "ax"

dv_vectors:
	.word	dv_stacktop
	.word	dv_reset
	.word	dv_nmi
	.word	dv_hardfault
	.word	dv_memfault
	.word	dv_busfault
	.word	dv_usagefault
	.word	dv_unknowntrap
	.word	dv_unknowntrap
	.word	dv_unknowntrap
	.word	dv_unknowntrap
	.word	dv_svctrap
	.word	dv_unknowntrap
	.word	dv_unknowntrap
	.word	dv_pendsvtrap
	.word	dv_systickirq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
	.word	dv_irq
