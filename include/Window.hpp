#ifndef __INTERFACE__H__
# define __INTERFACE__H__

# include <ncurses.h>
# include <cstdlib>

class Window
{

public:
	Window();
	~Window();

	WINDOW*			main;
	unsigned int	width;
	unsigned int	height;

};

#endif