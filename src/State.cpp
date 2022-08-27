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
		case KEY_UP:
			player.x = player.y - 1;
			break ;
		case KEY_DOWN:
			player.x = player.y + 1;
			break ;
		case KEY_LEFT:
			player.y = player.x - 2;
			break ;
		case KEY_RIGHT:
			player.y = player.x + 2;
			break ;
		default:
			break ;
	}
	cur_key = 0;
}