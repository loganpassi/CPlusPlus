/*
Logan Antonio Passi
CIS2542
11/14/17
Neighbor.h
*/
#ifndef NEIGHBOR_H
#define NEIGHBOR_H
#include "Candy.h"
#include "ToT.h"
#include <vector>
#include <unordered_map>

using namespace std;

class neighbor {
public:
	const static int CANDY_ARR_SIZE = 10;
	//default constructor
	neighbor();
	
	int getDistance() { return distance; }
	void displayCandy(ToT&);


	void buyCandy(unordered_map<string, int>, fstream&);
private:
	int distance;
	candy* candyArr;
};


#endif