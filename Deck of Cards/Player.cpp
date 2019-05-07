//Logan Passi
//CIS2542
//09/18/2017
//Player.cpp

#include "Player.h"


//default constructor
player::player() {
	name = "";
	playerDeckVect.resize(PLYRDECKSIZE);
	id = rand();
}


//setter
void player::setName(string s) {
	name = s;
}

void player::setPlayerCard(card c, int i) {
	playerDeckVect[i] = c;
}


//sum the players deck
int player::sumOfDeck() {
	int ttl = 0;
	for (int i = 0; i < PLYRDECKSIZE; i++) {
		ttl = ttl + playerDeckVect[i];
	}

	return ttl;
}


//overloading the == operator
bool player::operator == (player& rhs) {
	if (name != rhs.name || id != rhs.id)
		return false;
	return true;
}

