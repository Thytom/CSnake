#ifndef APPLE_H_
#define APPLE_H_

#include <time.h>

#include "snake.h"
#include "collision.h"

void move_apple(const snake_t *s, node_t *apple ,
		int term_x, int term_y);
node_t *new_apple(const snake_t *s, int term_x, int term_y);

#endif
