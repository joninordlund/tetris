
#include "shapestore.h"
#include "shape.h"
#include "consts.h"

#include <random>
#include <inttypes.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

ShapeStore::ShapeStore(): shapeList(
		{{new Shape(shape1), new Shape(shape2), new Shape(shape3), 
		new Shape(shape4), new Shape(shape5), new Shape(shape6), new Shape(shape7)}})
{}

Shape* ShapeStore::getRndShape() {
	uniform_int_distribution<int> dist(0,NUM_SHAPES - 1);
	random_device engine;
	Shape* rndShape = shapeList[dist(engine)];
	rndShape->setRndColor();
	rndShape->setRotation(0);
	return rndShape;
}

ShapeStore& ShapeStore::instance()
{
	static ShapeStore instance;
	return instance;
}
