# include "Entity.hpp"
# include <cwchar>

Entity::Entity( void )
: x(0), y(0), dude(L"")
{ }

Entity::Entity( double x, double y, const wchar_t ws[3])
: x(x), y(y)
{
	wcsncpy(dude, ws, 3);
}

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