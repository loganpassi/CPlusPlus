/*
Logan Passi
04/26/19
Square.cpp
*/

#include "square.h"

//default constructor
square::square() {
	numMoves = 0;
	xPos = 0;
	yPos = 0;
	order = 0;
	touch = false;
};

//parameterized constructor
square::square(int x, int y) {
	numMoves = 0;
	xPos = x;
	yPos = y;
	order = 0;
	touch = false;
}

//method to set the coordinates of the square
void square::setCoords(int x, int y) {
	xPos = x;
	yPos = y;
};