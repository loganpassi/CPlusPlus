/*
Logan Passi
01/27/2020
arrAvg.cpp
Short program to calculate the average value in a vector and then count how many values are larger than that average.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int count = 0; //holds the number of values larger than the average
	int sum = 0; //holds the sum of all the elements
	int avg = 0; //holds the average of all the elements
	int listLen = 0; //holds the length of the vector

	cout << "Please enter in the length of the vector: "; //Prompt and get input from the user for the length of the vector
	cin >> listLen;

	while (listLen > 100) { //Ensure that the length of the vector is smaller than 100
		cout << "Please enter a value smaller than 100: ";
		cin >> listLen;
	}

	cout << endl;

	vector<int> numVec;
	numVec.resize(listLen); //Resize the vector the appropriate length

	for (int i = 0; i < listLen; ++i) { //Iterate through the vector to get values for each element
		cout << "Please enter a value for element " << (i + 1) << ": ";
		cin >> numVec[i];
		sum += numVec[i];
	}

	avg = sum / listLen; //Calcuate the average

	for (int i = 0; i < listLen; ++i) { //Find how many values are larger than the average
		if (numVec[i] > avg) {
			count++;
		}
	}

	cout << endl << "The average value is: " << avg << endl; //Output the average and the number of values larger than the average
	cout << "The number of values that is larger than the average is :" << count << endl;
}
