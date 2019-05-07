/*
Logan Antonio Passi
CIS2542
11/19/17
TrickorTreat.cpp
*/

#include "ToT.h"
#include "Neighbor.h"
#include "node.h"
#include <fstream>
#include <string>
#include <vector>

void createCandy(unordered_map<string, int>&, fstream&);
void createNeighborhood(node*&, unordered_map<string, int>, fstream&);
void traverseNeighborhood(ToT&, node*);
void insertion_sort(int arr[], int length);

int main() {
	fstream inFile;
	string name, fname;
	stack<candy> copy;
	cout << "Please enter the file directory for candyList.txt: ";
	getline(cin, fname);
	inFile.open(fname, ios::in); // open file
	if (!inFile) {// check if file has been opened
		cout << endl << "Error opening file exiting program..." << endl;
		return EXIT_FAILURE;
	}
	else
		cout << endl << "File opened successfully!" << endl;
	const size_t ALL_CANDY_ARR_SIZE = 30, NEIGHBORHOOD_SIZE = 5;
	ToT ToT;
	unordered_map<string, int> allCandyUOM;
	createCandy(allCandyUOM, inFile);
	node* neighborhood = new node();
	createNeighborhood(neighborhood, allCandyUOM, inFile);
	cout << endl << "Enter in a sp00ky name: ";
	cin >> name;
	ToT.set_name(name);
	cout << "\n\n----------Happy Halloween " << ToT.get_name() << "!----------" << endl;
	traverseNeighborhood(ToT, neighborhood);
	copy = ToT.getStackOfCandy();
	ToT.convToBST();
	int c[NEIGHBORHOOD_SIZE] = {};
	for (unsigned int i = 0; i < NEIGHBORHOOD_SIZE; ++i) {
		c[i] = copy.top().get_calories();
		copy.pop();
	}
	insertion_sort(c, NEIGHBORHOOD_SIZE);
	//delete neighborhood;
	inFile.close();
	return EXIT_SUCCESS;
}

void createCandy(unordered_map<string, int>& uom, fstream& inFile) {
	string name;
	int calories = 0;
	while (!inFile.eof()) {
		inFile >> calories, getline(inFile, name, '\n');
		uom.insert({ name, calories });
	}
}

void createNeighborhood(node*& n, unordered_map<string, int> allCandy, fstream& inFile) {
	node* neighbor5 = new node();
	node* neighbor4 = new node();
	node* neighbor3 = new node();
	node* neighbor2 = new node();
	n->set_link(neighbor2);
	neighbor2->set_link(neighbor3);
	neighbor3->set_link(neighbor4);
	neighbor4->set_link(neighbor5);
	neighbor5->set_link(nullptr);
	for (node* cursor = n; cursor != nullptr; cursor = cursor->link()) {
		neighbor nbr;
		cursor->set_data(nbr);
		cursor->data().buyCandy(allCandy, inFile);
	}
}


void traverseNeighborhood(ToT& T, node* n) {
	int count = 0;
	for(node* cursor = n; cursor != nullptr; cursor = cursor->link()){
		++count;
		cout << "\nHouse number " << count << " is " << cursor->data().getDistance() << " feet away..." << endl;
		cout << "\nTime to start walking!" << endl << endl;
		cout << "---Distance Walked\t Distance Left---\n";
		cout << "|" << setw(17) << right << "\t\t\t\t|\n";
		cout << "v" << setw(17) << right << "\t\t\t\tv\n";
		T.walk(cursor->data().getDistance());
		cursor->data().displayCandy(T);
	}
}

void insertion_sort(int arr[], int length)
{
	int i, j, tmp;
	for (i = 1; i < length; i++) {
		j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
			j--;
		}
	}
	cout << endl << "Insertion Sort" << endl;
	for (int i = 0; i < length; ++i) {
		cout << arr[i] << endl;
	}
}
