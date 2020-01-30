/*
Logan Passi
Short program to convert decimal number to binary.
findMax.cpp
*/
#include <iostream>
#include <vector>

using namespace std;

void convertToBi(int dec) {
	vector<int> binVec(12);
	int counter = 0;
	for (int i = 0; dec > 0; ++i) { //loop through the vector and populate the vector
		binVec[i] = dec % 2; //populate the vector with either 0's or 1's
		dec /= 2; //then divide the number by 2
	}

	for (int i = 11; i >= 0; --i) { //loop though the vector and output the binary
		if ((i + 1) % 4 == 0) {
			cout << " ";
		}
		cout << binVec[i];
	}
	cout << endl;
}

int main() {
	int decNum = 0;
	int bin = 0;

	cout << "Please enter a postivie integer =< 4095: "; //Prompt and get input from the user
	cin >> decNum;
	while (decNum > 4095) { //ensure the number is smaller than 4095
		cout << "Your value cannot be larger than 4095!" << endl;
		cout << "Please enter a valid number: ";
		cin >> decNum;
	}
	convertToBi(decNum); //call the convertToBi() function
	system("pause");
}

/*
Please enter a postivie integer = < 4095: 500
	0001 1111 0100
	Press any key to continue . . .
*/