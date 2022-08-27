# include "Window.hpp"
# include <cstdio>
# include <charconv>
# include <cstring>

/*
	- 3 different windows :
		- game title + keys + menu (play / exit)
		- game mode (top box with score / life + game box)
		- game over (score + replay / exit menu)

*/

int main()
{
	Window	window;
	box(window.main, 0 , 0);
	wrefresh(window.main);
	getch();
	return (0);
}