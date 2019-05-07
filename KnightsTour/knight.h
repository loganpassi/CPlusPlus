/*
Logan Passi
12/15/2017
knight.h
*/

#include <iostream>
#include <ctime> //include ctime to seed rand function
#include <iomanip>//include iomanip for output manipulation
#include <string>//include cstring to use string data type

using namespace std;

//knight class
class knight {
public:

	//default constructor
	knight();

	//get the position of the knight (both x and y coordinates)
	void getPosition();
	
	//move the position of the knight by adding or subtracting
	//from the x or y coordinates
	void movePosition(int, int);

	//get the x-coordinate
	int getX() { return x; }

	//get the y-coordinate
	int getY() { return y; }

private:

	// x-position of the knight
	int x;

	// y-position of the knight
	int y;
};