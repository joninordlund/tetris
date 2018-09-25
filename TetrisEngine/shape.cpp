#include <random>
#include "shape.h"

//const int Shape::colorList[] = {1,2,3,4,5,6,7};

Shape::Shape(const array<int32_t, 4>& bList) :
	blockList(bList),
	rotation(0)
{
	setRndColor();
}

void Shape::setRndColor()
{
	std::uniform_int_distribution<int> distribution(1,5);
	std::random_device engine;
	color = distribution(engine);
}

