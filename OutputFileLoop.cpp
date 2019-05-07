//Logan Passi
//OutputFileLoop.cpp
//02/22/2017
//CIS2541
//In class exercise to demonstrate use of fstream object and mulit-file objects
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
//function prototypes
string Dec2Bin(int decNum);


int main() {
	//local variables
	string fname;
	//prompt and read file name
	cout << "Please enter in output file name: ";
	getline(cin, fname);
	//create file stream for output
	fstream outFile(fname, ios::out);
	//check for errors
	if (!outFile)
	{
		cerr << "Error opening file . . ." << endl;
		exit(-1);
	}
	else
	{
		cout << "Output has been written to file!" << endl;
	}
	//display header
	outFile << setw(10) << "Decimal" << setw(15) << "Binary" << endl;
	outFile << setw(10) << "=======" << setw(15) << "=======" << endl;
	// loop to determine binary equivilant of decimal numbers 1-20
	for (int decNum = 1; decNum <= 20; decNum++)
	{
		outFile << setw(10) << decNum << setw(15) << Dec2Bin(decNum) << endl;
	}
	//close file
	outFile.close();
	return 0;
}