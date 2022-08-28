#ifndef __STATE__H__
# define __STATE__H__

# include <list>
# include <unistd.h>
# include "Time.hpp"
# include "Player.hpp"
# include "Enemy.hpp"
# include "Window.hpp"
# include "Objects.hpp"
# include "define.hpp"

class Window;

class State
{

public:
	State();
	~State();

	void	update();

	Player					player;
	std::list< Enemy >		enemies;
	std::list< Objects >	bullets;
	Time					chrono;
	int						cur_key;
	int						status;
	
};

#endif