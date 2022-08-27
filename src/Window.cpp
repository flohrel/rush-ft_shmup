# include "Window.hpp"

Window::Window()
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

	// initialisation of color pairs (fg / bg)
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
}

Window::~Window()
{
	// deallocate memory
    if (endwin() == ERR)
		exit(EXIT_FAILURE);
}
