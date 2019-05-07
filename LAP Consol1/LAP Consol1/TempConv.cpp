/*
	Logan Passi
	TempConv.cpp
	1/25/2017
	first program to convert f to c.
*/

#include <iostream>
using namespace std;

int main() {
	// local variables
	const float CNV_FACTOR = 5.0F / 9;
	//named constant
	float fahr = 212, cels;
	cout << "This program converts input Fahrenheit to Celsius." << endl;
	//convert f to c
	cels = CNV_FACTOR * (fahr - 32);
	//output conversion
	cout << "Fahrenheit: " << fahr << endl;
	cout << "Celsius :" << cels << endl;
	return 0;
}