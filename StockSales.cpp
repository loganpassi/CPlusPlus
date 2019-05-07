//Logan Passi
//StockSales.cpp
//02/23/2017
//CIS2541
//Program to caclulate and display the total stock profit or loss.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
bool fileValidation(fstream&, string);
float profitCalculator(fstream&, string, int, float, float, float, float);

int main()
{	
	int numbOfShares = 0, totalNumbOfShares = 0;
	float profit = 0.00, salePrice = 0.00, saleCommission = 0.00, purchasePrice = 0.00, purchaseCommission = 0.00, totalProfit = 0.00;
	string fname, stock;
	fstream inpFile;
	cout << "Please enter in input file name: ";
	getline(cin, fname);
	bool valid = fileValidation(inpFile, fname);
	if (!valid)
	{
		cerr << "Error opening file . . ." << endl;
		exit(-1);
	}
	cout << setw(10) << left << "STOCK" << setw(10) << right << "SHARES" << setw(15) << "P Price" << setw(15) << "S Price" << setw(20) << "Profit (Loss)" << endl;
	cout << setw(10) << left << "-----" << setw(10) << right << "------" << setw(15) << "-------" << setw(15) << "-------" << setw(20) << "-------------" << endl;
	cout << fixed;
	cout << setprecision(2);
	while (!inpFile.eof())
	{
		inpFile >> stock >> numbOfShares >> purchasePrice >> purchaseCommission >> salePrice >> saleCommission;
		profit = profitCalculator(inpFile, stock, numbOfShares, salePrice, saleCommission, purchasePrice, purchaseCommission);
		totalProfit += profit;
		totalNumbOfShares += numbOfShares;
		cout << setw(10) << left << stock << setw(10) << right << numbOfShares << setw(15) << purchasePrice << setw(15) << salePrice << setw(20) << profit << endl;
	}
	inpFile.close();
	cout << endl << "Total Profit (Loss) for " << totalNumbOfShares << " shares = $" << totalProfit << endl;
	return 0;
}

bool fileValidation(fstream& inpFile, string fname)
{
	inpFile.open(fname, ios::in);if (!inpFile)
	{
		return false;
	
	}
	else
	{
		return true;
	}
}

float profitCalculator(fstream& inpFile, string stock, int numbOfShares, float salePrice, float saleCommission, float purchasePrice, float purchaseCommission)
{	
	float profit = 0.00;
	profit = ((numbOfShares*salePrice) - saleCommission) - ((numbOfShares*purchasePrice) + purchaseCommission);
	return profit;
}

/*
Please enter in input file name: F:\CIS2541\P2_stocks.txt
STOCK         SHARES        P Price        S Price       Profit (Loss)
-----         ------        -------        -------       -------------
AAPL              23         102.30          96.25             -157.05
GE                15          23.00          28.87               70.15
MSFT              30          58.50          52.06             -213.10
GOOG              10         540.20         695.03             1528.40

Total Profit (Loss) for 78 shares = $1228.40
Press any key to continue . . .


or 

Please enter in input file name: X:
Error opening file . . .
Press any key to continue . . .
*/