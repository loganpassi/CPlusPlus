#include <iostream>
#include <vector>
using namespace std;

/* The showValues function accepts an integer array   
   and size of the array.  Each element is output
   separated by a space. */
void showValues(const int nums[], int size)
{
	for (int index = 0; index < size; index++)
		cout << nums[index] << ' ';
	cout << endl;
}

void showValues(vector<int> nums)
{
	for (unsigned int index = 0; index < nums.size(); index++)
		cout << nums[index] << ' ';
	cout << endl;
}