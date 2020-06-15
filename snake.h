#ifndef SNAKE_H_
#define SNAKE_H_

#include <ncurses.h>
#include <stdlib.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define SPEED 0.5

#define DEFAULT_SNAKE_START_LEN 5
#define DEFAULT_SNAKE_START_DIR RIGHT
#define DEFAULT_SNAKE_BODY_CHAR '#'

#define NODE_EMPTY -1

typedef struct node {
	float x;
	float y;
} node_t;

typedef struct snake {
	float direction;
	float length;
	node_t* body;
} snake_t ;

snake_t* create_snake(const int start_x, const int start_y,
		const int start_direction, const int start_length);
void free_snake(snake_t* s);
void move_snake(snake_t* s, const int direction);
void grow_snake(snake_t* s, const int amount);
void draw_snake(WINDOW *win, const snake_t* s);

#endif
