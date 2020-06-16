#ifndef COLLISION_H_
#define COLLISION_H_

#include "snake.h"

int check_collision(const node_t *node_list, const int length, const node_t *node);
int collides(const node_t a, const node_t b);
#endif
