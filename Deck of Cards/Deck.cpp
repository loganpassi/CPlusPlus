//Logan Passi
//CIS2542
//09/18/2017
//Deck.cpp
#include "Deck.h"


//default deck class constructor
deck::deck() {
	//create the sizes for deckVect and playerDeckVect
	deckVect.resize(CAPACITY);
	//variables for rank index and suit index
	int rankIndex = 1, suitIndex = 0;
	//loop to go from 0 - 51 to create 52 cards
	for (size_type i = 0; i < CAPACITY; i++) {
		if (rankIndex == 14) {
			++suitIndex;
			rankIndex = 2;
		}
		else
			++rankIndex;
		deckVect[i] = card(suitIndex, rankIndex);
	}
}

//function to display the player's deck
void displayDeck(vector<card> v) {
	for (deck::size_type i = 0; i < v.size(); i++) {
		cout << "----------------------------" << endl;
		cout << setw(2) << right << "[" << i + 1 << "]" << v[i];
	}
}


//display the info of each player and their deck
const void deck::displayInfo(player p) {
	cout << endl << setw(10) << "Player: " << "[" <<  p.getName() << "]" << endl;
	displayDeck(p.getPlayerDeckVect());
	cout << endl << setw(10) << "Total: " << "[" << p.sumOfDeck() << "]" << endl;
	cout << endl << "\n*******************************************" << endl << endl;
}

//shuffle the entire deck
void deck::shffl() {
	srand(static_cast<unsigned int>(time(NULL)));
	int rNum;
	card temp;
	for (size_type i = 0; i < CAPACITY; i++) {
		rNum = rand() % CAPACITY;
		temp = deckVect[i];
		deckVect[i] = deckVect[rNum];
		deckVect[rNum] = temp;
	}
}

//create a deck for a player
void deck::deal(player& P1, player& P2, player& P3, player& P4) { //passing all players by reference
	unsigned int i = 0, j = 0, k = 1;
	while (i < (player::PLYRDECKSIZE * k)) {
		while (j < player::PLYRDECKSIZE) {
			P1.setPlayerCard(deckVect[i], j);
			deckVect[i] = empty;
			++i;
			P2.setPlayerCard(deckVect[i], j);
			deckVect[i] = empty;
			++i;
			P3.setPlayerCard(deckVect[i], j);
			deckVect[i] = empty;
			++i;
			P4.setPlayerCard(deckVect[i], j);
			deckVect[i] = empty;
			++i;
			++j;
		}
		++k;
	}
}


//function to discard a card
void deck::discard(player& p, const int i, const int j) {
	card temp = p.getPlayerDeckVect()[j];
	deckVect[i] = p.getPlayerDeckVect()[j];
	p.setPlayerCard(empty, j);
	cout << endl << "[" << p.getName() << "]" << " discarded:" << endl << temp << endl;
	cout << "TOTAL: " << "[" << p.sumOfDeck() << "]" << endl;
	cout << "\n=============ENTER TO CONTINUE=============\n";
	if (i == 0)
		cin.ignore();
	getchar();
}