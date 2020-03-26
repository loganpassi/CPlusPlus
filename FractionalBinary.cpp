/*
Logan Passi
03/25/2020
FractionalBinary.cpp

Short program to convert fractional decimal values to binary.
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	double myNum;
	int intNum;
	double dblNum;
	int counter = 0;

	cout << "Enter a number: ";
	cin >> myNum;

	intNum = static_cast<int>(myNum);			//Get the value before the decimal
	dblNum = myNum - intNum;					//Get the value after the decimal

	cout << "Decimal Value: " << myNum << endl;
	cout << "Binary Value: ";

	stack<int> binStack;

	while (intNum != 0) {						//Convert the integer value to binary
		binStack.push(intNum % 2);
		intNum /= 2;
		counter++;
	}

	for (int i = 0; i < counter; i++) {
		cout << binStack.top();
		binStack.pop();
	}

	cout << ".";

	string myStr;

	while (dblNum != 0) {					//Convert the decimal value to binary
		myNum = dblNum * 2;
		intNum = static_cast<int>(myNum);
		dblNum = myNum - intNum;
		myStr += to_string(intNum);
	}
	
	cout << myStr;

	return 0;
}


/*
Enter a number: 3.25
Decimal Value: 3.25
Binary Value: 11.01
*/