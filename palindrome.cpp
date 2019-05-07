/*
Logan Passi
10/25/2017
CIS2541
palindrome.cpp
*/

#include <iostream>
#include <stack>
//#include "C:\\Users\\cod_user\\Desktop\\queueArray\\queueArray.h"
#include "c:\\Users\\cod_user\\Desktop\\queueList\\queueList.h"

using namespace std;

int main() {
	// create stack and queue of characters
	stack<char> charStack;
	queueList<char> charQueue;
	char inpChar;
	bool matches = true;
	//get input from user
	cout << "Enter a line to check for a palindrome: ";
	while (cin.peek() != '\n') {
		cin >> inpChar;
		//check to see if alphanumeric character
		if (isalpha(inpChar)) {
			//add to stack and queue
			inpChar = toupper(inpChar);
			charStack.push(inpChar);
			charQueue.push(inpChar);
		}
	}
	//end of input characters
	//compare stack and queue
	while (!charQueue.empty() && !charStack.empty()) {
		//check o see if characters ro remove are equal
		if (charQueue.front() != charStack.top())
			matches = false;
		//remove items from stack and queue
		charQueue.pop();
		charStack.pop();
	}

	if (matches)
		cout << "You have entered a palindrome." << endl;
	else
		cout << "You have not entered a palindrome." << endl;

	return EXIT_SUCCESS;
}