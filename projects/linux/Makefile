THIS_DIR      := $(shell dirname $(abspath $(lastword $(MAKEFILE_LIST))))
SOURCE_DIR    := $(abspath $(THIS_DIR)/../../)
BUILD_DIR     := $(THIS_DIR)/out
RELEASE_DIR   := $(THIS_DIR)/out/release
PROJ_NAME     := bsp_cunit

C_FILES       += $(SOURCE_DIR)/projects/linux/main.c
C_FILES       += $(SOURCE_DIR)/bsp/platform/linux/infra/trace/source/trace_impl.c

CFLAGS        += -I$(SOURCE_DIR)/bsp/include
CFLAGS        += -I$(SOURCE_DIR)/bsp/platform/linux/infra/trace/include
CFLAGS        += -I$(SOURCE_DIR)/bsp/utils/ring_buff/include
CFLAGS        += -I$(SOURCE_DIR)/test/CUnit/include

C_FILES       += $(SOURCE_DIR)/test/case/utils/ring_buff/cunit_ring_buff.c
CFLAGS        += -I$(SOURCE_DIR)/test/case/utils/ring_buff

C_FILES       += $(SOURCE_DIR)/bsp/utils/signal_generator/source/signal_generator.c
CFLAGS        += -I$(SOURCE_DIR)/bsp/utils/signal_generator/include
C_FILES       += $(SOURCE_DIR)/test/case/utils/signal_generator/cunit_signal_generator.c
CFLAGS        += -I$(SOURCE_DIR)/test/case/utils/signal_generator

LDFLAGS       += -L$(SOURCE_DIR)/test/CUnit/lib -lcunit

include $(SOURCE_DIR)/build/Makefile

stm32wbxx_install:
	@echo Install STM32WBxx
	@mkdir -p $(RELEASE_DIR)/include
	@cp -rf $(SOURCE_DIR)/bsp/include/* $(RELEASE_DIR)/include/
	@mkdir -p $(RELEASE_DIR)/platform
	@cp -rf $(SOURCE_DIR)/bsp/platform/stm32wbxx $(RELEASE_DIR)/platform/
	@mkdir -p $(RELEASE_DIR)/utils
	@cp -rf $(SOURCE_DIR)/bsp/utils/* $(RELEASE_DIR)/utils/
