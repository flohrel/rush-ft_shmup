# include "State.hpp"

State::State()
: player(1, 1), chrono(), cur_key(0)
{ }

State::~State()
{ }

void	State::update()
{
	switch (cur_key)
	{
		case 'w':
			player.y = player.y - 1;
			break ;
		case 's':
			player.y = player.y + 1;
			break ;
		case 'a':
			player.x = player.x - 2;
			break ;
		case 'd':
			player.x = player.x + 2;
			break ;
		default:
			break ;
	}
	cur_key = 0;
}