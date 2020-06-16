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
	free(s->body);
	free(s);
}

void move_snake_wrap(snake_t* s, const int direction, const int term_x, const int term_y)
{
	move_snake(s, direction);

	if(s->body->x >= term_x)
		s->body->x = 0;
	else if(s->body->x < 0)
		s->body->x = term_x - 1;

	if(s->body->y >= term_y)
		s->body->y = 0;
	else if(s->body->y < 0)
		s->body->y = term_y - 1;
}


void move_snake(snake_t* s, const int direction)
{
	if(direction != CURRENT_DIRECTION)
	{
		if(!((direction == LEFT && s->direction == RIGHT)
					|| (direction == RIGHT && s->direction == LEFT)
					|| (direction == UP && s->direction == DOWN)
					|| (direction == DOWN && s->direction == UP)))
		 {
			s->direction = direction;
		 }
	}

	for(int i = (s->length - 1); i > 0; i--)
	{
		if(s->body[i - 1].x != NODE_EMPTY) // Ignore until we find something with something in
		{
			s->body[i].x = s->body[i-1].x;
			s->body[i].y = s->body[i-1].y;
		}
	}

	node_t *head = s->body;
	int dir = s->direction;
	switch(dir)
	{
		case UP 	: head->y -= SPEED; break;
		case DOWN	: head->y += SPEED; break;
		case LEFT	: head->x -= SPEED; break;
		case RIGHT	: head->x += SPEED; break;
	}
}

void grow_snake(snake_t* s, const int amount)
{
	s->body = realloc(s->body, (s->length += amount) * sizeof(node_t));
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

void clear_snake(WINDOW *win, const snake_t* s)
{
	node_t current;
	for(int i = 0; i < s->length; i++)
	{
		current = s->body[i];
		if(current.x != NODE_EMPTY && current.y != NODE_EMPTY)
		{
			mvwaddch(win, current.y, current.x, ' ');
		}
	}
}
