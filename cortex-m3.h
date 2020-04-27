/*  cortexm3.h
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
#ifndef CORTEXM3_H
#define CORTEXM3_H

#include "stm32.h"

/* Aux control registers, including the SysTick timer
*/
typedef struct dv_cortexm3acr_s dv_cortexm3acr_t;

struct dv_cortexm3acr_s
{
	dv_reg32_t unknown;		/* What's this */
	dv_reg32_t ictr;		/* Interrupt controller type */
	dv_reg32_t actlr;		/* Aux control register */
	dv_reg32_t stcsr;		/* SysTick control/status */
	dv_reg32_t strvr;		/* SysTick reload */
	dv_reg32_t stcvr;		/* SysTick current value */
	dv_reg32_t stcr;		/* SysTick calibration value */
};

#define DV_CORTEXM3ACR_BASE		0xe000e000
#define dv_m3acr				((dv_cortexm3acr_t *)DV_CORTEXM3ACR_BASE)[0]

/* System control registers
*/
typedef struct dv_cortexm3scr_s dv_cortexm3scr_t;

struct dv_cortexm3scr_s
{
	dv_reg32_t cpuid;		/* RO - CPU identification */
	dv_reg32_t icsr;		/* Interrupt control/state */
	dv_reg32_t vtor;		/* Vector table offset */
	dv_reg32_t aircr;		/* Application interrupt and reset control */
	dv_reg32_t scr;			/* System control */
	dv_reg32_t ccr;			/* Configuration and control */
	dv_reg32_t shpr1;		/* System handler priority */
	dv_reg32_t shpr2;		/* System handler priority */
	dv_reg32_t shpr3;		/* System handler priority */
	dv_reg32_t shcsr;		/* System handler control and state */
	dv_reg32_t cfsr;		/* Configurable fault status */
	dv_reg32_t hfsr;		/* Hardfault status */
	dv_reg32_t dfsr;		/* Debug fault status */
	dv_reg32_t mmfar;		/* MemManage fault address */
	dv_reg32_t bfar;		/* Bus fault address*/
	dv_reg32_t afsr;		/* Auxiliary fault status */
	dv_reg32_t id_pfr0;		/* RO */
	dv_reg32_t id_pfr1;		/* RO */
	dv_reg32_t id_dfr0;		/* RO */
	dv_reg32_t id_afr0;		/* RO */
	dv_reg32_t id_mmfr0;	/* RO */
	dv_reg32_t id_mmfr1;	/* RO */
	dv_reg32_t id_mmfr2;	/* RO */
	dv_reg32_t id_mmfr3;	/* RO */
	dv_reg32_t id_isar0;	/* RO */
	dv_reg32_t id_isar1;	/* RO */
	dv_reg32_t id_isar2;	/* RO */
	dv_reg32_t id_isar3;	/* RO */
	dv_reg32_t id_isar4;	/* RO */
};

#define DV_CORTEXM3SCR_BASE		0xe000ed00
#define dv_m3scr				((dv_cortexm3scr_t *)DV_CORTEXM3SCR_BASE)[0]

/* CPACR and STIR are well separated from the SCR
*/
#define DV_CORTEXM3_CPACR		0xe000ed88
#define DV_m3cpacr				((dv_reg32_t *)DV_CORTEXM3_CPACR)[0]

#define DV_CORTEXM3_STIR		0xe000ef00
#define DV_m3stir				((dv_reg32_t *)DV_CORTEXM3_STIR)[0]

#endif
