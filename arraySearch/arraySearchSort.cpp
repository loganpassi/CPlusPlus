//arraySearchSort.cpp
//Logan Passi
//03/06/2017
//Sample program to demonstrate the use of array algoritms such as searching and sorting

#include <iostream>
#include <vector>
using namespace std;

//function prototype
int linearSearch(const int[], int, int);
void showValues(const int[], int);
void showValues(vector<int>);

//bubble sort function
void bubbleSort(int list[], int numElems)
{
	bool swap; //flag for efficiency
	int temp; //swap variable
	do {
		swap = false;
		// bubble largest to end
		for (int count = 0; count < (numElems - 1); count++)
		{
			if (list[count] > list[count + 1])
			{
				//swap elements
				temp = list[count];
				list[count] = list[count + 1];
				list[count + 1] = temp;
				swap = true;
			}
		}
	}while (swap);
}

int main()
{
	//create simple array with installer list
	int iArr[] = { 32, -15, 572, 0, -225, 66, -99, 572 };
	int iSize = sizeof(iArr) / sizeof(int);
	//display array
	showValues(iArr, iSize);
	//sort the array
	bubbleSort(iArr, iSize);
	cout << "Sorted array..." << endl;
	showValues(iArr, iSize);
	//prompt user for value to search
	int searchVal;
	cout << "Please input an integer to search ";
	cin >> searchVal;
	int retVal =  linearSearch(iArr, iSize, searchVal);
	//see if value found
	if (retVal < 0)
	{
		cout << "Sorry value " << searchVal << " is not found!" << endl;
	}
	else
	{
		cout << "Yes! Value " << searchVal << " is found at index " << retVal << endl;
	}
	return 0;
}
