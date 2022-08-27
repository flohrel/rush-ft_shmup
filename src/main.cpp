# include "Window.hpp"
# include "State.hpp"
# include <cstdio>
# include <charconv>
# include <cstring>
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

	Window	window;

	box(window.main, 0 , 0);

	State	game_state;

	while (42)
	{
		game_state.cur_key = wgetch(window.main);
		if (game_state.cur_key == 'q')
			break ;
		game_state.update();
		window.render(game_state);
		usleep(10000);
	}

	return (0);
}