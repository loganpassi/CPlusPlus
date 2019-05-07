/*
Logan Passi
CIS2542
STL_SearchTest.cpp
11/13/2017
*/

#include <iostream>
#include <algorithm> //for binary and find search
#include <vector> //for C++ vector
#include <string> //for C++ string class
using namespace std;

int main() {
	//create vector or sorted integers
	vector<int> sortedDecades{ 1960, 1970, 1980, 1990, 2000 };
	//create a vector of unsorted strings
	vector<string> unsortedFruits{ "pineapple", "strawberry", "mango", "apricot", "banana" };

	//prompt ser and search for given decade
	int decade;
	cout << "Which decade has the best music? ";
	cin >> decade;
	//search for decade
	if (binary_search(sortedDecades.begin(), sortedDecades.end(), decade))
		cout << "That is on my playlist." << endl;
	else
		cout << "That is not on my playlist." << endl;

	//prompt for fruit from the user
	string fruit;
	cout << "What is your favorite fruit? ";
	cin >> fruit;
	//search for fruit using 'find' function
	if (find(unsortedFruits.begin(), unsortedFruits.end(), fruit) != unsortedFruits.end())
		cout << "Yum yum, that is mine too." << endl;
	else
		cout << "Gross, thats disgusting." << endl;

	return EXIT_SUCCESS;
}