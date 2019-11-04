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
#include <vector>
using namespace std;

// function prototypes
void showValues(vector<int>);
void vectorSpecs(vector<int>);

//function to display vector statistics
void vectorSpecs(vector<int> num)
{
	cout << "Vector size = " << num.size() << endl;
	cout << "Vector capacity = " << num.capacity() << endl;
}

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
	// using arrays
	const int MAX_INTS = 20;
	int inpIntArr[MAX_INTS];
	//using a vector
	vector<int> inpIntVec;

	// open an existing file for input, fail if doesn't exist
	cout << "Please input a data file to read: ";
	getline(cin, fileName);
	//output vector specs
	vectorSpecs(inpIntVec);
	// check for file open and write
	if (openFileIn(inFile, fileName)) {
		// using while loop, read all integers from file
		cout << "Reading integers from file..." << endl;
		numInts = 0;
		//while (numInts < MAX_INTS && !inFile.eof())
		while (!inFile.eof())
		{
			//inFile >> inpIntArr[numInts]; // change to use array
			//ttlInts += inpIntArr[numInts];
			inFile >> inpInt;
			//using vector
			inpIntVec.push_back(inpInt);
			ttlInts += inpIntVec[inpIntVec.size() - 1];
			numInts++;
		}
		// close file
		inFile.close();

		//vector statistics
		cout << "Vector specs after file read" << endl;
		vectorSpecs(inpIntVec);

		// output number of integers read
		cout << "Number of integers read from file = " 
			<< numInts << endl;
		cout << "Total of integers read from file = " 
			<< ttlInts << endl;
		// output array values
		cout << "Contents of array: ";
		//showValues(inpIntArr, numInts);
		//output vector values
		cout << "Contents of vector: ";
		showValues(inpIntVec);
	}
	else {
		cerr << "ERROR! Cannot open file for output!" << endl;
		return -1;
	}
	return 0;
}