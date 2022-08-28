# include "Entity.hpp"
# include <string.h>
# include <cwchar>

Entity::Entity( void )
: x(0), y(0), dude(""), speed(0)
{ }

Entity::Entity( double x, double y )
: x(x), y(y), speed(0)
{ }

Entity::Entity( const Entity& src )
: x(src.x), y(src.y), speed(src.speed)
{ }

Entity::~Entity()
{ }

Entity&	Entity::operator=( const Entity& rhs )
{
	x = rhs.x;
	y = rhs.y;
	return (*this);
}

bool		Entity::operator==( const Entity& rhs )
{
	return ( ( x == rhs.x ) && ( y == rhs.y ) );
}