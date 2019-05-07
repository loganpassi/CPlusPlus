//Logan Passi
//CIS2541
//2/13/2017
//DataLoop.cpp
//In class exercise to practice different loop types

#include <iostream>
using namespace std;

int main() {
	//local variables
	int numInts, numInts1, counter = 0, totalInt = 0;
	//get number of integers to read
	cout << "How many integers to read? ";
	cin >> numInts;
	//exit if positive number
	if (numInts < 0)
	{
		cout << "Sorry, need to have a non-negative number!" << endl;
		return(-1);
	}
	// read number of integers
	/*
	do {
		cout << "Please input an integer: ";
		cin >> numInts1;
		counter++;
	} while (counter < numInts);
	*/
	//read number of integers using pretest for loop
	for (;counter < numInts; counter++)
	{
		cout << "Please input an integer: ";
		cin >> numInts1;
		//only add up positive integers
		if (numInts1 < 0)
			continue;
		totalInt += numInts1;
	}
	/*
	while (counter < numInts)
	{
		cout << "Please input an integer: ";
		cin >> numInts1;
		counter++; // increment counter
		// only sum positive integers
		if (numInts1 < 0)
			//break;
			continue;	
		totalInt += numInts1;
	}
	*/
	// output total of entered itegers
	cout << "The total of " << counter << " integers is " << totalInt << endl;
	
	
	return 0;
}