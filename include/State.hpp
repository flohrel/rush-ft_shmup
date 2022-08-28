#ifndef __STATE__H__
# define __STATE__H__

# include <list>
# include <unistd.h>
# include "Time.hpp"
# include "Player.hpp"
# include "Enemy.hpp"
# include "Window.hpp"
# include "Object.hpp"
# include "Effect.hpp"
# include "define.hpp"

class Window;

class State
{

public:
	State();
	~State();

	void	update();

	char					map[MAP_HEIGHT][WIDTH / 2];
	Player					player;
	std::list< Enemy >		enemies;
	std::list< Object >		bullets;
	std::list< Effect >		effects;
	Time					chrono;
	int						cur_key;
	double					line;
	int						score;
	
};

#endif