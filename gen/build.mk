# Software Building Makefile

include gen/build_core.mk
include gen/build_hal.mk
include gen/build_bsp.mk

##############################################
#################### BUILD ###################
##############################################

# Targets definitions
TARGET_DBG = $(TARGET_DIR)/$(PROJ_NAME)-$(VERSION).elf
TARGET_RLS = $(TARGET_DIR)/$(PROJ_NAME)-$(VERSION).elf

# Target definition according to version
ifeq ($(VERSION), debug)
TARGET = $(TARGET_DBG)
VERSION_FLAGS = $(DEBUG_FLAGS)
else ifeq ($(VERSION), release)
TARGET = $(TARGET_RLS)
VERSION_FLAGS = $(RELEASE_FLAGS)
else
$(error Please select debug or release)
endif

.PHONY += build

build : $(TARGET)

# Target Linking Stage
$(TARGET) : bsp libhal libgeneric-hal core
	mkdir -p $(@D)
	$(CC) ${CORE_OBJS} ${BSP_OBJS} -L$(BUILD_LIBS_DIR) -Wl,--whole-archive -lgeneric-hal-$(VERSION) -Wl,--no-whole-archive -lhal-$(VERSION) $(PROJECT_LDFLAGS) -o $@ > $(TARGET:.elf=.size)
	$(READELF) -a $(TARGET) > $(TARGET:.elf=.readelf)
	@echo "*****************************"
	@echo "***   Target Build Done   ***"
	@echo "*****************************"