/*
Logan Passi
12/15/2017
chessboard.cpp
*/

#include "chessboard.h"//including the chessboard header
#include <cmath>

//default constructor
chessboard::chessboard() {
	square s;
	int xPos = 0, yPos = 0;
	for (xPos; xPos < SIZE; ++xPos) {
		for (yPos; yPos < SIZE; ++yPos) {
			board[xPos][yPos] = s; //set each element of the 2d array to hold a square object
			board[xPos][yPos].setCoords(xPos, yPos); //set the coordinates of each square
			board[xPos][yPos].setNumMoves(calcMoves(board[xPos][yPos])); //calculate the number of moves for each square
		}
		yPos = 0; //reset the y position in order to continue to the next row
	}
}


//method to calculate the number of moves a square has at a given time
int chessboard::calcMoves(square s) {
	int count = 0;

	//check up 2, right 1
	if (s.getYPos() - 2 >= 0 && s.getXPos() + 1 < SIZE) { //check to see if this spot is outside the chessboard
		if (board[s.getXPos() + 1][s.getYPos() - 2].getTouch() != true) { //check to see if this spot had been touched by the knight
			++count;
		}
	} 


	//check up 1, right 2
	if (s.getYPos() - 1 >= 0 && s.getXPos() + 2 < SIZE) {
		if (board[s.getXPos() + 2][s.getYPos() - 1].getTouch() != true) {
			++count;
		}
	}


	//check down 1, right 2
	if (s.getYPos() + 1 < SIZE && s.getXPos() + 2 < SIZE) {
		if (board[s.getXPos() + 2][s.getYPos() + 1].getTouch() != true) {
			++count;
		}
	}


	//check down 2, right 1
	if (s.getYPos() + 2 < SIZE && s.getXPos() + 1 < SIZE) {
		if (board[s.getXPos() + 1][s.getYPos() + 2].getTouch() != true) {
			++count;
		}
	}


	//check down 2, left 1
	if (s.getYPos() + 2 < SIZE && s.getXPos() - 1 >= 0) {
		if (board[s.getXPos() - 1][s.getYPos() + 2].getTouch() != true) {
			++count;
		}
	}


	//check down 1, left 2
	if (s.getYPos() + 1 < SIZE && s.getXPos() - 2 >= 0) {
		if (board[s.getXPos() - 2][s.getYPos() + 1].getTouch() != true) { 
			++count;
		}
	}


	//check up 1, left 2
	if (s.getYPos() - 1 >= 0 && s.getXPos() - 2 >= 0) {
		if (board[s.getXPos() - 2][s.getYPos() - 1].getTouch() != true) {
			++count;
		}
	}


	//check up 2, left 1
	if (s.getYPos() - 2 >= 0 && s.getXPos() - 1 >= 0) {
		if (board[s.getXPos() - 1][s.getYPos() - 2].getTouch() != true) {
			++count;
		}
	}

	return count;
}

//function to display the chessboard
void chessboard::displayBoard() {
	string fiveSp = "     ";
	static int count = 0;
	Sleep(0700);

	knight.getPosition();
	board[knight.getX()][knight.getY()].setTouch(true); //set the square's touched value to true since the knight is there
	board[knight.getX()][knight.getY()].setOrder(count); //set the order of which the knight traveled to this square
	knight.setCount(count);

	int xPos = 0, yPos = 0;
	cout << fiveSp;

	for (int i = 0; i < SIZE; ++i) { //display A-H for the chessboard
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

			switch (board[xPos][yPos].getTouch()) {

			case false: cout << setw(3) << "X"; //display an X if the knight has not been to that position
				break;

			default: 
				cout << setw(3) << board[xPos][yPos].getOrder(); //display the value at that position
			}
		}
		yPos = 0;
		cout << endl << endl;
	}
	++count;
	cout << setw(23) << right << "Number of moves: " << count - 1 << endl << endl;
};


//function to move knight
void chessboard::moveKnight() {

	//display the board
	displayBoard();

	if (int i = 0 < pow(SIZE, 2)) {
		switch (decidePosition()) { //call the decidePosition method to determine where to travel to

			//right 1, up 2
		case 1: knight.movePosition(1, -2); //move the knight
			board[knight.getX()][knight.getY()].setTouch(true); //set the square's touch value that the knight moved to to true
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
		case -1:
			if (knight.getCount() == 63) { //if the knight has traveled to every square he has completed his tour
				cout << setw(24) << "The knight has completed his tour!" << endl;
				cin.get();
				exit(0);
			}
			else { //if not, he failed his tour
				cout << setw(24) << "No new spot found!" << endl << endl;
				cin.get();
				exit(-1);
			}
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
	square tempSquare;


	//check up 2, right 1
	if (knight.getY() - 2 >= 0 && knight.getX() + 1 < SIZE) { //check to see if the square outside the chessboard
		tempSquare = board[knight.getX() + 1][knight.getY() - 2]; //if it is within the board, set our tempSquare equal to this spot
		tempSquare.setNumMoves(calcMoves(tempSquare)); //recalculate the number of moves for this square as it the number of moves could have diminished
		if (tempSquare.getNumMoves() < move && tempSquare.getTouch() != true) { //if this square's number of moves is less than our current number of moves
			move = tempSquare.getNumMoves();									//and has not been touched, then this will be our current choice to move to
			choice = 1;															//unless we find a square with a smaller number of moves
		}
	}
	

	//check up 1, right 2
	if (knight.getY() - 1 >= 0 && knight.getX() + 2 < SIZE) {
		tempSquare = board[knight.getX() + 2][knight.getY() - 1];
		tempSquare.setNumMoves(calcMoves(tempSquare));
		if (tempSquare.getNumMoves() < move && tempSquare.getTouch() != true) {
			move = tempSquare.getNumMoves();
			choice = 2;
		}
	}	


	//check down 1, right 2
	if (knight.getY() + 1 < SIZE && knight.getX() + 2 < SIZE) {
		tempSquare = board[knight.getX() + 2][knight.getY() + 1];
		tempSquare.setNumMoves(calcMoves(tempSquare));
		if (tempSquare.getNumMoves() < move && tempSquare.getTouch() != true) {
			move = tempSquare.getNumMoves();
			choice = 3;
		}
	}
		
			
	//check down 2, right 1
	if (knight.getY() + 2 < SIZE && knight.getX() + 1 < SIZE) {
		tempSquare = board[knight.getX() + 1][knight.getY() + 2];
		tempSquare.setNumMoves(calcMoves(tempSquare));
		if (tempSquare.getNumMoves() < move && tempSquare.getTouch() != true) {
			move = tempSquare.getNumMoves();
			choice = 4;
		}
	}
		

	//check down 2, left 1
	if (knight.getY() + 2 < SIZE && knight.getX() - 1 >= 0) {
		tempSquare = board[knight.getX() - 1][knight.getY() + 2];
		tempSquare.setNumMoves(calcMoves(tempSquare));
		if (tempSquare.getNumMoves() < move && tempSquare.getTouch() != true) {
			move = tempSquare.getNumMoves();
			choice = 5;
		}
	}
			

	//check down 1, left 2
	if (knight.getY() + 1 < SIZE && knight.getX() - 2 >= 0) {
		tempSquare = board[knight.getX() - 2][knight.getY() + 1];
		tempSquare.setNumMoves(calcMoves(tempSquare));
		if (tempSquare.getNumMoves() < move && tempSquare.getTouch() != true) {
			move = tempSquare.getNumMoves();
			choice = 6;
		}
	}
			

	//check up 1, left 2
	if (knight.getY() - 1 >= 0 && knight.getX() - 2 >= 0) {
		tempSquare = board[knight.getX() - 2][knight.getY() - 1];
		tempSquare.setNumMoves(calcMoves(tempSquare));
		if (tempSquare.getNumMoves() < move && tempSquare.getTouch() != true) {
			move = tempSquare.getNumMoves();
			choice = 7;
		}
	}
		

	//check up 2, left 1
	if (knight.getY() - 2 >= 0 && knight.getX() - 1 >= 0) {
		tempSquare = board[knight.getX() - 1][knight.getY() - 2];
		tempSquare.setNumMoves(calcMoves(tempSquare));
		if (tempSquare.getNumMoves() < move && tempSquare.getTouch() != true) {
			move = tempSquare.getNumMoves();
			choice = 8;
		}
	}
			
	return choice;
	
}