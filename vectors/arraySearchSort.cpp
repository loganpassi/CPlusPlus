//arraySearchSort.cpp
//Logan Passi
//03/06/2017
//Sample program to demonstrate the use of array algoritms such as searching and sorting

#include <iostream>
#include <vector>
using namespace std;

//function prototype

void showValues(const int[], int);
void showValues(vector<int>);

int main()
{
	//create simple array with installer list
	int iArr[] = { 32, -15, 572, 0, 572, 0, -225, 66, -99, 572 };
	int iSize = sizeof(iArr) / sizeof(int);
	//display array
	showValues(iArr, iSize);
	return 0;
}
