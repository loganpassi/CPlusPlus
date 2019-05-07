//Logan Passi
//CIS2541
//2/1/2017
//testRandom.cpp
//In class activity to test the generation of random numbers.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
	//local variables
	int rnum, min, max;
	cout << "Maxmimum randomum number is " << RAND_MAX << "." << endl;
	//get random number seed value
	unsigned int seed = static_cast<unsigned int>(time(0)); //number of seconds since 1/1/78
	//seed the random number
	srand(seed);
	//get random number
	rnum = rand();
	//display the random number
	//cout << "Generated random number is " << rnum<<"." << endl;
	//get minimum and maximum
	cout << "Please input a minimum number:";
	cin >> min;
	cout << "Please input a minimum number:";
	cin >> max;
	//generate the random number
	rnum = ( rand() % (max - min + 1)) + min;
	//output random generated number
	cout << "Random number between " << min << " and " << max << " is " << rnum << endl;
	return 0;
}