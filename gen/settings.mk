# Makefile including all environnement parameters

include gen/board_settings.mk 
include gen/cc_settings.mk

##############################################
################### TOOLS ####################
##############################################

# Tools
CC      = $(shell which arm-none-eabi-gcc)
AR      = $(shell which arm-none-eabi-ar)
SIZE    = $(shell which arm-none-eabi-size)
READELF = $(shell which arm-none-eabi-readelf)
GDB     = $(shell which gdb-multiarch || which gdb)
OCD     = $(shell which openocd)
CHECKER = $(shell which cppcheck)

##############################################
############### MEMORY SETTINGS ##############
##############################################

ifeq ($(LOAD_MEMORY), flash)
IT_VECTOR_SETTINGS = -DVECT_TAB_FLASH
else ifeq ($(LOAD_MEMORY), ram)
IT_VECTOR_SETTINGS = -DVECT_TAB_SRAM
else
$(error Load memory can only be flash or ram)
endif