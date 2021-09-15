CC			:= avr-g++
FLAGS		:= -Wall -Werror -g -Os
CFLAGS	:= -I./inc
MFLAGS	:= -mmcu=atmega328p
LFLAGS	:= -L./lib -lICM7212

AR			:= avr-ar rcs
OBJCPY	:= avr-objcopy -j .text -j .data -O ihex
OBJS		:= $(patsubst src/%.cpp, %.o, $(wildcard src/*.cpp))

.PHONY: all clean

default: lib/libICM7212.a clean

all: lib/libICM7212.a bin/ICM7212AM_demo.hex clean

%.o: src/%.cpp
	$(CC) $(FLAGS) $(CFLAGS) -c -o $@ $< -lm

lib/libICM7212.a: $(OBJS)
	mkdir -p lib
	$(AR) $@ $^

bin/ICM7212AM_demo.hex: lib/libICM7212.a
	mkdir -p bin/
	$(CC) $(FLAGS) $(CFLAGS) $(MFLAGS) -o bin/main.elf demo/main.cpp $(LFLAGS)
	$(OBJCPY) bin/main.elf $@

clean:
	rm -f *.o bin/main.elf

remove:
	rm -rf bin lib