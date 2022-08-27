# include "Entity.hpp"
# include <string.h>
# include <cwchar>

Entity::Entity( void )
: x(0), y(0), dude("")
{ }

Entity::Entity( double x, double y )
: x(x), y(y)
{ }

Entity::Entity( const Entity& src )
: x(src.x), y(src.y)
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