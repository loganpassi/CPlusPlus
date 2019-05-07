/*
Logan Passi
12/15/2017
chessboard.cpp
*/

#include "chessboard.h"//including the chessboard header
#include <cmath>

//default constructor
chessboard::chessboard() {
	square square;
	int xPos = 0, yPos = 0;
	for (xPos; xPos < SIZE; ++xPos) { //loop through the main array
		for (yPos; yPos < SIZE; ++yPos) { //loop through the sub-arrays
			board[yPos][xPos] = square;
			square.setCoords(yPos, xPos);
			switch (yPos) {
			
			case 0: board[yPos][xPos].setNumMoves(edgeArr[xPos]);
				break;

			case 7: board[yPos][xPos].setNumMoves(edgeArr[xPos]);
				break;

			case 1: board[yPos][xPos].setNumMoves(scndEdgeArr[xPos]);
				break;

			case 6: board[yPos][xPos].setNumMoves(scndEdgeArr[xPos]);
				break;
			
			default: board[yPos][xPos].setNumMoves(midArr[xPos]);

			}
		}
		yPos = 0;
	}
};


//function to display the chessboard
void chessboard::displayBoard() {
	string fiveSp = "     ";
	static int count = 0;
	_sleep(0700);
	knight.getPosition();
	board[knight.getX()][knight.getY()].setTouch(true);
	board[knight.getX()][knight.getY()].setOrder(count);
	int xPos = 0, yPos = 0;
	cout << fiveSp;
	for (int i = 0; i < SIZE; ++i) {
		cout << setw(3) << alphaArr[i];
	}
	cout << endl;
	cout << fiveSp;
	for (int i = 0; i < SIZE; ++i) {
		cout << setw(3) << "--";
	}
	cout << endl;
	for (xPos; xPos < SIZE; ++xPos) {
		cout << setw(3) << numArr[xPos] << " |";
		for (yPos; yPos < SIZE; ++yPos) {

			switch (board[yPos][xPos].getTouch()) {

			case false: cout << setw(3) << "X"; //display an X if the knight has not been to that position
				break;

			default: 
				cout << setw(3) << board[yPos][xPos].getOrder(); //display the value at that position
			}
		}
		yPos = 0;
		cout << endl << endl;
	}
	++count;
	//cout << endl << " Press [Enter] to continue..." << endl;
	//cin.get();
	cout << setw(23) << right << "Number of moves: " << count - 1 << endl << endl;
	//clear the screen
	//system("CLS");
};


//function to move knight

void chessboard::moveKnight() {
	//static int count = 0; //variable to keep count of how many times the knight has moved

	//display the board
	displayBoard();


	//make the spot where the knight is equal to the count of time that the knight has moved
	//board[knight.getY()][knight.getX()] = count;

	if (int i = 0 < pow(SIZE, 2)) {
		switch (decidePosition()) {
		
		//right 1, up 2
		case 1 : knight.movePosition(1, -2);
			board[knight.getX()][knight.getY()].setTouch(true);
			break;
		
		//right 2, up 1
		case 2: knight.movePosition(2, -1);
			board[knight.getX()][knight.getY()].setTouch(true);
			break;

		//right 2, down 1
		case 3: knight.movePosition(2, 1);
			board[knight.getX()][knight.getY()].setTouch(true);
			break;

		//right 1, down 2
		case 4: knight.movePosition(1, 2);
			board[knight.getX()][knight.getY()].setTouch(true);
			break;

		//left 1, down 2
		case 5: knight.movePosition(-1, 2);
			board[knight.getX()][knight.getY()].setTouch(true);
			break;

		//left 2, down 1
		case 6: knight.movePosition(-2, 1);
			board[knight.getX()][knight.getY()].setTouch(true);
			break;

		//left 2, up 1
		case 7: knight.movePosition(-2, -1);
			board[knight.getX()][knight.getY()].setTouch(true);
			break;

		//left 1, up 2
		case 8: knight.movePosition(-1, -2);
			board[knight.getX()][knight.getY()].setTouch(true);
			break;

		//no new spot found
		case -1: cout << setw(24) << "No new spot found!" << endl << endl;
				exit(-1);
		}


		//increment count
		++i;

		//recursive call to move the knight again
		moveKnight();


	}
};


//funtion to decide where to move
int chessboard::decidePosition() {
	//see what position has not been visited yet and also make sure that the knight does not go outside the boundries of the chessboard

	int move = 9;
	int choice = -1;
	
	//check up 2, right 1
	if (board[knight.getX() + 1][knight.getY() - 2].getTouch() == false && knight.getY() - 2 >= 0 && knight.getX() + 1 < SIZE && board[knight.getX() + 1][knight.getY() - 2].getNumMoves() < move) {
		move = board[knight.getX() + 1][knight.getY() - 2].getNumMoves();
		choice = 1;
	}
		


	//check up 1, right 2
	if (board[knight.getX() + 2][knight.getY() - 1].getTouch() == false && knight.getY() - 1 >= 0 && knight.getX() + 2 < SIZE && board[knight.getX() + 2][knight.getY() - 1].getNumMoves() < move) {
		move = board[knight.getX() + 2][knight.getY() - 1].getNumMoves();
		choice = 2;
	}
		


	//check down 1, right 2
	if (board[knight.getX() + 2][knight.getY() + 1].getTouch() == false && knight.getY() + 1 < SIZE && knight.getX() + 2 < SIZE && board[knight.getX() + 2][knight.getY() + 1].getNumMoves() < move) {
		move = board[knight.getX() + 2][knight.getY() + 1].getNumMoves();
		choice = 3;
	}
		
			

	//check down 2, right 1
	if (board[knight.getX() + 1][knight.getY() + 2].getTouch() == false && knight.getY() + 2 < SIZE && knight.getX() + 1 < SIZE && board[knight.getX() + 1][knight.getY() + 2].getNumMoves() < move) {
		move = board[knight.getX() + 1][knight.getY() + 2].getNumMoves();
		choice = 4;
	}
		

	//check down 2, left 1
	if (board[knight.getX() - 1][knight.getY() + 2].getTouch() == false && knight.getY() + 2 < SIZE && knight.getX() - 1 >= 0 && board[knight.getX() - 1][knight.getY() + 2].getNumMoves() < move) {
		move = board[knight.getX() - 1][knight.getY() + 2].getNumMoves();
		choice = 5;
	}
		
			

	//check down 1, left 2
	if (board[knight.getX() - 2][knight.getY() + 1].getTouch() == false && knight.getY() + 1 < SIZE && knight.getX() - 2 >= 0 && board[knight.getX() - 2][knight.getY() + 1].getNumMoves() < move) {
		move = board[knight.getX() - 2][knight.getY() + 1].getNumMoves();
		choice = 6;
	}
		
			

	//check up 1, left 2
	if (board[knight.getX() - 2][knight.getY() - 1].getTouch() == false && knight.getY() - 1 >= 0 && knight.getX() - 2 >= 0 && board[knight.getX() - 2][knight.getY() - 1].getNumMoves() < move) {
		move = board[knight.getX() - 2][knight.getY() - 1].getNumMoves();
		choice = 7;
	}
		

	//check up 2, left 1
	if (board[knight.getX() - 1][knight.getY() - 2].getTouch() == false && knight.getY() - 2 >= 0 && knight.getX() - 1 >= 0 && board[knight.getX() - 1][knight.getY() - 2].getNumMoves() < move) {
		move = board[knight.getX() - 1][knight.getY() - 2].getNumMoves();
		choice = 8;
}
			
	return choice;
	
}