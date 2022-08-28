# include "State.hpp"
# include "Objects.hpp"
# include <unistd.h>
# include <ncurses.h>
#include "Define.hpp"


State::State()
: player(0, 0), chrono(), cur_key(0)
{ }

State::~State()
{ }

//chtype getchar_at(int y, int x, WINDOW *main)
//{
//	return (mvwinch(main, y, x));
//}

void	State::update()
{
	switch (cur_key)
	{
		case KEY_UP:
			if ( --player.y == 0 )
			{
				player.y++;
			}
			break ;
		case KEY_DOWN:
			if ( ++player.y > HEIGHT - 2 )
			{
				player.y--;
			}
			break ;
		case KEY_LEFT:
			if ( (player.x -= 2) <= 0 )
			{
				player.x = 1;
			}
			break ;
		case KEY_RIGHT:
			if ( (player.x += 2) >= (WIDTH - 2) )
			{
				player.x = WIDTH - 3;
			}
			break ;
		case ' ':
		{
			//shoot(player.x, player.y, 0, window.main);
			Objects e(player.x, player.y - 1);
			bullets.push_back(e);
			break;
		}
		default:
			break ;
	}
	for (auto e = bullets.begin(); e != bullets.end(); e++)
	{
		e->y--;
	}
	cur_key = 0;
}