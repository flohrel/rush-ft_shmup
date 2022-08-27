# include "Entity.hpp"

Entity::Entity( void )
: x(0), y(0)
{ }

Entity::Entity( unsigned int x, unsigned int y )
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