CC := gcc
CFLAGS := -std=c90 -Isrc -Wall -Wextra -MMD -MP
LDFLAGS := -flto -Wl,--gc-sections
LIBS := 

SRC_DIR := src
BUILD_DIR := build

SRC := $(shell find -L $(SRC_DIR) -type f -name '*.c')
OBJ := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
BIN := main

%.o: %.c
	@$(CC) -c $(CFLAGS) $(LDFLAGS) $< -o $@

all: $(BIN)

$(BIN): $(OBJ)
	@$(CC) $(LDFLAGS) $(OBJ) -o $@ $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

run: $(BIN)
	./$(BIN)

clean:
	@rm -rf $(BUILD_DIR) $(BIN)

.PHONY: all run clean