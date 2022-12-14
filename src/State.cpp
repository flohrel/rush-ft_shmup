# include "State.hpp"


State::State()
: player(0, 0), chrono(), cur_key(0), line(MAP_HEIGHT - 42)
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
			Object e(player.x, player.y - 1, -1);
			bullets.push_back(e);
			break;
		}
		default:
			break ;
	}
	for (auto e = enemies.begin(); e != enemies.end(); e++)
	{
		if ( (static_cast<int>(e->x) == static_cast<int>(player.x)
				|| static_cast<int>(e->x) == static_cast<int>(player.x - 1)
				|| static_cast<int>(e->x) == static_cast<int>(player.x + 1))
				&& static_cast<int>(e->y) == static_cast<int>(player.y) )
		{
			life = 0;
		}
	}
	for (auto e = bullets.begin(); e != bullets.end(); e++)
	{
		if ( (static_cast<int>(e->x) == static_cast<int>(player.x)
				|| static_cast<int>(e->x) == static_cast<int>(player.x - 1)
				|| static_cast<int>(e->x) == static_cast<int>(player.x + 1))
				&& static_cast<int>(e->y) == static_cast<int>(player.y) )
		{
			life = 0;
		}
	}
	for (auto e = bullets.begin(); e != bullets.end(); e++)
	{
		bool	sry = false;
		for (auto f = enemies.begin(); f != enemies.end(); f++)
		{ 
			if ( (static_cast<int>(e->x) == static_cast<int>(f->x)
				|| static_cast<int>(e->x) == static_cast<int>(f->x - 1)
				|| static_cast<int>(e->x) == static_cast<int>(f->x + 1))
				&& static_cast<int>(e->y) == static_cast<int>(f->y) )
			{
				f->alive = false;
				score += 10;
				sry = true;
			}
		}
		e->y += (e->origin * (chrono.frame_time * BULLET_SPEED));
		if ( e->y < 1 || sry == true)
		{
			auto tmp = e;
			e--;
			bullets.erase(tmp);
			sry = false;
		}
	}
	if (line > 1)
		line -= (1 * (chrono.frame_time * MAP_SPEED));
	cur_key = 0;
}