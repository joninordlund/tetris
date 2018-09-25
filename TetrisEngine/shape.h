
#ifndef SHAPE_H
#define SHAPE_H

#include <inttypes.h>
#include <array>

using namespace std;

class Shape {
	
	public:
		Shape(const array<int32_t, 4>& rowList);
	
		int32_t getBlock() {return blockList[rotation];}
		
		int getColor() {return color;}
		int getWidth() {return (blockList[rotation] >> 8) & 0xff;}
		int getHeight() {return blockList[rotation] & 0xff;}
		
		void setRndColor();
		void setRotation(int rot) {rotation = rot;}
		int getRotation() {return rotation;}
		
	private:
		array<int32_t, 4> blockList;
		int rotation;
		int color;
		static const int colorList[];
};

#endif
