#include "Object.hpp"

Object::Object()
: Entity()
{ }

Object::Object(double x, double y)
: Entity(x, y)
{
	dude = "▕ ";
}
