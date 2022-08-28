#ifndef __Objects__H__
# define __Objects__H__

# include "Entity.hpp"
# include <ncurses.h>
# include <string>
# include <ctime>

class Objects : public Entity
{

public:
	Objects();
	Objects(double x, double y);

	std::string			dude;

};

#endif
