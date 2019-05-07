//Logan Passi
//StockLookUp.cpp
//CIS2541
//03/20/17
//Program to read from a file and output data from the file utilizing pointers and parallel arrays

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <locale>
using namespace std;

void bubbleSort(string*, int);
int arrSearch(string*, int, string);

int main()
{
	fstream inFile;
	string fname, symbol, *tradingSymbol, *companyName;
	int remainingStocks, *numOfShares, index;
	float *currentPrice, *currentValue;
	cout << "Please enter in the file directory : ";
	getline(cin, fname);
	cout << endl;
	inFile.open(fname, ios::in); // open file
	if (!inFile) // check if file has been opened
		return -1;
	for (int i = 0; !inFile.eof(); i++)// read only the first line from the file
	{
		if (i == 0)
		{
			inFile >> remainingStocks;
			break;
		}
	}
	numOfShares = new int[remainingStocks]; //create dynamic arrays
	companyName = new string[remainingStocks];
	tradingSymbol = new string[remainingStocks];
	currentPrice = new float[remainingStocks];
	for (int i = 0; i < remainingStocks; i++)
	{
			inFile >> tradingSymbol[i], getline(inFile, companyName[i], '#') >> numOfShares[i] >> currentPrice[i];
	}
	string *tradingSymbolCopy = new string[remainingStocks];
	for (int i = 0; i < remainingStocks; i++)
	{
		tradingSymbolCopy[i] = tradingSymbol[i]; //makes a copy of the tradingSymbol array before it is sorted
	}
	cout << "Availible stocks: " << endl << endl;;
	bubbleSort(tradingSymbolCopy, remainingStocks);
	cout << endl << endl;
	currentValue = new float[remainingStocks];
	for (int i = 0; i < remainingStocks; i++) //calculate the current value for each stock
	{
		currentValue[i] = currentPrice[i] * numOfShares[i];
	}
	cout << fixed;
	cout << setprecision(2);
	cout << "Enter the symbol: "; //get symbol from user
	cin >> symbol;
	index = arrSearch(tradingSymbol, remainingStocks, symbol); //call arrSearch function
	cout << endl << endl;
	if (index != -1) // output the stock data
	{
		cout << setw(35) << left << "Company Name:" << right << setw(30) << companyName[index] << endl;
		cout << setw(35) << left << "Number of Shares:" << right << setw(30) << numOfShares[index] << endl;
		cout << setw(35) << left << "Current Price (per share):" << right << setw(30) << currentPrice[index] << endl;
		cout << setw(35) << left << "Current Value:" << right << setw(30) << currentValue[index] << endl << endl;
	}
	else
		return -1;
	inFile.close(); // close input file
	delete[] tradingSymbol, tradingSymbolCopy, companyName, numOfShares, currentPrice; //release memory
	return 0;
}


void bubbleSort(string *tradingSymbolCopy, int remainingStocks) 
{
	bool swap;  // flag for efficiency
	string temp;   // swap variable
	do {
		swap = false;
		// 'bubble' largest to end
		for (int count = 0; count < (remainingStocks - 1); count++) {
			if (tradingSymbolCopy[count] > tradingSymbolCopy[count + 1]) {
				// swap elements
				temp = tradingSymbolCopy[count];
				tradingSymbolCopy[count] = tradingSymbolCopy[count + 1];
				tradingSymbolCopy[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
	for (int i = 0; i < remainingStocks; i++)
	{
		cout << tradingSymbolCopy[i] << " ";
		if (i == 2)
			cout << endl;
	}
}

int arrSearch(string *tradingSymbol, int remainingStocks, string symbol)
{
	int index;
	for (unsigned int i = 0; i < symbol.length(); i++) //make user input uppercase
	{
		symbol[i] = toupper(symbol[i]);
	}
	for (int i = 0; i < remainingStocks; i++) //find the index of the symbol in the array
	{
		if (tradingSymbol[i] == symbol)
		{
			index = i;
			break;
		}
		else
		{
			index = -1;
		}
	}
	return index;
}

/*
Please enter in the file directory : H:\CIS2541\P3_stkPort.txt

Availible stocks :

BA F HD
MCD WMT

Enter the symbol : hd


Company Name : The Home Depot, Inc.
Number of Shares : 31
Current Price(per share) : 115.54
Current Value : 3581.74

Press any key to continue . . .
*/