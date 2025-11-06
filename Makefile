CC = gcc
CFLAGS = -Iinclude -Wall -Wextra

SRC_DIR = src
OBJ_DIR = obj
BIN = main.exe

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(BIN)

debug: CFLAGS += -g
debug: $(BIN)

clean:
	rm -rf $(OBJ_DIR) $(BIN)

run:
	./main.exe

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean debug all