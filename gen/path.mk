# Makefile with all project paths

##############################################
############ PROJECT DIRECTORIES #############
##############################################

WORKSPACE 				= $(shell pwd)

CORE_DIR        		= $(WORKSPACE)/core

TOOLS_DIR 				= $(WORKSPACE)/tools
CMSIS_DIR 				= $(TOOLS_DIR)/CMSIS
HALs_DIR  				= $(TOOLS_DIR)/HALs
BSPs_DIR  				= $(TOOLS_DIR)/BSPs

GEN_DIR           		= $(WORKSPACE)/gen
CONF_HALS_DIR     		= $(GEN_DIR)/conf_HALs
CONF_MISRA_DIR     		= $(GEN_DIR)/conf_misra

APPLICATION_DIR 		= $(WORKSPACE)/application

BUILD_DIR             	= $(WORKSPACE)/build
BUILD_CORE_DIR        	= $(BUILD_DIR)/core
BUILD_TOOLS_DIR       	= $(BUILD_DIR)/tools
BUILD_LIBS_DIR        	= $(BUILD_DIR)/libs
TARGET_DIR            	= $(BUILD_DIR)/target

##############################################
############## CORE DIRECTORIES ##############
##############################################

# Main Directories
CORE_INCDIR = $(CORE_DIR)/inc
CORE_SRCDIR = $(CORE_DIR)/src

##############################################
############## CMSIS DIRECTORIES #############
##############################################

# CMSIS Directories
ifeq ($(CHIP_FAMILLY), CMSDK)
CMSIS_INCDIR_DEVICE = $(CMSIS_DIR)/cmsis_device_cmsdk_cm7/Include
else
$(error There is no compatible CMSIS)
endif
CMSIS_INCDIR       = $(CMSIS_DIR)/CMSIS-ARM/CMSIS/Core/Include

##############################################
############### HAL DIRECTORIES ##############
##############################################

# HAL Directories
ifeq ($(CHIP_FAMILLY), CMSDK)
HAL_DIR = $(HALs_DIR)/HAL-CMSDK
else
$(error There is no compatible HAL)
endif
HAL_INCDIR = $(HAL_DIR)/Inc
HAL_SRCDIR = $(HAL_DIR)/Src
HAL_OBJDIR = $(BUILD_TOOLS_DIR)/hal

##############################################
########### GENERIC HAL DIRECTORIES ##########
##############################################

# GENERIC HAL Directories
GENERIC_HAL_DIR    = $(HALs_DIR)/GENERIC-HAL
GENERIC_HAL_INCDIR = $(GENERIC_HAL_DIR)/inc
GENERIC_HAL_SRCDIR = $(GENERIC_HAL_DIR)/src
GENERIC_HAL_OBJDIR = $(BUILD_TOOLS_DIR)/generic_hal

##############################################
############### BSP DIRECTORIES ##############
##############################################

# BSP Directories
BSP_INCDIR = $(BSP_DIR)/inc
BSP_SRCDIR = $(BSP_DIR)/src
BSP_OBJDIR = $(BUILD_TOOLS_DIR)/bsp
