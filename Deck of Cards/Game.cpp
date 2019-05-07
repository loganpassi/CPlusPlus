//Logan Passi
//CIS2542
//10/02/2017
//Game.cpp

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "node.h"

int main() {
	unsigned int i = 0, k = 0, j = 0, rNum = 0;
	player P1, P2, P3, P4;
	deck deck;
	string name;
	cout << "******Welcome To Cards!******" << endl;
	cout << "Please enter in a name for [Player 1]: ";
	cin >> name;
	P1.setName(name);
	cout << "Please enter in a name for [Player 2]: ";
	cin >> name;
	P2.setName(name);
	cout << "Please enter in a name for [Player 3]: ";
	cin >> name;
	P3.setName(name);
	cout << "Please enter in a name for [Player 4]: ";
	cin >> name;
	P4.setName(name);
	cout << "[P1]-->" << P1.getName() << endl;
	cout << "[P2]-->" << P2.getName() << endl;
	cout << "[P3]-->" << P3.getName() << endl;
	cout << "[P4]-->" << P4.getName() << endl;
	cout << "I will now deal 13 cards to each of you." << endl;
	deck.shffl();
	deck.deal(P1, P2, P3, P4);
	node *p4Node = new node(P4);
	node *p3Node = new node(P3, p4Node);
	node *p2Node = new node(P2, p3Node);
	node *p1Node = new node(P1, p2Node);
	p4Node->set_link(p1Node);
	deck.displayInfo(P1);
	deck.displayInfo(P2);
	deck.displayInfo(P3);
	deck.displayInfo(P4);
	vector<node> nodeVect = { *p1Node, *p2Node, *p3Node, *p4Node };
	srand(static_cast<unsigned int>(time(NULL)));
	rNum = rand() % 4;
	node currNode = nodeVect[rNum];
	player currPlayer;
	for (j; j < player::PLYRDECKSIZE; ++j) {
		for (k; k < nodeVect.size(); ++i, ++k, currNode = (*currNode.link())) {
			currPlayer = currNode.data();
			if (currPlayer == P1)
				deck.discard(P1, i, j);
			else if (currPlayer == P2)
				deck.discard(P2, i, j);
			else if (currPlayer == P3)
				deck.discard(P3, i, j);
			else if (currPlayer == P4)
				deck.discard(P4, i, j);
		}
		k = 0;
		srand(static_cast<unsigned int>(time(NULL)));
		rNum = rand() % 4;
		currNode = nodeVect[rNum];
	}
	delete p4Node;
	delete p3Node;
	delete p2Node;
	delete p1Node;
	return EXIT_SUCCESS;
}