#ifndef EFFECT_H
# define EFFECT_H

# include "Object.hpp"

class Effect : public Object
{

public:
	Effect();
	Effect(double x, double y, unsigned c);

	std::string			dude;
	unsigned			counter;

};

#endif