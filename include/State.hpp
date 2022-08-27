#ifndef __STATE__H__
# define __STATE__H__

# include "Time.hpp"
# include "Player.hpp"

class State
{

	friend class Window;

public:
	State();
	~State();

	void	update();

	Player	player;
	Time	chrono;
	wchar_t	cur_key;
	int		status;
	
};

#endif