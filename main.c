#include "main.h"

int main(int argc, char *argv[])
{
	// Ncurses setup
	initscr();
	noecho();
	timeout(0);
	curs_set(0);

	int term_x;
	int term_y;

	getmaxyx(stdscr, term_y, term_x); // Get terminal size

	int game_state = RUNNING;
	snake_t *snake = create_snake(term_x / 2, term_y / 2,
			DEFAULT_SNAKE_START_DIR, DEFAULT_SNAKE_START_LEN);
	node_t *apple = new_apple(snake, term_x, term_y);
	int score = 0;
	char input;

	while(game_state != FINISHED)
	{
		getmaxyx(stdscr, term_y, term_x);

		clock_t initial_time = clock();

		int direction = CURRENT_DIRECTION;
		switch(input = getch())
		{
			case CSNAKE_OPT_MOVE_UP: direction = UP; break;
			case CSNAKE_OPT_MOVE_DOWN: direction = DOWN; break;
			case CSNAKE_OPT_MOVE_LEFT: direction = LEFT; break;
			case CSNAKE_OPT_MOVE_RIGHT: direction = RIGHT; break;
			case CSNAKE_OPT_EXIT: game_state = FINISHED; break;
			default: break;
		}
		clear_snake(stdscr, snake);
		move_snake_wrap(snake, direction, term_x, term_y);
		draw_snake(stdscr, snake);

		if(collides(*snake->body, *apple))
		{
			grow_snake(snake, 1);
			move_apple(snake, apple, term_x, term_y);
			score++;
		}
		mvaddch(apple->y, apple->x, '@');

		int ticks = (clock() - initial_time);
		float seconds = ticks / CLOCKS_PER_SEC;
		int nanosecs = 1000000000 * seconds;
		const struct timespec frame[] = {
			{0, (1000000000/FRAMERATE) - nanosecs}
		};
		nanosleep(frame, NULL);
	}

	endwin();

	printf("Game Over! Final Score: %d\n", score);

	free_snake(snake);
	free(apple);
	return 0;
}
