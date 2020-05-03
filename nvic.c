/*  nvic.c
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
#include "nvic.h"

/* dv_nvic_init() - initialize the nvic
*/
void dv_nvic_init(void)
{
	/* Disable all sources and clear any pending
	*/
	int nsets = (DV_NVIC_NIRQ+31)/32;

	for ( int i = 0; i < nsets; i++ )
	{
		dv_nvic.icer[i] = 0xffffffff;	/* Disable all interrupts sources in the set */
		dv_nvic.icpr[i] = 0xffffffff;	/* Clear all pending IRQa in the set */
	}
}
