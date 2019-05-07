/*
Author:	
Class:	CIS2542
Date:	08/28/2017
File:	StockTester.cpp
Descr:
In class exercise to demonstrate use of the stock class.
*/
#include "stock.h"

// function to take passed stock object and display
void DisplayStockData(stock s) {
	cout << "\n***STOCK DATA***" << endl;
	cout << "\tSymbol -> " << s.getSymbol() << endl;
	cout << "\tNumber of Shares -> " << s.numShares << endl;
	cout << "\tPurchase Price -> " << s.purchPrice << endl;
	cout << "\tCurrent Price -> " << s.currPrice << endl;
	cout << "\tInitial Value -> " << s.initValue() << endl;
	cout << "\tCurrent Value -> " << s.currValue() << endl;
	cout << "\tGain or Loss -> " << s.gainLoss() << endl;
}

//overload < operator as free function to compare symbols
bool operator < (const stock& lhs, const stock& rhs)
{
	return lhs.getSymbol() < rhs.getSymbol();
}

//overload << operator as friend function
ostream& operator << (ostream& out, const stock& s)
{
	out << endl << s.symbol << " " << s.numShares << " " << s.purchPrice << endl;
	return out;
}
	

int main() {
	// create local variables to hold user input
	string stkSym;
	int shares;
	float pPrice, cPrice;
	// get user input
	cout << "Please input the stock symbol: ";
	cin >> stkSym;
	cout << "Please input the integer number of shares: ";
	cin >> shares;
	cout << "Please input the purchase price: ";
	cin >> pPrice;
	cout << "Please input the current price: ";
	cin >> cPrice;
	try
	{
		// create some stock objects
		stock st1(stkSym, shares, pPrice, cPrice), st2, st3(st1);
		// display stock data
		cout << "st1\n";
		DisplayStockData(st1);
		cout << "st2\n";
		DisplayStockData(st2);
		cout << "st3\n";
		st3.setSymbol("CIS2542"); // using mutator
		DisplayStockData(st3);
		//compare stock objects
		if (st1 < st3)
		{
			cout << st1.getSymbol() << " is less than " << st3.getSymbol() << endl;
		}
		//insertion operator
		cout << st1 << endl;
		//assignment operator
		cout << st2 << endl;
		st2 = st1;
		cout << st2 << endl;
	}
	catch (char *cstring)
	{
		cout << cstring << endl;
		return EXIT_FAILURE;
	}
	catch (...)
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}