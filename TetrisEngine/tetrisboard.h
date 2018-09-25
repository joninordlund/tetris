#ifndef TETRISBOARD_H
#define TETRISBOARD_H

#include <array>
#include <vector>
	
class Shape;

class TetrisBoard
{
	public:
		static const int width = 20;
		static const int height = 30;
		
		typedef std::vector<std::array<int, width>> Grid; 

		TetrisBoard();
	
		void newBlock();
		void moveDown();
		void moveRight();
		void moveLeft();
		void rotate();
		void checkFullRows(); 
		int getScore() {return score;}
		bool isGameOver() {return gameOver;}
		Grid getGrid();
		
	private:	
		void setCurrBlock(int xPos, int yPos);
		
		bool isValidPos(int xPos, int YPos);
		void removeCurrBlock();
		void paintCurrBlock(int color);
		
		Shape* currShape;
		int blkXpos;
		int blkYpos;
		int score;
		bool gameOver;
		Grid grid;
};

#endif
