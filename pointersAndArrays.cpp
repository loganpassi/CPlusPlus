/*
Logan Passi
02/02/20
pointersAndArrays.cpp
Short program utilizing pointers and arrays
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int myArr[5] = {5, 10, 15, 20, 25}; //create an array
	int * arrPtr = nullptr; //creating a pointer and initialize it to the null pointer

	cout << "Iterating through the array" << endl;
	cout << "==============================" << endl;

	for (int i = 0; i < 5; ++i) { //iterate normally through the array and output the elements
		cout << "Element " << i + 1 << ": " << setw(3) << left << myArr[i] << endl;
	}

	arrPtr = myArr; //set the pointer to the memory address of the beginning of the array

	cout << "\nIterating though array with a pointer" << endl;
	cout << "==============================" << endl;

	for (int i = 0; i < 5; ++i) { //start with the initial posision of the pointer and add i to move down in memory
		cout << "Element " << i + 1 << ": " << setw(3) << *(arrPtr + i) << " Address: " << arrPtr + i << endl; //add i to the pointer and then dereference that address
	}
	system("pause");
}

/*
Iterating through the array
==============================
Element 1: 5
Element 2: 10
Element 3: 15
Element 4: 20
Element 5: 25

Iterating though array with a pointer
==============================
Element 1: 5   Address: 00DBFCD4
Element 2: 10  Address: 00DBFCD8
Element 3: 15  Address: 00DBFCDC
Element 4: 20  Address: 00DBFCE0
Element 5: 25  Address: 00DBFCE4
Press any key to continue . . .
*/