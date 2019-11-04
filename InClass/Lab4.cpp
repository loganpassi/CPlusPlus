//Logan Passi
//Lab4.cpp
//02/22/2017
//CIS2541

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string fname;
	int number, counter = 0, total = 0;
	float average = 0.00;
	//prompt and read file name
	cout << "Please enter in input file name: ";
	getline(cin, fname);
	//create file stream for input
	fstream inFile(fname, ios::in);
	//check for errors
	if (!inFile)
	{
		cerr << "Error opening file . . ." << endl;
		exit(-1);
	}
	else
	{
		cout << "File has been opened!" << endl;
	}
	while (inFile >> number)
	{
		total = total + number;
		counter++;
	}
	cout << setprecision(3);
	cout << fixed;
	average = static_cast<float>(total) / static_cast<float>(counter);
	cout << setw(30) << left <<"Average Value: " << setw(15) << average << endl;
	cout << setw(30) << left << "Total Value: " << setw(15) << total << endl;
	cout << setw(30) << left <<"Amount of Values:" << setw(15) << counter << endl;
	inFile.close();
	return 0;
}
/*
Please enter in input file name: C:\Users\cod_user\Desktop\Random.txt
File has been opened!
Average Value:                527.635
Total Value:                  105527
Amount of Values:             200
Press any key to continue . . .
*/
