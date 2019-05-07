/*
Logan Passi
bagBSTreeTester.cpp
CIS2452
11/08/2017
*/

#include "bagBSTree.h"
#include <iostream>
using namespace std;

int main() {
	//identify integer node values
	int items[] = { 35, 18, 25, 48, 72, 60 };
	int arrSize = sizeof(items) / sizeof(int);
	//create BST
	bagBSTree<int> bagOfInts;
	for (size_t i = 0; i < arrSize; ++i)
		bagOfInts.insert(items[i]);
	//output some BST characteristic
	cout << "Size fo bag BST if " << bagOfInts.size() << endl;
	cout << "BST display" << endl;
	bagOfInts.displayBSTree(3);
	cout << "InOrder scan of BST" << endl;
	bagOfInts.inOrderDisplay();
	cout << endl;
	//searching BST for value
	int iVal;
	cout << "\nSearching BST for value" << endl;
	cout << "Input a value to search: ";
	cin >> iVal;
	cout << "There are " << bagOfInts.count(iVal) << " oocurrences of " << iVal << " in the BST bag." << endl;
	return EXIT_SUCCESS;
}