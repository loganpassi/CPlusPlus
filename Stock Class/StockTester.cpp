/*
Author: Logan Passi
Class: 2542
Date: 08/28/2017
File: StockTester.cpp
Descr: In class excercise to demontrate use of the stock class.
*/

#include "Stock.h"

//function to take passed stock obj and display

void displayStockData(stock s)
{
	cout << "\t***Stock Data***" << endl;
	cout << "\tSymbol: " << s.getSymbol() << endl;
	cout << "\tNumber of Shares: " << s.getShares() << endl;
	cout << "\tPurchase Price: " << s.getPurPrice() << endl;
	cout << "\tCurrent Price: " << s.getCurrPrice() << endl;
	cout << "\tInitial Value: " << s.initValue() << endl;
}

int main()
{
	//create local variables to hold user input
	string stkSym;
	int shares;
	float pPrice, cPrice;
	cout << "Please input the stock symbol: ";
	cin >> stkSym;
	cout << "Please input the integer number of shares: ";
	cin >> shares;
	cout << "Please input the purchase price: ";
	cin >> pPrice;
	cout << "Please input the current price: ";
	cin >> cPrice;
	//create some stock objects
	stock st1(stkSym, shares, pPrice, cPrice), st2, st3(st1);
	//display stock data
	cout << "\nstk1";
	displayStockData(st1);
	cout << "\nstk2";
	displayStockData(st2);
	cout << "\nstk3";
	st3.setSymbol("CIS2542"); //using mutator
	displayStockData(st3);
	return EXIT_SUCCESS;
}