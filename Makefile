#  Makefile
#
#  Copyright David Haworth
#
#  This file is part of the STM32 playground.
#
#  The STM32 playground is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  The STM32 playground is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with the STM32 playground.  If not, see <http://www.gnu.org/licenses/>.

DV_GNU_D	?= /data1/gnu/gcc-linaro-7.5.0-2019.12-x86_64_arm-eabi

DV_GCC		?= $(DV_GNU_D)/bin/arm-eabi-gcc
DV_LD		?= $(DV_GNU_D)/bin/arm-eabi-ld
DV_OBJCOPY	?= $(DV_GNU_D)/bin/arm-eabi-objcopy

DV_BIN_D	= bin
DV_OBJ_D	= obj

DV_ENTRY	?= dv_reset
DV_LDSCRIPT	?= stm32.ldscript

CC_OPT		+= -Wall
CC_OPT		+= -fno-common
CC_OPT		+= -mcpu=cortex-m3

CC_OPT		+= -O2
CC_OPT		+= -g

LD_OPT		+= -e $(DV_ENTRY)
LD_OPT		+= -T $(DV_LDSCRIPT)

VPATH		+= .

# The demo code
DV_LD_OBJS	+= $(DV_OBJ_D)/dv-cortexm-vectors.o
DV_LD_OBJS	+= $(DV_OBJ_D)/play.o
DV_LD_OBJS	+= $(DV_OBJ_D)/rcc.o
DV_LD_OBJS	+= $(DV_OBJ_D)/leds.o
DV_LD_OBJS	+= $(DV_OBJ_D)/systick.o

.PHONY:		default all help clean install srec binary

default:	binary

clean:
	-rm -rf $(DV_OBJ_D) $(DV_BIN_D)

all:		$(DV_OBJ_D) $(DV_BIN_D) elf

elf:		$(DV_BIN_D)/play.elf

$(DV_BIN_D)/play.elf:	$(DV_LD_OBJS) $(DV_LDSCRIPT)
	$(DV_LD) -o $@ $(DV_LD_OBJS) $(LD_LIB) $(LD_OPT)

$(DV_OBJ_D)/%.o:	%.c
	$(DV_GCC) $(CC_OPT) -o $@ -c $<

$(DV_OBJ_D)/%.o:	%.S
	$(DV_GCC) $(CC_OPT) -o $@ -c $<

$(DV_BIN_D):
	mkdir -p bin

$(DV_OBJ_D):
	mkdir -p obj

install:	all
	$(DV_OBJCOPY) bin/play.elf -O binary $(INSTALL_DIR)/kernel.img

srec:		all
	$(DV_OBJCOPY) bin/play.elf -O srec --srec-forceS3 /dev/stdout | dos2unix | egrep -v '^S3..........00*..$$' > bin/play.srec

binary:		play.bin

play.bin:	all
	$(DV_OBJCOPY) bin/play.elf -O binary play.bin
