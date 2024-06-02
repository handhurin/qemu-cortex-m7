# HAL Building Makefile

##############################################
#################### HAL #####################
##############################################

# HAL Flags
HAL_CFLAGS    = $(PROJECT_CFLAGS) -Wno-unused-variable -Wno-unused-parameter
HAL_INCFLAGS  = -I$(HAL_INCDIR) -I$(HAL_INCDIR)/Legacy -I$(CONF_HALS_DIR)
HAL_INCFLAGS += -I$(CMSIS_INCDIR) -I$(CMSIS_INCDIR_DEVICE)

# HAL Files
include $(HAL_SRCS_LIST)
HAL_OBJS  = $(subst $(HAL_SRCDIR)/,$(HAL_OBJDIR)/,$(HAL_SRCS:.c=-$(VERSION).o))
HAL_LIB   = $(BUILD_LIBS_DIR)/libhal-$(VERSION).a

# HAL compilation
$(HAL_OBJDIR)/%-$(VERSION).o : $(HAL_SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) $(HAL_CFLAGS) $(HAL_INCFLAGS) $(VERSION_FLAGS) $^ -o $@ 

# HAL Library
$(HAL_LIB) : $(HAL_OBJS)
	mkdir -p $(@D)
	$(AR) rcs $@ $^

libhal : $(HAL_LIB)
	@echo "******************************"
	@echo "*****   HAL Build Done   *****"
	@echo "******************************"
	@echo

##############################################
################ GENERIC HAL #################
##############################################

# GENERIC HAL Flags
GENERIC_HAL_CFLAGS    = $(PROJECT_CFLAGS)
GENERIC_HAL_INCFLAGS  = -I$(GENERIC_HAL_INCDIR)
GENERIC_HAL_INCFLAGS += -I$(HAL_INCDIR) -I$(HAL_INCDIR)/Legacy -I$(CONF_HALS_DIR)
GENERIC_HAL_INCFLAGS += -I$(CMSIS_INCDIR) -I$(CMSIS_INCDIR_DEVICE)
GENERIC_HAL_INCFLAGS += -I$(BSP_INCDIR)

# GENERIC HAL Files
GENERIC_HAL_SRCS = $(wildcard $(GENERIC_HAL_SRCDIR)/*.c)
GENERIC_HAL_OBJS = $(subst $(GENERIC_HAL_SRCDIR)/,$(GENERIC_HAL_OBJDIR)/,$(GENERIC_HAL_SRCS:.c=-$(VERSION).o))
GENERIC_HAL_LIB  = $(BUILD_LIBS_DIR)/libgeneric-hal-$(VERSION).a

# GENERIC HAL compilation
$(GENERIC_HAL_OBJDIR)/%-$(VERSION).o : $(GENERIC_HAL_SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) $(GENERIC_HAL_CFLAGS) $(GENERIC_HAL_INCFLAGS) $(VERSION_FLAGS) $^ -o $@ 

# GENERIC HAL Library
$(GENERIC_HAL_LIB) : $(GENERIC_HAL_OBJS)
	mkdir -p $(@D)
	$(AR) rcs $@ $^

libgeneric-hal : $(GENERIC_HAL_LIB)
	@echo "********************************"
	@echo "**   GENERIC HAL Build Done   **"
	@echo "********************************"
	@echo