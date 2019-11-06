/*
Logan Passi
12/15/2017
knight.h
*/

#include <iostream>
#include <ctime> //include ctime to seed rand function
#include <iomanip>//include iomanip for output manipulation
#include <string>//include cstring to use string data type
#include <windows.h>//include windows.h for Sleep() function
using namespace std;

//knight class
class knight {
public:

	//default constructor
	knight();

	//SETTERS

	//set the count
	void setCount(int c) { count = c; }
	
	//move the position of the knight by adding or subtracting
	//from the x or y coordinates
	void movePosition(int, int);

	//GETTERS

	//get the x-coordinate
	int getX() { return x; }

	//get the y-coordinate
	int getY() { return y; }

	//get the count
	int getCount() { return count;}

	//get the position of the knight (both x and y coordinates)
	void getPosition();


private:

	// x-position of the knight
	int x;

	// y-position of the knight
	int y;

	//count of how many times the knight has moved
	int count;
};