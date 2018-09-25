#ifndef SHAPESTORE_H
#define SHAPESTORE_H

#include <array>

class Shape;
using namespace std;

class ShapeStore {

public:
	Shape* getRndShape();
	static ShapeStore& instance();
	
private:
	ShapeStore();

	array<Shape*, 7> shapeList;
};

#endif
