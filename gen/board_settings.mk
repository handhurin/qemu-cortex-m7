# Makefile with board parameters

#################################
########### MPS2_AN500 ##########
#################################
ifeq ($(BOARD), MPS2_AN500)
# Chip Information
CHIP_VENDOR = ARM
CHIP_FAMILLY = CMSDK_CM7
CHIP = CMSDK_CM7
MACH = cortex-m7
CORE_SELECT = -DCORE_CM7
FPU_TYPE = -mfloat-abi=soft
FPU_AVAILABILITY = FPU_UNAVAILABLE
CACHE_AVAILABILITY = CACHE_AVAILABLE
# Debugger Information
OCD_DBG = interface/stlink.cfg
OCD_CHIP = target/stm32h7x.cfg
# BSP Information
BSP_DIR = $(BSPs_DIR)/MPS2_AN500-BSP
LINKER_SCRIPT = $(BSP_DIR)/mps2_an500.ld

#################################
############## ELSE #############
#################################
else
$(error This board is not available for the software)
endif