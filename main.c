#include "main.h"

int main(int argc, char *argv[])
{
	// Ncurses setup
	initscr();
	noecho();
	timeout(0);
	curs_set(0);

	const struct timespec frame[] = {
		{0, 1000000000/FRAMERATE}
	};

	int term_x;
	int term_y;

	getmaxyx(stdscr, term_y, term_x); // Get terminal size

	int game_state = RUNNING;
	snake_t *snake = create_snake(term_x / 2, term_y / 2,
			DEFAULT_SNAKE_START_DIR, DEFAULT_SNAKE_START_LEN);
	char input;

	while(game_state != FINISHED)
	{
		switch(input = getch())
		{
			case CSNAKE_OPT_MOVE_UP: break;
			case CSNAKE_OPT_MOVE_DOWN: break;
			case CSNAKE_OPT_MOVE_LEFT: break;
			case CSNAKE_OPT_MOVE_RIGHT: break;
			case CSNAKE_OPT_EXIT: game_state = FINISHED;
			default : break;
		}

		clear();
		draw_snake(stdscr, snake);
		nanosleep(frame, NULL);
	}

	endwin();
	return 0;
}
