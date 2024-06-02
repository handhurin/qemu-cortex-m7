# Principal Makefile

##############################################
################## PROJECT ###################
##############################################

PROJ_NAME = exercice-2
BOARD = ART_PI
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
include gen/code_verification.mk

clean :
	rm -rf $(BUILD_DIR)

echoes :
	@echo $(PROJ_NAME)
