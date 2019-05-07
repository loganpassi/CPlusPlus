/*
Author:	
Class:	CIS2542
Date:	08/28/2017
File:	stock.h
Descr:
Declaration file for the stock class.
*/
#include <iostream>
#include <string>
using namespace std;

class stock {
	string symbol;
	int numShares;
	float purchPrice;
	float currPrice;
public:
	// constructors
	stock(); // default 
	stock(string, int, float, float);  // parameterized 
	stock(const stock&); // copy 
	// destructor
	~stock() { }
	// accessor functions-->inline function
	string getSymbol() const { return symbol; }
	int getNumShares() const { return numShares; }
	float getPurchPrice() const { return purchPrice; }
	float getCurrPrice() const { return currPrice; }
	// mutator functions
	void setSymbol(string s);
	void setNumShares(int ns);
	void setPurchPrice(float pp);
	void setCurrPrice(float cp);
	// valuation function
	float initValue() const;
	float currValue() const;
	float gainLoss() const;
	//friend function
	friend void DisplayStockData(stock s);
	friend ostream& operator << (ostream& out, const stock& s);
	// overload operator as a member function
	stock& operator =(const stock& s);
};