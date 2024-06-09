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

# HAL Recipe
hal : $(HAL_LIB)
	@echo "******************************"
	@echo "*****   HAL Build Done   *****"
	@echo "******************************"
	@echo
