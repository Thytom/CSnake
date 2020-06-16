#ifndef APPLE_H_
#define APPLE_H_

#include <time.h>

#include "snake.h"

void move_apple(const snake_t *s, node_t *apple ,
		const int term_x, const int term_y);
node_t *new_apple(const snake_t *s, const int term_x, const int term_y);

int check_collision(const node_t *node_list, const int length, const node_t *node);
int collides(const node_t a, const node_t b);

#endif
