# include "Window.hpp"

Window::Window()
{
	// sets up memory and clears the screen
	stdscr = initscr();

	// initialises use of colors
	if (start_color() == ERR)
		exit(EXIT_FAILURE);

	// intialises use of special keys (F1, arrows, ...)
	keypad(stdscr, true);

	// getch() is not blocking
	nodelay(stdscr, true);

	// don't print char read by getch()
	noecho();

	// disable line buffering without disabling signal processing
	cbreak();

	// initialisation of color pairs (fg / bg)
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	init_pair(7, COLOR_GREEN, COLOR_BLACK);
}

Window::~Window()
{
	// deallocate memory
    if (endwin() == ERR)
		exit(EXIT_FAILURE);
}
