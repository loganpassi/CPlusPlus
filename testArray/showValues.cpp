//Logan Passi
//The showValues function accetps any integer array and
//size of the array. Each element is output 
//separated by a space.

#include <iostream>
using namespace std;

void showValues(const int nums[], int size)
{
	for (int index = 0; index < size; index++)
	{
		cout << nums[index] << " ";
	}
	cout << endl;
}