#ifndef __INTERFACE__H__
# define __INTERFACE__H__

# include <iostream>
# include <ncurses.h>

class Window
{

public:
	Window();
	~Window();

	WINDOW*			stdscr;

};

#endif