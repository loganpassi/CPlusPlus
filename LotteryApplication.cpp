//Logan Passi
//LotteryApplication.cpp
//03/01/2017
//CIS2541
//Lab #5

#include <iostream>
#include <ctime>
using namespace std;
void generateNumbers(int[], int);
int findMatches(int[], int[], int);

int main()
{
	const int SIZE = 5;
	int usrArr[SIZE], lotteryArr[SIZE];
	cout << "Please enter five numbers between 0 and 9: " << endl;
	for (int index = 0; index < SIZE; index++)
	{
		cin >> usrArr[index];	
	}
	cout << endl;
	generateNumbers(lotteryArr, SIZE);
	findMatches(usrArr, lotteryArr, SIZE);
	cout << "User Array: ";
	for (int index = 0; index < SIZE; index++)
	{	
		cout << usrArr[index];
	}
	cout << endl << "Lottery Array: ";
	for (int index = 0; index < SIZE; index++)
	{
		cout << lotteryArr[index];
	}
	cout << endl;

	return 0;
}

void generateNumbers(int lotteryArr[], int SIZE)
{
	int max = 9, min = 0;
	unsigned seed = time(0);
	srand(seed);
	for (int index = 0; index < 5; index++)
	{
		lotteryArr[index] = (rand() % (max - min + 1)) + min;
	}
}

int findMatches(int usrArr[], int lotteryArr[], int SIZE)
{
	int win = 0;
	for (int index = 0; index < SIZE; index++)
	{
		if (usrArr[index] == lotteryArr[index])
		{
			win++;

		}
	}
	if (win == 0)
	{
		cout << "You have not guessed any of the numbers." << endl;
	}
	else
	{
		cout << "You have correclty guessed " << win << " time(s)." << endl;
	}
	return 0;
}
/*
Please enter five numbers between 0 and 9:
1
5
6
4
8

You have not guessed any of the numbers.
User Array : 15648
Lottery Array : 88120
Press any key to continue . . .
*/