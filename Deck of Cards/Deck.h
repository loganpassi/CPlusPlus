//Logan Passi
//CIS2542
//09/18/2017
//Deck.h
#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include "Player.h"
#include "node.h"

class deck {

public:
	//aliase and member constant
	using size_type = std::size_t;
	static const size_type CAPACITY = 52;

	//friend function to display a deck
	friend void displayDeck(vector<card>);

	//default constructor
	deck();

	//make the players' decks
	void deal(player&, player&, player&, player&);

	//getters
	vector<card> getDeckVect() { return deckVect; }


	//shuffle the deck of cards
	void shffl();

	const void displayInfo(player);

	//function to discard a card
	void discard(player&, const int,const int);
	
	//empty card
	card empty = { -1, 0 };

private:
	
	//private vector to hold 52 card objects
	vector<card> deckVect;
};

#endif