/*
Logan Passi
04/26/19
Square.cpp
*/

#include "square.h"


//default constructor
square::square() {
	int numMoves = 0;
	int xPos = 0;
	int yPos = 0;
};

//parameterized constructor
square::square(int y, int x) {
	int numMoves = 0;
	int xPos = x;
	int yPos = y;
}

void square::setCoords(int y, int x) {
	int xPos = x;
	int yPos = y;
};