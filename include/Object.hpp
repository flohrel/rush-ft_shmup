#ifndef __OBJECT__H__
# define __OBJECT__H__

# include "Entity.hpp"
# include <ncurses.h>
# include <string>
# include <ctime>

class Object : public Entity
{

public:
	Object();
	Object(double x, double y, int i);

	std::string			dude;
	unsigned			speed;
	int					origin;

};

#endif
