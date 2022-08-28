#ifndef __INTERFACE__H__
# define __INTERFACE__H__

# include <ncurses.h>
# include <cstdlib>
# include "State.hpp"
# include "define.hpp"

class State;

class Window
{

public:
	Window();
	~Window();

	void	render(State game_state);
	void	check_term_size();
	void	print_header();
	void	print_board();

	WINDOW*			main;
	unsigned int	width;
	unsigned int	height;

};

#endif