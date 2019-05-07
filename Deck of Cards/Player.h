//Logan Passi
//CIS2542
//09/18/2017
//Player.h

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"


class player {

public:

	//aliase and member constant
	using size_type = std::size_t;
	static const size_type PLYRDECKSIZE = 13;

	//default constructor
	player();

	//getters
	string getName() { return name; }

	vector<card> getPlayerDeckVect() { return playerDeckVect; }

	//setter
	void setName(string);

	void setPlayerCard(card, int);

	int sumOfDeck();

	//overloading the == operator
	bool operator == (player&);

private:

	//player deck to hold 14 card objects
	vector<card> playerDeckVect;

	//private name variable for player class
	string name;

	int id;
	
};

#endif