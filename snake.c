#include "snake.h"

snake_t* create_snake(const int start_x, const int start_y,
		const int start_direction, const int start_length)
{
	snake_t* new_snake = malloc(sizeof(snake_t));

	new_snake->direction = start_direction;
	new_snake->length = start_length;

	new_snake->body = malloc(sizeof(node_t) * start_length);

	new_snake->body[0].x = start_x;
	new_snake->body[0].y = start_y;

	for(int i = 1; i < start_length; i++)
	{
		new_snake->body[i].x = NODE_EMPTY;
		new_snake->body[i].y = NODE_EMPTY;
	}

	return new_snake;
}

void free_snake(snake_t* s)
{

}

void move_snake(snake_t* s, const int direction)
{

}

void grow_snake(snake_t* s, const int amount)
{

}

void draw_snake(WINDOW *win, const snake_t* s)
{
	node_t current;
	for(int i = 0; i < s->length; i++)
	{
		current = s->body[i];
		if(current.x != NODE_EMPTY && current.y != NODE_EMPTY)
		{
			mvwaddch(win, current.y, current.x, DEFAULT_SNAKE_BODY_CHAR);
		}
	}
}

