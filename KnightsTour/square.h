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

	//setters
	void setXPos(int x) {
		xPos = x;
	}

	void setYPos(int y) {
		yPos = y;
	}

	void setNumMoves(int n) {
		numMoves = n;
	}

	void setOrder(int o) {
		order = o;
	}

	void setTouch(bool t) {
		touch = t;
	}

	//getters
	int getXPos() {
		return xPos;
	}

	int getYPos() {
		return yPos;
	}

	int getNumMoves() {
		return numMoves;
	}

	int getTouch() {
		return touch;
	}

	int getOrder() {
		return order;
	}

	void setCoords(int y, int x);

	//private data members
 private:

	int numMoves = 0;
	int xPos = 0;
	int yPos = 0;
	bool touch = false;
	int order = 0;

};
