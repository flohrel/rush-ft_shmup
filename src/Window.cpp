# include "Window.hpp"

Window::Window() : width(0), height(0)
{
	// sets up memory and clears the screen
	initscr();

	// initialises use of colors
	if (start_color() == ERR)
		exit(EXIT_FAILURE);

	// getch() is not blocking
	nodelay(stdscr, true);

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

void	Window::render(State game_state)
{
	werase(main);
	box(main, 0 , 0);
	mvwprintw(main, game_state.player.y, game_state.player.x, game_state.player.dude.c_str());
	for (auto e = game_state.enemies.begin(); e != game_state.enemies.end(); e++)
	{
		mvwprintw(main, e->y, e->x, e->dude.c_str());
	}
	wrefresh(main);
}
