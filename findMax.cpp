/*
Logan Passi
Short Program to determin the maximum value of given values.
findMax.cpp
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int max;
	int length = 0;
	cout << "Please enter in the amount of values you want to enter: ";
	cin >> length;

	while (length < 1) {
		cout << "The size must be larger than 0!";
		cout << "Please enter in the amount of values you want to enter: ";
		cin >> length;
	}

	vector<int> numVec;
	numVec.resize(length);

	for (int i = 0; i < length; ++i) {
		cout << "Please enter value " << i + 1<< ": ";
		cin >> numVec[i];
	}
	max = numVec[0];
	if (length != 1) {
		for (int i = 0; i < length; ++i) {
			if (max < numVec[i]) {
				max = numVec[i];
			}
		}
	}

	cout << "The largest value is: " << max << endl;
	system("pause");

}

/*
Please enter in the amount of values you want to enter : 5
Please enter value 1 : 3
Please enter value 2 : 5
Please enter value 3 : 4
Please enter value 4 : 8
Please enter value 5 : 62
The largest value is : 62
Press any key to continue . . .
*/