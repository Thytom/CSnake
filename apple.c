#include "apple.h"

void move_apple(const snake_t *s, node_t *apple
		, int term_x, int term_y)
{
	if(s->body == NULL || apple == NULL)
		return;
	do
	{
		apple->x = rand() % term_x;
		apple->y = rand() % term_y;
	} while(check_collision(s->body, s->length, apple) == 1);
}

node_t *new_apple(const snake_t *s, int term_x, int term_y)
{
	node_t *apple = malloc(sizeof(node_t));
	move_apple(s, apple, term_x, term_y);
	return apple;
}
