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
# include <stdlib.h>
# include <time.h>
 
int return_random(int lower, int upper)
{
    int num;

	num = (rand() % (upper - lower + 1)) + lower;
	return (num);
}

int main()
{
	setlocale(LC_ALL, "");

	Window			window;
	std::string 	choices[2] {"NEW GAME", "  EXIT  "};
	int				choice;
	int				highlight = 0;

	window.print_header();
	keypad(window.main, true);
	srand(time(0));
	while (1)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (i == highlight)
				wattron(window.main, A_REVERSE);
			mvwprintw(window.main, i + 9, 26 - 4, choices[i].c_str());
			wattroff(window.main, A_REVERSE);
		}
		choice = wgetch(window.main);
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
	clear();
	if (highlight == 0)
	{
		window.print_board();

		State	game_state;

		// start position of player
		game_state.player.x = WIDTH / 2;
		game_state.player.y = HEIGHT - 4;

		// TEST enemy
		Enemy e(return_random(1, window.width - 2), 1);
		game_state.enemies.push_back(e);

		while (42)
		{
			if (game_state.cur_key == 'q')
				break ;
			game_state.update();
			window.render(game_state);
			usleep(1000);
			game_state.cur_key = wgetch(window.main);
			if (game_state.cur_key == KEY_RESIZE)
			{
				window.print_board();
			}
		}
	}
	return (0);
}
