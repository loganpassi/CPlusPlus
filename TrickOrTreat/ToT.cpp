/*
Logan Antonio Passi
CIS542
11/19/17
ToT.cpp
*/

#include "ToT.h"
#include "binarySearchTree.h"

//default constructor
ToT::ToT() {
	distanceWalked = 0;
	name = "";
	stackOfCandy.empty();
}

//setter for the name
void ToT::set_name(string s) {
	name = s;
}


void ToT::walk(int i) {
	static int distanceWalked = 0;
	_sleep(0700);
	cout << left << setw(41) << "\r" << i;
	cout << "\t\t\r" << distanceWalked;
	if (i != 0) {
		++distanceWalked;
		walk(i - 1);
	}
	distanceWalked = 0;
}
void ToT::addCandy(candy c) {
	stackOfCandy.push(c);
}
void ToT::convToBST() {
	stack<candy> copy = stackOfCandy;
	cout << endl << "Binary Tree Search and Inorder Proccessing" << endl;
	binarySearchNode* root = NULL;
	int cal = copy.top().get_calories(), size = copy.size();
	root = insert(root, cal);
	copy.pop();
	for (int i = 0; i < size - 1; ++i) {
		cal = copy.top().get_calories();
		insert(root, cal);
		copy.pop();
	}
	inorder(root);
}