#include "collision.h"

int check_collision(const node_t *node_list, int length, const node_t *node)
{
	for(int i = 1; i < length; i++)
		if(collides(node_list[i], *node))
			return 1;

	return 0;
}

int collides(node_t a, node_t b)
{
	if(a.x == b.x && a.y == b.y)
		return 1;
	else
		return 0;
}
