/*
Logan Passi
12/15/2017
chessboard.h
*/

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "knight.h"
#include "square.h"
#include <cstring>

//chessboard class
class chessboard {
public:
	static const int SIZE = 8;

	//default constructor
	chessboard();

	//function to display the chessboard
	void displayBoard();

	//function to move knight
	void moveKnight();

	//funtion to decide where to move
	int decidePosition();

	//array to hold 1-8
	int numArr[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	//array to hold a-h
	char alphaArr[SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };


	//function to determine the number of moves each square has
	int calcMoves(square s);

private:

	//knight object
	knight knight;

	//2d array to make the chessboard
	square board[SIZE][SIZE];
};
#endif
