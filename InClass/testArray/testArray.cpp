#include <iostream>
using namespace std;

int main()
{
	const int SIZE5 = 5;
	int arr5[SIZE5] = { 0 };
	for (int &iarr : arr5)
	{
		cout << "Please enter an integer value: ";
		cin >> iarr;
	}
	for (int i = 0; i < SIZE5; i++)
	{
		cout << arr5[i] << endl;
	}
	return 0;
}