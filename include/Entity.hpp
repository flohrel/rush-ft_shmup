#ifndef __Entity__H__
# define __Entity__H__

# include <cstdlib>
# include <string>

class Entity
{

public:
	Entity();
	Entity( double x, double y );
	Entity( const Entity& src );
	virtual ~Entity();

	virtual Entity&		operator=( const Entity& rhs );
	virtual bool		operator==( const Entity& rhs );

	double				x;
	double				y;
	std::string			dude;
	unsigned			speed;

};

#endif