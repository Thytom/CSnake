#include "main.h"

int main(int argc, char *argv[])
{
	initscr();
	noecho();
	timeout(0);
	curs_set(0);

	getch();

	endwin();
	return 0;
}
