/*
     FILE:   FileLoop.cpp
	 AUTHOR: <Your Name Here>
	 DATE:   MM/DD/YYYY
	 DESCR:
	 This is a sample program to loop and read data 
	 from a file for subsequent processing.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//*************************************************
// The openFileIn function accepts a reference    *
// to an fstream object as an argument.  The file *
// is opened for intput.  The function returns    *
// true upon success, false upon failure.         *
//*************************************************
bool openFileIn(fstream& file, string name) {
	file.open(name, ios::in);
	if (file.fail())
		return false;
	else
		return true;
}

int main(void)
{
	fstream inFile;
	string fileName;
	int inpInt, numInts = 0, ttlInts = 0;
	const int MAX_INTS = 20;
	int inpIntArr[MAX_INTS];

	// open an existing file for input, fail if doesn't exist
	cout << "Please input a data file to read: ";
	getline(cin, fileName);
	// check for file open and write
	if (openFileIn(inFile, fileName)) {
		// using while loop, read all integers from file
		cout << "Reading integers from file..." << endl;
		numInts = 0;
		while (numInts < MAX_INTS && !inFile.eof())
		{
			inFile >> inpInt[numInts];
			numInts++;
			ttlInts += inpInt[numInts];
		}
		// close file
		inFile.close();

		// output number of integers read
		cout << "Number of integers read from file = " 
			<< numInts << endl;
		cout << "Total of integers read from file = " 
			<< ttlInts << endl;
	}
	else {
		cerr << "ERROR! Cannot open file for output!" << endl;
		return -1;
	}
	return 0;
}