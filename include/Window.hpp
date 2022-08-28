#ifndef __INTERFACE__H__
# define __INTERFACE__H__

# include <ncurses.h>
# include <cstdlib>
# include "State.hpp"

# define HEIGHT	42
# define WIDTH	100

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
	void	print_score(int points);

	WINDOW*			main;
	WINDOW*			score;
	unsigned int	width;
	unsigned int	height;

};

#endif