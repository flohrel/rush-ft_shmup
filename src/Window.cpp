# include "Window.hpp"
# include <ncurses.h>
# include <unistd.h>

Window::Window() : width(0), height(0)
{
	// sets up memory and clears the screen
	initscr();

	// initialises use of colors
	if (start_color() == ERR)
		exit(EXIT_FAILURE);

	// don't print char read by getch()
	noecho();

	// disable line buffering without disabling signal processing
	cbreak();

	// don't show cursor
	curs_set(false);

	refresh();

	// initialisation of color pairs (fg / bg)
	init_pair(1, COLOR_BLACK, COLOR_WHITE);

	check_term_size();
}

Window::~Window()
{
	delwin(main);
	// deallocate memory
    if (endwin() == ERR)
		exit(EXIT_FAILURE);
}

void	Window::render(State game_state)
{
	werase(main);
	box(main, 0 , 0);
	mvwprintw(main, game_state.player.y, game_state.player.x, game_state.player.dude.c_str());
	for (int line = 0; line != 42; line++)
	{
		for (int col = 0; col != 50; col++)
		{
			int	x = col * 2;
			int y = static_cast<int>(game_state.line) + line;
			char c = game_state.map[y][col];
			switch (c)
			{
				case 'X':
					mvwprintw(main, line, x, "XX");
					break ;
				case 'S':
					mvwprintw(main, line, x, "SS");
					break ;
				case '=':
					mvwprintw(main, line, x, "=");
					break ;
				case 'x':
					mvwprintw(main, line, x, "x");
					break ;
				case '.':
					mvwprintw(main, line, x, ".");
					break ;
			}
		}
	}
	for (auto e = game_state.enemies.begin(); e != game_state.enemies.end(); e++)
	{ 
		if (e->alive == false)
		{
			mvwprintw(main, e->y, e->x, "XX");
		}
		else
			mvwprintw(main, e->y, e->x, e->dude.c_str());
	}
	for (auto e = game_state.bullets.begin(); e != game_state.bullets.end(); e++)
	{
		mvwprintw(main, e->y, e->x, e->dude.c_str());
	}
	wnoutrefresh(main);
	doupdate();
}

void	Window::check_term_size()
{
	getmaxyx(stdscr, height, width);
	if ( height < HEIGHT || width < WIDTH )
	{
		delwin(main);
		endwin();
		exit(EXIT_FAILURE);
	}
}

void	Window::print_header()
{
	main = newwin(13, 55, 2, width / 2 - 26);
	box(main, '*', '*');
	mvwprintw(main, 1, 1, "  _____  __            .__                           ");
	mvwprintw(main, 2, 1, "_/ ____\\/  |_     _____|  |__   _____  __ ________   ");
	mvwprintw(main, 3, 1, "\\   __\\   __\\   /  ___/  |  \\ /     \\|  |  \\____ \\  ");
	mvwprintw(main, 4, 1, " |  |   |  |     \\___ \\|   Y  \\  Y Y  \\  |  /  |_> > ");
	mvwprintw(main, 5, 1, " |__|   |__|____/____  >___|  /__|_|  /____/|   __/  ");
	mvwprintw(main, 6, 1, "          /_____/    \\/     \\/      \\/      |__|     ");
	mvwprintw(main, 7, 1, "                 A terminal shooter                  ");
	wrefresh(main);
}

void	Window::print_board()
{
	werase(main);
	wnoutrefresh(main);
	doupdate();
	delwin(main);
	check_term_size();
	main = newwin(HEIGHT, WIDTH, ( (height - HEIGHT) / 2), ( (width - WIDTH) / 2));
	keypad(main, true);
	nodelay(main, true);
}