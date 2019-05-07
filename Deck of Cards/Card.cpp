//Logan Passi
//CIS2542
//09/17/2017
//Card.cpp

#include "Card.h"


//default card class constructor
card::card(){
	
	suit = static_cast<int>(Suit::empty);

	rank = static_cast<int>(Rank::empty);

}

//parameterized card class constructor
card::card(int s, int r) {

	suit = s;

	rank = r;

}

//copy card class constructor
card::card(const card& c) {

	suit = c.suit;

	rank = c.rank;
}

//setters
void card::setSuit(int s) {
	suit = s;
}

void card::setRank(int r) {
	rank = r;
}


//switch statement to get suit name from card object
void card::getSuitName(card c) {

	switch (c.getSuit()) {

	case static_cast<int>(Suit::empty) : cout << "Empty\n";
		break;

	case static_cast<int>(Suit::clubs) : cout << "Clubs\n";
		break;

	case static_cast<int>(Suit::diamonds) : cout << "Diamonds\n";
		break;

	case static_cast<int>(Suit::hearts) : cout << "Hearts\n";
		break;

	case static_cast<int>(Suit::spades) : cout << "Spades\n";
		break;
		}
}


//switch statement to get rank name of card object
void card::getRankName(card c) {

	switch (c.getRank()) {

	case static_cast<int>(Rank::empty) : cout << "Empty\n";
		break;

	case static_cast<int>(Rank::two) : cout << "Two\n";
		break;

	case static_cast<int>(Rank::three) : cout << "Three\n";
		break;

	case static_cast<int>(Rank::four) : cout << "Four\n";
		break;

	case static_cast<int>(Rank::five) : cout << "Five\n";
		break;

	case static_cast<int>(Rank::six) : cout << "Six\n";
		break;

	case static_cast<int>(Rank::seven) : cout << "Seven\n";
		break;

	case static_cast<int>(Rank::eight) : cout << "Eight\n";
		break;

	case static_cast<int>(Rank::nine) : cout << "Nine\n";
		break;

	case static_cast<int>(Rank::ten) : cout << "Ten\n";
		break;

	case static_cast<int>(Rank::jack) : cout << "Jack\n";
		break;

	case static_cast<int>(Rank::queen) : cout << "Queen\n";
		break;

	case static_cast<int>(Rank::king) : cout << "King\n";
		break;

	case static_cast<int>(Rank::ace) : cout << "Ace\n";
		break;

	}
}


//overloading the + operator for card + card
int card::operator + (card& c) {
	int retVal = 0;
	retVal += rank;
	retVal += c.getRank();
	return retVal;
}

//overloading the + operator for card + int
int card::operator + (const int& i) {
	int retVal = 0;
	retVal += rank;
	retVal += i;
	return retVal;
}

//overloading the + operator for int + card
int operator + (const int& lhs, card& rhs) {
	int retVal = 0;
	retVal += lhs;
	retVal += rhs.getRank();
	return retVal;
}

//overloading the << operator
ostream& operator << (ostream& s, card& c) {

	s << endl;

	s << right << setw(10) << "| " << setw(10) << left << "Rank: ";

	c.getRankName(c);

	s << endl << right << setw(10) << "| " << setw(10) << left << "Suit: ";

	c.getSuitName(c);

	s << endl << right << setw(10) << "| " << setw(10) << left << "Value: ";

	s << c.getRank();

	s << endl;

	return s;
}