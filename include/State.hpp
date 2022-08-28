#ifndef __STATE__H__
# define __STATE__H__

# include <list>
# include "Time.hpp"
# include "Player.hpp"
# include "Enemy.hpp"
# include "Window.hpp"
# include "Objects.hpp"

class Window;

class State
{

public:
	State();
	~State();

	void	update(Window window);

	Player				player;
	std::list< Enemy >	enemies;
	std::list< Objects >	bullets;
	Time				chrono;
	int					cur_key;
	int					status;
	
};

#endif