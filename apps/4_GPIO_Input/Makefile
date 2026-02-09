# Makefile for STM32F446RE

# Application and SDK directories
APP_DIR = $(CURDIR)
SDK_ROOT = $(APP_DIR)/../..

# Toolchain configuration
TOOLCHAIN = $(SDK_ROOT)/toolchain/arm-none-eabi/bin/arm-none-eabi-
CC  = $(TOOLCHAIN)gcc
AS  = $(TOOLCHAIN)as
OBJCOPY = $(TOOLCHAIN)objcopy
PROGRAMMER = $(SDK_ROOT)/toolchain/OpenOCD/bin/openocd.exe

# MCU specific flags
CPU = cortex-m4
FPU = fpv4-sp-d16
FLOAT_ABI = hard
MCU_FLAGS = -mcpu=$(CPU) -mthumb -mfpu=$(FPU) -mfloat-abi=$(FLOAT_ABI)

# Source files
SRC= $(wildcard $(APP_DIR)/Src/*.c)
DEVICE = $(wildcard $(SDK_ROOT)/CMSIS/Device/stm32f4xx/*.c)
STARTUP = $(wildcard $(SDK_ROOT)/Startup/*.s)

# Object files
SRC_OBJ = $(patsubst $(APP_DIR)/Src/%.c, $(BUILD_DIR)/%.o, $(SRC))
DEVICE_OBJ = $(patsubst $(SDK_ROOT)/CMSIS/Device/stm32f4xx/%.c, $(BUILD_DIR)/%.o, $(DEVICE))
STARTUP_OBJ = $(patsubst $(SDK_ROOT)/Startup/%.s, $(BUILD_DIR)/%.o, $(STARTUP))

OBJ =\
	$(SRC_OBJ) \
	$(DEVICE_OBJ) \
	$(STARTUP_OBJ)

# Directories for build and binary output
BUILD_DIR = build
BIN_DIR = bin

# Compiler and linker flags
CFLAGS = $(MCU_FLAGS) -Wall -Wextra -Werror -DSTM32F446xx
LDFLAGS = $(MCU_FLAGS) -T$(SDK_ROOT)/Linker/STM32F446RE_FLASH.ld -u _printf_float
INCLUDES =\
	-I$(APP_DIR)/Inc \
	-I$(SDK_ROOT)/CMSIS/Include \
	-I$(SDK_ROOT)/CMSIS/Device/stm32f4xx

# OpenOCD programmer flags
PROGRAMMER_FLAGS=-f interface/stlink.cfg -f target/stm32f4x.cfg

# Output application name
APP_NAME = 4_GPIO_Input

# Default target
all: clean build flash

build: makedir $(BIN_DIR)/$(APP_NAME).elf $(BIN_DIR)/$(APP_NAME).hex $(BIN_DIR)/$(APP_NAME).bin

# Generar ELF a partir de los objetos
$(BIN_DIR)/$(APP_NAME).elf: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $^ -o $@

# Generar HEX a partir del ELF
$(BIN_DIR)/$(APP_NAME).hex: $(BIN_DIR)/$(APP_NAME).elf
	$(OBJCOPY) -O ihex $< $@

# Generar BIN a partir del ELF
$(BIN_DIR)/$(APP_NAME).bin: $(BIN_DIR)/$(APP_NAME).elf
	$(OBJCOPY) -O binary $< $@

# Reglas para compilar los archivos fuente en objetos
$(BUILD_DIR)/%.o: $(APP_DIR)/Src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/%.o: $(SDK_ROOT)/CMSIS/Device/stm32f4xx/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/%.o: $(SDK_ROOT)/Startup/%.s
	$(AS) -mcpu=cortex-m4 -o $@ $<

# Rule to generate build folder
makedir:
	@mkdir -p "$(BUILD_DIR)" "$(BIN_DIR)"

# Rule to clean files 
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

flash: $(BIN_DIR)/$(APP_NAME).elf
	$(PROGRAMMER) $(PROGRAMMER_FLAGS) -c "program $(BIN_DIR)/$(APP_NAME).elf verify reset exit"

.PHONY: all clean build makedir flash
