# include "State.hpp"


State::State()
: player(0, 0), chrono(), cur_key(0), line(160 - 42)
{ }

State::~State()
{ }

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
			Object e(player.x, player.y - 1);
			bullets.push_back(e);
			break;
		}
		default:
			break ;
	}
	for (auto e = bullets.begin(); e != bullets.end(); e++)
	{
		for (auto f = enemies.begin(); f != enemies.end(); f++)
		{ 
			if (e->x == f->x && e->y == f->y)
			{
				f->alive = false;
			}
		}
		e->y -= (1 * (chrono.frame_time * BULLET_SPEED));
		if ( e->y < 1 )
		{
			auto tmp = e;
			e--;
			bullets.erase(tmp);
		}
	}
	if (line > 1)
		line -= (1 * (chrono.frame_time * BULLET_SPEED));
	cur_key = 0;
}