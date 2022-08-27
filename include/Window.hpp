#ifndef __INTERFACE__H__
# define __INTERFACE__H__

# include <ncurses.h>
# include <cstdlib>
# include "State.hpp"

class Window
{

public:
	Window();
	~Window();

	void	render(State game_state);

	WINDOW*			main;
	unsigned int	width;
	unsigned int	height;

};

#endif