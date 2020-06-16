#ifndef APPLE_H_
#define APPLE_H_

#include <time.h>

#include "snake.h"

#define FULL_COL 0
#define HEAD_COL 1

void move_apple(const snake_t *s, node_t *apple ,
		const int term_x, const int term_y);
node_t *new_apple(const snake_t *s, const int term_x, const int term_y);

int check_collision(const snake_t *s, const node_t *apple, const int col_type);

#endif
