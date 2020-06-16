#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ncurses.h>

#include "snake.h"
#include "apple.h"

#define RUNNING 0
#define FINISHED 1

#define FRAMERATE 25

#define CSNAKE_OPT_EXIT			'q'
#define CSNAKE_OPT_MOVE_UP		'w'
#define CSNAKE_OPT_MOVE_DOWN	's'
#define CSNAKE_OPT_MOVE_LEFT	'a'
#define CSNAKE_OPT_MOVE_RIGHT	'd'

#endif
