//Logan Passi
//CIS2542
//09/17/2017
//Card.h
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cassert>
#ifndef CARD_H
#define CARD_H
using namespace std;

class card {

public:

	//enumoration for card suit
	enum class Suit {empty = -1, clubs = 0, diamonds, hearts, spades};

	//enumoration for card rank and value
	enum class Rank {empty = 0, two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};
	
	//default constructor
	card();

	//parameterized constructor
	card(int, int);

	//copy constructor
	card(const card&);
	

	//get name of suit or rank with switch statement
	void getSuitName(card);

	void getRankName(card);


	//setters
	void setSuit(int);
	void setRank(int);
	
	//getters
	int getSuit() { return suit; }
	int getRank() { return rank; }

	//overloading + operator
	int operator + (card&);
	int operator + (const int&);


private:

	//private variables for card object
	int suit;

	int rank;

};

//overload the + operator
int operator + (const int& lhs,card& rhs);

//overload the << operator
ostream& operator << (ostream& s, card& c);

#endif