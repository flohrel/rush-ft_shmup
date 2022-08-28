#ifndef __Enemy__H__
# define __Enemy__H__

# include "Entity.hpp"
# include <ncurses.h>
# include <string>
# include <ctime>

class Enemy : public Entity
{

public:
	Enemy();
	Enemy(double x, double y);

	std::string			dude;
	bool				alive;

};

#endif
