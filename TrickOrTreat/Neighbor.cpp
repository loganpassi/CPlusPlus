/*
Logan Antonio Passi
CIS2542
11/19/17
Neighbor.cpp
*/

#include "Neighbor.h"
#include <ctime>
#include <fstream>

neighbor::neighbor() {
	candyArr = new candy[CANDY_ARR_SIZE];//dont forget to release memory
	int lowest = 15, highest = 35, range = highest - lowest;
	srand(static_cast<unsigned int>(time(NULL)));
	distance = lowest + (rand() % (range + 1));
}

 void neighbor::displayCandy(ToT& T) {
	cout << "\n\n===========================================\n";
	for (int i = 0; i < CANDY_ARR_SIZE; ++i) {
		cout << endl << left << "[" << i + 1 << "]" << endl;
		cout << candyArr[i];
	}
	int input = NULL;
	cout << endl << "----------> Select a candy: ";
	cin >> input;
	candy temp;
	for (int i = 0; i <= input - 1; ++i) {
		temp.set_calories(candyArr[i].get_calories());
		temp.set_name(candyArr[i].get_name());
	}
	T.addCandy(temp);
	cout << endl << "You grabbed..." << endl << endl;
	cout << T.getStackOfCandy().top();

}


void neighbor::buyCandy(unordered_map<string, int> uom, fstream& inFile) {
	string name;
	srand(static_cast<unsigned int>(time(NULL)));
	unsigned int rNum = 0, range = 29, calories = 0;
	unordered_map<string, int>::const_iterator item;
	for (size_t i = 0; i < CANDY_ARR_SIZE; ++i)
	{
		inFile.clear();
		inFile.seekg(0, ios::beg);
		rNum = rand() % range;
		for (size_t i = 0; i <= rNum; i++) {
			inFile >> calories, getline(inFile, name, '\n');
		}
		item = uom.find(name);
		candyArr[i].set_name(item->first);
		candyArr[i].set_calories(item->second);
	}
}