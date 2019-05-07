/*
Author:	
Class:	CIS2542
Date:	08/28/2017
File:	stock.cpp
Descr:
Implementation file for the stock class.
*/

#include "stock.h"

//constructor-->initialize stock data using defaults
// precondition:  none
// postcondition: stock object has valid symbol, number of shares, purchase price, and current price
stock::stock() {
	symbol = "";
	numShares = 0;
	purchPrice = 0.0F;
	currPrice = 0.0F;
}
// constructor-->initialize stock data with parameters
// using member initialization list
stock::stock(string s, int ns, float pp, float cp) 
	: currPrice(cp) {
	setNumShares(ns);
	setPurchPrice(pp);
	symbol = s;
}
// constructor-->initialize stock object with passed parameter stock object
stock::stock(const stock& s) {
	symbol = s.symbol;
	numShares = s.numShares;
	purchPrice = s.purchPrice;
	currPrice = s.currPrice;
}

// mutator functions
// precondition:  none
// postcondition: stock object has valid data for given member
void stock::setSymbol(string s) {
	symbol = s;
}
void stock::setNumShares(int ns) {
	// cannot have negative number of shares
	if (ns < 0)
	{
		// throw point --> throw keyword followed by any argument
		throw "**ERROR** stock setNumShares(): shares invalid";
	}
	else
	{
		numShares = ns;
	}
}
void stock::setPurchPrice(float pp) {
	// cannot have negative purchase price
	if (pp < 0.0F)
	{
		// throw point --> throw keyword followed by any argument
		throw string("**ERROR** stock setPurchPrice(): purchase price invalid");
	}
	else
	{
		purchPrice = pp;
	}
}
void stock::setCurrPrice(float cp) {
	currPrice = cp;
}

// valuation functions

// precondition:  stock has valid purchase price and number of shares
// postcondition: return value is initial stock valuation
float stock::initValue() const {
	return purchPrice * numShares;
}

//precondition: stock has value current price and number of shares
//postcondition: return value is current stock evaluation
float stock::currValue() const {
	return currPrice * numShares;
}

//precondition: stock has valid purchase and current price and number of shares
//postcondition: return value is difference between current and intial values
float stock::gainLoss() const {
	return currValue() - initValue();
}

//operator overload as member function
stock& stock::operator = (const stock& s)
{
	//copy over values
	symbol = s.symbol;
	numShares = s.numShares;
	currPrice = s.currPrice;
	purchPrice = s.purchPrice;
	return *this;
}