/*
Logan Passi
12/15/2017
knight.cpp
*/ 

#include "knight.h"
#include "square.h"

//default constructor
knight::knight() {

	//set boundries for the random number that will be generated
	int lowest = 0, highest = 7, range = highest - lowest;

	//generate random x-position
	x = lowest + (rand() % (range + 1));

	//generate random y-position
	y = lowest + (rand() % (range + 1));

	//initialize the count value to zero
	count = 0;
};


//get the position of the knight (both x and y coordinates)
void knight::getPosition() {
	cout << endl << setw(26) << right << "Knight's Position: ";
	switch (x)
	{

	case 0: cout << "A";
		break;
	
	case 1: cout << "B";
		break;

	case 2: cout << "C";
		break;

	case 3: cout << "D";
		break;

	case 4: cout << "E";
		break;

	case 5: cout << "F";
		break;

	case 6: cout << "G";
		break;

	case 7: cout << "H";
		break;

	}
	cout << y + 1 << endl;
	cout << setw(28) << right << "---------------------" << endl << endl;
};


//move the position of the knight by adding or subtracting
//from the x or y coordinates (yPos and xPos)
void knight::movePosition(int xPos, int yPos) {
	y += yPos;
	x += xPos;

}