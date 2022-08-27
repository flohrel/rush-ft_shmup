# include "Window.hpp"
# include <cstdio>
# include <charconv>
# include <cstring>
# include <ncurses.h>
# include <string>
using namespace std;

/*
	- 3 different windows :
		- game title + keys + menu (play / exit)
		- game mode (top box with score / life + game box)
		- game over (score + replay / exit menu)

*/

int main()
{
	Window	window;
	WINDOW	*menu;
	int		xmax;
	int		ymax;
	string 	choices[2] {"NEW GAME", "  EXIT  "};
	int		choice;
	int		highlight = 0;

	box(window.main, 0 , 0);
	getmaxyx(window.main, ymax, xmax);
	menu = newwin(13, 55, 1, xmax / 2 - 26);
	box(menu, 0, 0);
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
	getch();
	return (0);
}