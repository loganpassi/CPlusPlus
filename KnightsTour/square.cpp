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
square::square(int x, int y) {
	int numMoves = 0;
	int xPos = x;
	int yPos = y;
}

//method to set the coordinates of the square
void square::setCoords(int x, int y) {
	xPos = x;
	yPos = y;
};