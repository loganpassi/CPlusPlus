/*
Logan Antonio Passi
CIS542
11/14/17
ToT.h
*/
#ifndef TOT_H
#define TOT_H
#include "Candy.h"
#include <stack>
using namespace std;

class ToT {
public:
	//default constructor
	ToT();

	//public getters
	string get_name() { return name; }
	stack<candy> getStackOfCandy() { return stackOfCandy; }

	//public setter
	void set_name(string s);

	//function to convert the stack to a binary search tree
	void convToBST();

	void addCandy(candy c);

	//recursion function to walk
	void walk(int);

private:
	int distanceWalked;
	string name;
	stack<candy> stackOfCandy;
};

#endif