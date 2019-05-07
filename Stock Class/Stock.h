#pragma once
/*
Author: Logan Passi
Class: 2542
Date: 08/28/2017
File: Stock.h
Descr: Declaration file for the stock class
*/

#include <string>
#include <iostream>
using namespace std;

class stock {
	string symbol;
	int numOfShares;
	float purPrice;
	float currPrice;
public:
	stock(); //default constructor
	stock(string, int, float, float); //parameterized constructor
	stock(stock&); //copy constructor
	~stock() { cout << "\n\t***destructor called***\n"; }
	// getter/accessor functions
	string getSymbol() const { return symbol; }
	int getShares() const { return numOfShares; }
	float getPurPrice() const { return purPrice; }
	float getCurrPrice() const { return currPrice; }
	// setter/mutator functions
	void setSymbol(string s);
	void setShares(int ns);
	void setPurPrice(float pp);
	void setCurrPrice(float cp);
	//calculation funciton
	float initValue() const;
};
