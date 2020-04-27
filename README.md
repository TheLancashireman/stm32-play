# TheLancashireman's STM32 playground.

This repository contains some code that I hacked together to learn about the STM32F103C8xx processor
and the "Blue Pill" development board.

It's just the basics - GPIO (so I can blink an LED), the PLL (so I can run at the full 72 MHz),
a timer (Cortex M's SysTick to start with) and a uart. All the basic stuff one might need for
a simple bare-metal project.

There's also some information about the compiler and debugging using gdb, openocd and an ST-LINK dongle clone.


## License, disclaimer etc.

Copyright David Haworth

This file is part of the STM32 playground.

The STM32 playground is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

The STM32 playground is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with the STM32 playground.  If not, see <http://www.gnu.org/licenses/>.

