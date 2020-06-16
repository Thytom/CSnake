CC = gcc
CFLAGS = -O2 -g -Wall -lncurses
DEP = main.h snake.h apple.h collision.h
OBJ = main.o snake.o apple.o collision.o

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
