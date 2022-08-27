#ifndef __Entity__H__
# define __Entity__H__

# include <cstdlib>

class Entity
{

public:
	Entity();
	Entity( double x, double y, const wchar_t ws[3] );
	Entity( const Entity& src );
	virtual ~Entity();

	virtual Entity&	operator=( const Entity& rhs );
	virtual bool		operator==( const Entity& rhs );

	double	x;
	double	y;
	wchar_t	dude[3];

};

#endif