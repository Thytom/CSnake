CC = gcc
CFLAGS = -O2 -g -Wall -lncurses
DEP = main.h
OBJ = main.o

EXECUTABLE=CSnake

.phony: all make run clean

%.o : %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all: make run clean

make: $(OBJ)
	$(CC) -s -o $(EXECUTABLE) $^ $(CFLAGS)

run: make
	./$(EXECUTABLE)

clean:
	rm $(OBJ) $(EXECUTABLE)
