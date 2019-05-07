/*
     FILE:   DataFileLoop.cpp
	 AUTHOR: Carolyn England
	 DATE:   MM/DD/YYYY
	 DESCR:
	 This is a sample program to loop and read data. 
	 Counters and accumulators are used to 
	 total the data.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
	// local variables
	int inpInt, intCntr, ttlInts;

	// add file access
	string filename;
	ifstream inputFile;
	ofstream outputFile;

	//inputFile.open("intData.txt");
	inputFile.open("D:\\CIS2541\\topics\\intData.txt");
	outputFile.open("results.txt");

	// get filename
	//cout << "Enter the filename: ";
	//cin >> filename;

	// open file and check for errors
	//inputFile.open(filename);
	if (!inputFile) {
		cout << "ERROR opening file!" << endl;
		exit(-1);
	}

	// initialize the counter
	intCntr = 0;
	// initialize the accumulator
	ttlInts = 0;

	// using while loop, total all integers
	while (!inputFile.eof())
	{
		inputFile >> inpInt;
		intCntr++;
		ttlInts += inpInt;
	}

	// close file
	inputFile.close();

	// print out total counts
	cout << "Total number of integers read = " 
		<< intCntr << endl;
	cout << "Total of all integers read = " 
		<< ttlInts << endl;

	// to file
	outputFile << "Total number of integers read = "
		<< intCntr << endl;
	outputFile << "Total of all integers read = "
		<< ttlInts << endl;
	// close file
	outputFile.close();
	cout << "Results printed to file..." << endl;

	return 0;
}

/* OUTPUT
Enter the filename: F:\COD\CurrCourses\CIS2541CPP\Topics\5LoopsFiles\intData.txt

Total number of integers read = 18
Total of all integers read = 2534
Press any key to continue . . .

Total number of integers read = 18
Total of all integers read = 2534
Results printed to file...
Press any key to continue . . .

*/