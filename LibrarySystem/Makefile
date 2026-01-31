CC = gcc
CFLAGS = -Wall -I.

BUILD_DIR = build
PRE_DIR   = $(BUILD_DIR)/preprocess
ASM_DIR   = $(BUILD_DIR)/assemble
OBJ_DIR   = $(BUILD_DIR)/objects
BIN_DIR   = $(BUILD_DIR)/bin

TARGET = $(BIN_DIR)/library_app

SRCS = main.c \
       Utils/utils.c \
       Book/book.c \
       User/user.c \
       Management/management.c

PRE_FILES = $(patsubst %.c, $(PRE_DIR)/%.i, $(SRCS))
ASM_FILES = $(patsubst %.c, $(ASM_DIR)/%.s, $(SRCS))
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# make
all: $(TARGET)
	@echo "Build Success! Run with: ./$(TARGET)"


$(TARGET): $(OBJ_FILES)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@
	@echo "[LINK] Created executable: $@"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "[COMPILE] Created object: $@"

# make assemble
assemble: $(ASM_FILES)
$(ASM_DIR)/%.s: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -S $< -o $@
	@echo "[ASM] Created assembly: $@"

# make preprocess
preprocess: $(PRE_FILES)
$(PRE_DIR)/%.i: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -E $< -o $@
	@echo "[PRE] Created preprocessed: $@"

# make clean
clean:
	rm -rf $(BUILD_DIR)
	@echo "Cleaned build directory."

.PHONY: all clean preprocess assemble