//Logan Passi
//CIS2542
//10/02/2017
//templateFunctions.cpp
//In class exercise to demonstrate the use of template functions.

#include <iostream>
#include <string>
using namespace std;

//template function to compare tow item
//for equivalency
template <class GenType>
bool equivalent(GenType first, GenType second) {
	return first == second;
}

//specialized template function to compare two string items
template <>
bool equivalent(string first, string second) {
	if (first.size() != second.size())
		return false;
	//check each character
	else {
		for (unsigned i = 0; i < first.size(); i++)
			if (tolower(first[i] != tolower(second[i])))
				return false;
			else
				return true;
	}		
}

template <class GenType>
bool equivalent(GenType first, GenType second, GenType third) {
	return first == second && second == third;
}

int main() {
	//checking for integer equivalency
	const int CHECK_VAL = 10;
	int iVal1, iVal2;
	cout << "Input two integers separated by a space: ";
	cin >> iVal1 >> iVal2;
	if (equivalent(iVal1, iVal2))
		cout << iVal1 << " and " << iVal2 << " are equivalent.";
	else
		cout << iVal1 << " and " << iVal2 << " are not equivalent.";
	cout << endl;

	if (equivalent(iVal1, iVal2, CHECK_VAL))
		cout << "All entered value are equal to check " << CHECK_VAL << endl;
	cout << endl;
	//checking for float equivilency
	float fVal1, fVal2;
	cout << "Insert two floating point numbers separated by a space: ";
	cin >> fVal1 >> fVal2;
	if (equivalent(fVal1, fVal2))
		cout << fVal1 << " and " << fVal2 << " are equivalent.";
	else
		cout << fVal1 << " and " << fVal2 << " are not equivivent.";
	cout << endl;

	//checking for string equivilency
	string sVal1, sVal2;
	cout << "Insert two strings separated by a space: ";
	cin >> sVal1 >> sVal2;
	if (equivalent(sVal1, sVal2))
		cout << sVal1 << " and " << sVal2 << " are equivalent.";
	else
		cout << sVal1 << " and " << sVal2 << " are not equivivent.";
	cout << endl;

	return EXIT_SUCCESS;
}