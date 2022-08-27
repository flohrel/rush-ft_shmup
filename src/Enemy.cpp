#include "Enemy.hpp"

Enemy::Enemy()
: Entity()
{ }

Enemy::Enemy(double x, double y)
: Entity(x, y)
{
	dude = "◹◸";
}
