#ifndef SNAKE_H_
#define SNAKE_H_

#include <ncurses.h>

#define SNAKE_START_LEN 5

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

typedef struct node {
	int x;
	int y;
} node_t;

typedef struct snake {
	int direction;
	int length;
	node_t* body;
} snake_t ;

snake_t* create_snake(const int start_x, const int start_y);
void move_snake(snake_t* s, const int direction);
void grow_snake(snake_t* s, const int amount);
void draw_snake(WINDOW *win, const snake_t* s);

#endif
