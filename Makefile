CC = gcc
CFLAGS = -Wall -Wextra # -Werror

SRC = client.c
OBJ = build/client.o
TARGET = build/client

all: $(TARGET)
	$(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all