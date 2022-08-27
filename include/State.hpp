#ifndef __STATE__H__
# define __STATE__H__

# include "Time.hpp"
# include "Player.hpp"
# include "Window.hpp"

class Window;

class State
{

public:
	State();
	~State();

	void	update(Window window);

	Player	player;
	Time	chrono;
	wchar_t	cur_key;
	int		status;
	
};

#endif