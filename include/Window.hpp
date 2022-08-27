#ifndef __INTERFACE__H__
# define __INTERFACE__H__

# include <iostream>
# include <ncurses.h>

class Coordinate
{

public:
	Coordinate( void )
	: x(0), y(0), width(this->x), height(this->y)
	{ }

	Coordinate( uint64_t x, uint64_t y )
	: x(x), y(y), width(this->x), height(this->y)
	{ }

	~Coordinate()
	{ }

	Coordinate&	operator=( const Coordinate& rhs )
	{
		x = rhs.x;
		y = rhs.y;
		return (*this);
	}

	bool		operator==( const Coordinate& rhs )
	{
		return ( ( x == rhs.x ) && ( y == rhs.y ) );
	}

	uint64_t	x;
	uint64_t	y;
	uint64_t&	width;
	uint64_t&	height;

};

class Window : public Coordinate
{

public:
	Window();
	~Window();

	WINDOW*		main;

};

#endif