# include "Window.hpp"
# include "State.hpp"
# include "Define.hpp"
# include <cstdio>
# include <charconv>
# include <cstring>
# include <ncurses.h>
# include <string>
# include <locale.h>
# include <unistd.h>

/*
	- 3 different windows :
		- game title + keys + menu (play / exit)
		- game mode (top box with score / life + game box)
		- game over (score + replay / exit menu)

*/

int main()
{
	setlocale(LC_ALL, "");

	Window			window;
	WINDOW			*menu;
	int				xmax;
	int				ymax;
	std::string 	choices[2] {"NEW GAME", "  EXIT  "};
	int				choice;
	int				highlight = 0;

	box(window.main, 0, 0);
	getmaxyx(window.main, ymax, xmax);
	menu = newwin(13, 55, 2, xmax / 2 - 26);
	box(menu, '*', '*');
	wrefresh(window.main);
	mvwprintw(menu, 1, 1, "  _____  __            .__                           ");
	mvwprintw(menu, 2, 1, "_/ ____\\/  |_     _____|  |__   _____  __ ________   ");
	mvwprintw(menu, 3, 1, "\\   __\\   __\\   /  ___/  |  \\ /     \\|  |  \\____ \\  ");
	mvwprintw(menu, 4, 1, " |  |   |  |     \\___ \\|   Y  \\  Y Y  \\  |  /  |_> > ");
	mvwprintw(menu, 5, 1, " |__|   |__|____/____  >___|  /__|_|  /____/|   __/  ");
	mvwprintw(menu, 6, 1, "          /_____/    \\/     \\/      \\/      |__|     ");
	mvwprintw(menu, 7, 1, "                 A terminal shooter                  ");
	wrefresh(menu);
	keypad(menu, true);
	while (1)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (i == highlight)
				wattron(menu, A_REVERSE);
			mvwprintw(menu, i + 9, 26 - 4, choices[i].c_str());
			wattroff(menu, A_REVERSE);
		}
		choice = wgetch(menu);
		switch (choice)
		{
		case KEY_UP:
			highlight--;
			if (highlight == -1)
				highlight = 0;
			break;
		case KEY_DOWN:
			highlight++;
			if (highlight == 2)
				highlight = 1;
			break;
		default:
			break;
		}
		if (choice == 10)
			break;
	}
	if (highlight == 0)
	{
		State	game_state;

		// start position of player
		game_state.player.x = window.width / 2;
		game_state.player.y = window.height - 3;

		// TEST enemy
		Enemy e(window.width / 2, 1);
		game_state.enemies.push_back(e);

		while (42)
		{
			if (game_state.cur_key == 'q')
				break ;
			game_state.update(window);
			window.render(game_state);
			usleep(10000);
			game_state.cur_key = wgetch(window.main);
		}
	}
	else if (highlight == 1)
	{
		delwin(menu);
		endwin();
		exit(0);
	}
	return (0);
}
