#include "Effect.hpp"

Effect::Effect()
: Object()
{ }

Effect::Effect(double x, double y, unsigned c)
: Object(x, y), counter(c)
{ }
