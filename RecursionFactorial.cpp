// RecusionFactorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int recFact(int n);
int recFibonacci(int n);

int main()
{
	int factorial = 0;
	factorial = recFact(5);
	std::cout << "!5 = " << factorial << "\n";

	std::cout << recFibonacci(4) << "\n";
}

int recFact(int n) {
	static int sum = 0;

	//recursive case
	if (n != 0) {
		std::cout << n << "\n";
		return n * recFact(n - 1);
	}
	//base case
	else {
		return 1;
	}

}

int recFibonacci(int n) {

	//recursive case
	if (n >= 3) {
		return recFibonacci(n - 1) + recFibonacci(n - 2);
	}
	//base case
	else {
		return 1;
	}
}