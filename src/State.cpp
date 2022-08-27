# include "State.hpp"

State::State()
: player(0, 0), chrono(), cur_key(0)
{ }

State::~State()
{ }

void	State::update(Window window)
{
	switch (cur_key)
	{
		case 'w':
			if ( --player.y == 0 )
				player.y++;
			break ;
		case 's':
			if ( ++player.y > window.height - 2 )
				player.y--;
			break ;
		case 'a':
			if ( (player.x -= 2) <= 0 )
				player.x = 1;
			break ;
		case 'd':
			if ( (player.x += 2) >= (window.width - 2) )
				player.x = window.width - 3;
			break ;
		default:
			break ;
	}
	cur_key = 0;
}