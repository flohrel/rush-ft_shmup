# include "Window.hpp"

Window::Window() : width(0), height(0)
{
	// sets up memory and clears the screen
	initscr();

	// initialises use of colors
	if (start_color() == ERR)
		exit(EXIT_FAILURE);

	// intialises use of special keys (F1, arrows, ...)
	keypad(stdscr, true);

	// getch() is not blocking
//	nodelay(stdscr, true);

	// don't print char read by getch()
	noecho();

	// disable line buffering without disabling signal processing
	cbreak();

	// don't show cursor
	curs_set(false);

	refresh();

	// initialisation of color pairs (fg / bg)
	init_pair(1, COLOR_BLACK, COLOR_WHITE);

	getmaxyx(stdscr, height, width);
	main = newwin(height, width, 0, 0);
}

Window::~Window()
{
	// deallocate memory
    if (endwin() == ERR)
		exit(EXIT_FAILURE);
}
