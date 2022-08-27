#ifndef __Entity__H__
# define __Entity__H__

# include <cstdlib>

class Entity
{

public:
	Entity();
	Entity( unsigned int x, unsigned int y );
	Entity( const Entity& src );
	virtual ~Entity();

	virtual Entity&	operator=( const Entity& rhs );
	virtual bool		operator==( const Entity& rhs );

	double	x;
	double	y;

};

#endif