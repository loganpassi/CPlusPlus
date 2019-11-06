/*
Logan Passi
04/26/19
Square.h

Header file for square objects
*/

#include <iostream>

using namespace std;

//square class
class square {

public:

	//default constructor
	square();

	//parameterized constructor
	square(int x, int y);

	//SETTERS

	//set X position of the square
	void setXPos(int x) {
		xPos = x;
	}

	//set Y position of the square
	void setYPos(int y) {
		yPos = y;
	}

	//set the number of moves the knight is able to move to from this square
	void setNumMoves(int n) {
		numMoves = n;
	}

	//set the order of which the knight had touched this square
	void setOrder(int o) {
		order = o;
	}

	//set if the square had been touched by the knight or not
	void setTouch(bool t) {
		touch = t;
	}


	//GETTERS

	//get the X position of the square
	int getXPos() {
		return xPos;
	}

	//get the Y position of the square
	int getYPos() {
		return yPos;
	}

	//get the number of moves the knight is able to move to from this square
	int getNumMoves() {
		return numMoves;
	}

	//get if the square has been touched by the knight or not
	bool getTouch() {
		return touch;
	}

	//get the order of which the knight had touched this square
	int getOrder() {
		return order;
	}

	//function that sets the coordinates of the square on the chessboard
	void setCoords(int x, int y);

	//private data members
 private:
	int numMoves = 0;
	int xPos = 0;
	int yPos = 0;
	bool touch = false;
	int order = 0;

};
