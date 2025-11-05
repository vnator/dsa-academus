# Makefile para Árvore Binária de Busca

CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = main
SOURCES = main.c arv_binaria.c
HEADERS = avr_binaria.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
