#include "tetrisboard.h"
#include "shapestore.h"
#include "shape.h"

#include <cstdlib>
#include <inttypes.h>

using namespace std;

TetrisBoard::TetrisBoard() :
	score(0), gameOver(false)
{
	grid = Grid(height);
	newBlock();	
}

void TetrisBoard::newBlock()
{ 
	checkFullRows();
	score += 2;
	blkXpos = width / 2;
	blkYpos = 0;
	currShape = ShapeStore::instance().getRndShape();

	if(!isValidPos(blkXpos, blkYpos)){
		 gameOver = true;
	}
		else {
			setCurrBlock(blkXpos, blkYpos);
	}
}

void TetrisBoard::setCurrBlock(int xPos, int yPos)
{
	blkXpos = xPos;
	blkYpos = yPos;
	paintCurrBlock(currShape->getColor());
}

TetrisBoard::Grid TetrisBoard::getGrid()
{
	return grid;
}

void TetrisBoard::moveDown()
{
	removeCurrBlock();
	if(!isValidPos(blkXpos, blkYpos + 1)){
		setCurrBlock(blkXpos, blkYpos);
		newBlock();
	} 
	else {
		setCurrBlock(blkXpos, blkYpos + 1);
	}
}

void TetrisBoard::moveRight()
{
	if(blkXpos + currShape->getWidth() + 1 > width) return;
	removeCurrBlock();
	if(isValidPos(blkXpos + 1, blkYpos)){
		setCurrBlock(blkXpos + 1, blkYpos);
	}
	else {
		setCurrBlock(blkXpos, blkYpos);
	} 
}

void TetrisBoard::moveLeft()
{
	if(blkXpos - 1 < 0) return;
	removeCurrBlock();
	if(isValidPos(blkXpos - 1, blkYpos)){
		setCurrBlock(blkXpos - 1, blkYpos);
	} 
	else {
		setCurrBlock(blkXpos, blkYpos);
	}
}

// Private methods

bool TetrisBoard::isValidPos(int xPos, int yPos)
{
	if(	yPos > (height - currShape->getHeight()) || 
		xPos > (width - currShape->getWidth())){
			return false;
		} 
	uint32_t mask = 0x80000000;
	for(int y = 0; y < currShape->getHeight(); ++y){
		mask = 0x80000000 >> y*4;
		for(int x = 0; x < currShape->getWidth(); ++x){
			if(mask & currShape->getBlock() && 
				grid[yPos + y][xPos + x] != 0){
					return false;
			}
			mask = mask >> 1;
		}
	}
	return true;
}

void TetrisBoard::removeCurrBlock()
{
	paintCurrBlock(0); 
}

void TetrisBoard::paintCurrBlock(int color)
{
	uint32_t mask = 0x80000000;
	for(int y = 0; y < 4; ++y){
		for(int x = 0; x < 4; ++x){	
			mask & currShape->getBlock() ? 
				grid[blkYpos + y][blkXpos + x] = color : /* do nothing */ 0;
			mask = mask >> 1; 
		} 
	}
}

void TetrisBoard::rotate()
{
	int oldRot = currShape->getRotation();
	removeCurrBlock();
	currShape->setRotation((oldRot + 1) % 4);
	
	if(!isValidPos(blkXpos, blkYpos)){
		currShape->setRotation(oldRot);
	} 
	setCurrBlock(blkXpos, blkYpos);
}

void TetrisBoard::checkFullRows()
{
	static int count = 0;
	for(int y = height - 1; y >= 0; --y){
		int x;
		for(x = 0; x < width; ++x){
			if(grid[y][x] == 0) break;
		}
		if(x == width){
			score += 10 + count * 5;
			count++;
			grid.erase(grid.begin() + y);
			array<int, width> arr;
			arr.fill(0);
			grid.insert(grid.begin(), arr);
			checkFullRows();
		}
	}
	count = 0;
}
