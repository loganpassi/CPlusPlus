//	Logan Passi
//	1/30/2017
//	CIS2541
//	Lab1.cpp
//	Lab1, First lab assignment to calc and display the cost of a purchased item.

#include <iostream>
using namespace std;

int main()
{
	//name constant to hold tax rates
	const float STATE_TAX = 0.04F;
	const double COUNTY_TAX = 0.02;

	//variables to hold calculation values
	float purchasePrice, countySalesTax, stateSalesTax, totalPrice;
	purchasePrice = 95.00;

	//calculate
	countySalesTax = purchasePrice * static_cast<float>(COUNTY_TAX); //Temp cast
	stateSalesTax = purchasePrice * STATE_TAX;
	totalPrice = countySalesTax + stateSalesTax + purchasePrice;

	//output value
	cout << "The purchase price is $" << purchasePrice << "." << endl;
	cout << "The county sales tax is $" << countySalesTax << "."<<endl;
	cout << "The state tax is $" << stateSalesTax << "."<<endl;
	cout << "The total price is $" << totalPrice << "." << endl;

}




