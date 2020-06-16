#ifndef SNAKE_H_
#define SNAKE_H_

#include <ncurses.h>
#include <stdlib.h>

#define CURRENT_DIRECTION 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define SPEED 1

#define DEFAULT_SNAKE_START_LEN 5
#define DEFAULT_SNAKE_START_DIR RIGHT
#define DEFAULT_SNAKE_BODY_CHAR '#'

#define NODE_EMPTY -1

typedef struct node {
	int x;
	int y;
} node_t;

typedef struct snake {
	int direction;
	int length;
	node_t* body;
} snake_t ;

snake_t* create_snake(int start_x, int start_y,
		int start_direction, int start_length);
void free_snake(snake_t* s);

void move_snake_wrap(snake_t* s, int direction
		, int term_x, int term_y);
void move_snake(snake_t* s, int direction);

void grow_snake(snake_t* s, int amount);
void draw_snake(WINDOW *win, const snake_t* s);
void clear_snake(WINDOW *win, const snake_t* s);

#endif
