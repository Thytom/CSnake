#include "apple.h"

void move_apple(const snake_t *s, node_t *apple
		, const int term_x, const int term_y)
{
	if(s->body == NULL || apple == NULL)
		return;
	do
	{
		apple->x = rand() % term_x;
		apple->y = rand() % term_y;
	} while(check_collision(s, apple, FULL_COL) == 1);
}

node_t *new_apple(const snake_t *s, const int term_x, const int term_y)
{
	node_t *apple = malloc(sizeof(node_t));
	move_apple(s, apple, term_x, term_y);
	return apple;
}

int check_collision(const snake_t *s, const node_t *apple, const int col_type)
{
	if(s == NULL || apple == NULL)
		return 0;

	if(s->body[0].x == apple->x
			&& s->body[0].y == apple->y)
		return 1;

	if(col_type == FULL_COL)
	{
		for(int i = 1; i < s->length; i++)
			if(s->body[i].x == apple->x
					&& s->body[i].y == apple->y)
				return 1;
	}

	return 0;
}
