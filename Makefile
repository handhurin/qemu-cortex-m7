# Principal Makefile

##############################################
################## PROJECT ###################
##############################################

PROJ_NAME = qemu-cortex-m7
BOARD = MPS2_AN500
LOAD_MEMORY = ram
VERSION = debug

##############################################
################### MAKE #####################
##############################################

.PHONY = all clean echoes

all : clean build upload

include gen/settings.mk
include gen/path.mk
include gen/build.mk
include gen/debug.mk

clean :
	rm -rf $(BUILD_DIR)

echoes :
	@echo $(PROJ_NAME)
