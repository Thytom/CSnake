#ifndef COLLISION_H_
#define COLLISION_H_

#include "snake.h"

int check_collision(const node_t *node_list, int length, const node_t *node);
int collides(node_t a, node_t b);
#endif
