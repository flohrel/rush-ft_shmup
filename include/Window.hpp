#ifndef __INTERFACE__H__
# define __INTERFACE__H__

# include <ncurses.h>
# include <cstdlib>
# include "State.hpp"
# include "define.hpp"
# include <time.h>

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
	void	print_score(int points, clock_t t, double time_taken);

	WINDOW*			main;
	WINDOW*			score;
	unsigned int	width;
	unsigned int	height;

};

#endif