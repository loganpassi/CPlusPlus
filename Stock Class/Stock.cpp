/*
Author: Logan Passi
Class: 2542
Date: 08/28/2017
File: Stock.cpp
Descr: Implementation file for the stock class
*/

#include "stock.h"

//constructor--> initialize stock data using defaults

stock::stock()
{
	symbol = "";
	numOfShares = 0;
	purPrice = 0.0F;
	currPrice = 0.0F;
}

stock::stock(string s, int ns, float pp, float cp) //:symbol(s), numOfShares(ns), purPrice(pp), currPrice(cp);
{
	symbol = s;
	numOfShares = ns;
	purPrice = pp;
	currPrice = cp;
}

//copy constructor--> initialze stock obj with passed parameter stock obj
stock::stock(stock& s)
{
	//cout << "\n\t***copy constructor called***\n";
	symbol = s.symbol;
	numOfShares = s.numOfShares;
	purPrice = s.purPrice;
	currPrice = s.currPrice;
}

void stock::setSymbol(string s)
{
	symbol = s;
}

void stock::setShares(int ns)
{
	numOfShares = ns;
}

void stock::setPurPrice(float pp)
{
	purPrice = pp;
}

void stock::setCurrPrice(float cp)
{
	currPrice = cp;
}

//valuation functions
float stock::initValue() const
{
	return purPrice * numOfShares;
}