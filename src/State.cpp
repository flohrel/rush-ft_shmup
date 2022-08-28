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
//
//void	shoot(int x, int y, int lim, WINDOW *main)
//{
//	int px;
//	int py;
//	int	j;
//
//	px = x;
//	py = y - 1;
//	j = 0;
//	for (int i = py; i > lim; i--)
//	{
//		mvwprintw(main, py - j, px, " ");
//		mvwprintw(main, py - j++, px, "▕");
//		if (getchar_at(py - j, px, main) != '\0')
//		{
//			mvwprintw(main, py, px, "*");
//		}
//		wrefresh(main);
//	}
//}

void	State::update(Window window)
{
	switch (cur_key)
	{
		case 'w':
			if ( --player.y == 0 )
			{
				player.y++;
			}
			break ;
		case 's':
			if ( ++player.y > window.height - 2 )
			{
				player.y--;
			}
			break ;
		case 'a':
			if ( (player.x -= 2) <= 0 )
			{
				player.x = 1;
			}
			break ;
		case 'd':
			if ( (player.x += 2) >= (window.width - 2) )
			{
				player.x = window.width - 3;
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