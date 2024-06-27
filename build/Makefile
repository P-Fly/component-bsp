ifeq ($(SOURCE_DIR),)
$(error SOURCE_DIR can not be NULL)
endif

ifeq ($(BUILD_DIR),)
$(error BUILD_DIR can not be NULL)
endif

ifeq ($(PROJ_NAME),)
$(error PROJ_NAME can not be NULL)
endif

CFLAGS        += -Wall
CXXFLAGS      += -Wall
LDFLAGS	      += -Wall

C_FILES       ?=
C_OBJS         = $(C_FILES:$(SOURCE_DIR)/%.c=$(BUILD_DIR)/%.o)
CXX_FILES     ?=
CXX_OBJS       = $(CXX_FILES:$(SOURCE_DIR)/%.cpp=$(BUILD_DIR)/%.o)

CXXFLAGS      += $(CFLAGS)

all: $(BUILD_DIR)/$(PROJ_NAME)
	@echo Make done

clean:
	@echo Clean all
	@$(RM) -rf $(BUILD_DIR)

include $(SOURCE_DIR)/build/.rule.mk

.PHONY: all clean
