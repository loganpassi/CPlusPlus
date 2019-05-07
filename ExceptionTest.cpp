/*
Author: Logan Passi
Class: CIS242
File: ExceptTest.cpp
Date: 08/23/2017
Descr:
In class exercise to practice the use of debugging and 
exception handling for a sample problem
to calculate the square root of a number*/

#define NDEBUG // turing off assertion checks
#include <iostream>
#include <cassert>
using namespace std;


//function prototype
double calc_sqrt(double);
double calc_sqrt_except(double);


//main function that starts program
int main(void)
{
	//local variables
	double inVal, sqVal;
	cout << "Please input a positive value: ";
	cin >> inVal;
	// calc and display{
	//sqVal = calc_sqrt(inVal);
	//incorporate excepton handling with try/catch
	try
	{
		sqVal = calc_sqrt_except(inVal);
	}
	/*
	catch (char* str)
	{
		cout << str << endl;
		exit(EXIT_FAILURE);
	}
	*/
	//catch all will handle any exception thrown
	//order is important-->specific to general types
	catch (...)
	{
		cerr << "Exception thrown" << endl;
		exit(EXIT_FAILURE);
	}
	cout << "The square root of " << inVal << " is " << sqVal << endl;
	return EXIT_SUCCESS;
}

//function to calculate square root
//Precondition: val >= 0
//Postcondiditon: sqrt of val is returned
double calc_sqrt(double val)
{
	// use assertion to ensure precondition
	assert(val >= 0);
	return sqrt(val);
}

//function to calc the sqrt
//Precondition: val >= 0
//Postcondition: square root of val is returned
double calc_sqrt_except(double val)
{
	//see if precondition is met
	if (val < 0)
		throw "ERROR! val < 0";
	//no exception thrown; continue processing
	return sqrt(val);
}