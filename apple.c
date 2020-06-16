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
	} while(check_collision(s->body, s->length, apple) == 1);
}

node_t *new_apple(const snake_t *s, const int term_x, const int term_y)
{
	node_t *apple = malloc(sizeof(node_t));
	move_apple(s, apple, term_x, term_y);
	return apple;
}

int check_collision(const node_t *node_list, const int length, const node_t *node)
{
	for(int i = 1; i < length; i++)
		if(collides(node_list[i], *node))
			return 1;

	return 0;
}

int collides(const node_t a, const node_t b)
{
	if(a.x == b.x && a.y == b.y)
		return 1;
	else
		return 0;
}
