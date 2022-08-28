#include "Object.hpp"

Object::Object()
: Entity()
{ }

Object::Object(double x, double y, int i)
: Entity(x, y), origin(i)
{
	dude = "▕ ";
}
