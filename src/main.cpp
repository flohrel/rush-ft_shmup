# include "Window.hpp"
# include "State.hpp"
# include "define.hpp"
# include <cstdio>
# include <charconv>
# include <cstring>
# include <fstream>
# include <ncurses.h>
# include <string>
# include <locale.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

# include <iostream>

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
	State			game_state;
	std::string 	choices[2] {"NEW GAME", "  EXIT  "};
	int				choice;
	int				highlight = 0;

	window.print_header();
	keypad(window.main, true);
	srand(time(0));
	std::ifstream infile(MAP_FILE);
	for (int i = 0; i != 161; i++)
	{
		std::string line;
		std::getline(infile, line);
		std::cout << line << std::endl;
		memcpy(game_state.map[i], line.c_str(), 50);
	}
	exit(0);
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

		// start position of player
		game_state.player.x = WIDTH / 2;
		game_state.player.y = HEIGHT - 4;

		// TEST enemy
		Enemy e(return_random(1, WIDTH - 2), 1);
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
			game_state.chrono.get_fps();
		}
	}
	return (0);
}