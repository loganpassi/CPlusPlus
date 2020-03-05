/*
Logan Passi
03/04/2020
FactorialCalculator.cpp
Short Program to calculate the factorial of a number in an iterative and recursive process
*/

#include <iostream>

using namespace std;

void iterativeFact(int n);
void recursiveFact(int n, int t);

int main() {
	cout << "========Iteratively Caculating Factorial========" << endl;
	int myNum = 2;
	iterativeFact(myNum);

	myNum = 3;
	iterativeFact(myNum);

	myNum = 4;
	iterativeFact(myNum);

	cout << "========Recursively Calculating Factorial========" << endl;

	myNum = 2;
	cout << myNum;
	recursiveFact(myNum, 1);


	myNum = 3;
	cout << myNum;
	recursiveFact(myNum, 1);


	myNum = 4;
	cout << myNum;
	recursiveFact(myNum, 1);


}

void iterativeFact(int n) { //function to iteratively calculate the factorial of a given number
	int ttl = 1;
	for (int i = 2; i <= n; ++i) {
		ttl *= i;
	}

	cout << n << "! = " << ttl << endl;
}

void recursiveFact(int n, int t) { //Function to recursively calculate the factorial of a given number

	t *= n;
	n--;

	if (n != 0) {
		recursiveFact(n, t);
	}
	else {
		cout << "! = " << t << endl;
	}
}

/*
========Iteratively Caculating Factorial========
2! = 2
3! = 6
4! = 24
========Recursively Calculating Factorial========
2! = 2
3! = 6
4! = 24
*/