

CC := gcc

CFLAGS := -std=c11 -O2 -Wall -Wextra -Wpedantic -Werror
CPPFLAGS := -Isrc
LDLIBS := -lm

TARGET := build/list-4
OBJECTS := build/main.o build/integration.o

.PHONY: all install build run clean

all: build

install: build

build: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDLIBS) -o $@

build/%.o: src/%.c src/integration.h
	@mkdir -p build
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

run: build
	./$(TARGET)

clean:
	rm -rf build results
