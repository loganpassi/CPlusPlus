/*
Logan Passi
12/15/2017
KnightsTour.cpp
Problem : A knight is placed on the first block of an empty board and, moving according 
to the rules of chess, must visit each square exactly once.
*/

#include "chessboard.h"

int main() {
	srand(static_cast<unsigned int>(time(NULL))); //seed the rand function to have true random number generator
	chessboard board; //create board object
	board.moveKnight(); //call recursive function to move the knight
	return EXIT_SUCCESS;
}