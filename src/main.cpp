# include "Window.hpp"
# include <cstdio>
# include <charconv>
# include <cstring>

int main()
{
	Window	window;
	getmaxyx(stdscr, window.height, window.width);

	char buf[20];
	bzero(buf, 20);
	std::to_chars(buf, buf + 20, window.width);
	mvprintw(0, 0, "width = ");
	printw(buf);
	bzero(buf, 20);
	std::to_chars(buf, buf + 20, window.height);
	mvprintw(1, 0, "height = ");
	printw(buf);
	getch();
	return (0);
}