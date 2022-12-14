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
	for ( int i = MAP_HEIGHT; i != 0; )
	{
		i--;
		std::string line;
		std::getline(infile, line);
		memcpy(game_state.map[i], line.c_str(), 50);
	}
	infile.close();
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
		case KEY_RESIZE:
			window.print_header();
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

		// initiate score to 0;
		game_state.score = 0;
		game_state.life = 1;

		// TIME
		clock_t t;
		double time_taken = 0.0;
   		t = clock();
		while (42)
		{
			if (game_state.cur_key == 'q')
				break ;
			if (return_random(0, 10000) > 9999)
			{
				Enemy e(return_random(4, WIDTH - 8), return_random(4, HEIGHT - 20));
				Object o(e.x, e.y + 2, 1);
				game_state.enemies.push_back(e);
				game_state.bullets.push_back(o);
			}
			game_state.update();
			window.render(game_state);
			window.print_score(game_state, t, time_taken);
			game_state.cur_key = wgetch(window.main);
			if (game_state.cur_key == KEY_RESIZE)
			{
				window.print_board();
				window.print_score(game_state, t, time_taken);
			}
			game_state.chrono.get_fps();
			if (!game_state.life)
				break ;
		}
		window.print_game_over();
	}
	return (0);
}
