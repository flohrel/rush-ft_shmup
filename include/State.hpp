#ifndef __STATE__H__
# define __STATE__H__

# include <list>
# include "Time.hpp"
# include "Player.hpp"
# include "Enemy.hpp"
# include "Window.hpp"

class Window;

class State
{

public:
	State();
	~State();

	void	update(Window window);

	Player				player;
	std::list< Enemy >	enemies;
	Time				chrono;
	int					cur_key;
	int					status;
	
};

#endif