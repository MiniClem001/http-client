CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = client.c
OBJ = $(BUILD)client.o
TARGET = $(BUILD)client
BUILD = build/

all: $(TARGET)
	$(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ): $(SRC) $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD):
	@[ -d "build/" ] || mkdir -p build/

clean:
	rm -rf $(BUILD)

.PHONY: all clean