//Author: Krastan Dimitrov
//Date: 10/18/17
//Class: CIS 2542 Lab 7
//File: postFixEval.cpp
//Desc: evaluates an arithmetic expression in postfix notation

#include <iostream>
#include <stack>
#include <string>
#include <cassert>

using namespace std;

int main() {
	const char TIMES = '*';
	const char DIVIDE = '/';
	const char PLUS = '+';
	const char MINUS = '-';
	string toPush = "";
	double toPushD = 0.0;
	string expression = "";
	stack<double> nums;
	stack<char> operators;
	double dOne = 0;
	double dTwo = 0;

	cout << "Enter the postfix expression: ";
	getline(cin, expression);

	while (expression != "") {	//loops until user enters "Enter"
		for (size_t i = 0; i < expression.length(); i++)
		{
			while (!isspace(expression[i]) && toPush[0] != PLUS && toPush[0] != MINUS && toPush[0] != TIMES && toPush[0] != DIVIDE) {	//adds to toPush as long as its not a space or operator
				toPush += expression[i];
				i++;
			}

			if (isspace(expression[i]) || toPush[0] == PLUS || toPush[0] == MINUS || toPush[0] == TIMES || toPush[0] == DIVIDE) {	//if its a space or operator
				if (toPush.length() == 1) {
					if (toPush[0] != PLUS && toPush[0] != MINUS && toPush[0] != TIMES && toPush[0] != DIVIDE) {	//if its size 1 and not an operator, adds to nums
						toPushD = stod(toPush);
						nums.push(toPushD);
						toPush = "";
					}
					else {
						assert(nums.size() == 1);	//else adds to operators
						operators.push(toPush[0]);
						toPush = "";
					}
				}
				else {
					toPushD = stod(toPush);		//if its more than one characters adds to nums
					nums.push(toPushD);
					toPush = "";
				}

				if (!operators.empty()) {		//if there are operators then does whatever the operator says and adds the answer to nums while clearing operator and old nums
					dTwo = nums.top();
					nums.pop();
					dOne = nums.top();

					nums.pop();

					if (operators.top() == PLUS) {
						nums.push(dOne + dTwo);
					}
					else if (operators.top() == MINUS) {
						nums.push(dOne - dTwo);
					}
					else if (operators.top() == TIMES) {
						nums.push(dOne * dTwo);
					}
					else if (operators.top() == DIVIDE) {
						assert(dTwo != 0);
						nums.push(dOne / dTwo);
					}

					operators.pop();
				}

			}



		}
		cout << expression << " => evaluates to " << nums.top() << endl;	//displays last num in nums
		nums.pop();															//empties it
		assert(operators.empty());		//makes sure both stacks are all empty
		assert(nums.empty());			
		cout << "Enter another postfix expression or press enter to end: ";
		getline(cin, expression);
	}

	return EXIT_SUCCESS;
}

/*
Enter the postfix expression: .5 .25 /
.5 .25 / => evaluates to 2
Enter another postfix expression or press enter to end: 2.5 3.5 + 8.5 *
2.5 3.5 + 8.5 * => evaluates to 51
Enter another postfix expression or press enter to end: 5 3 2 * + 4 - 5 +
5 3 2 * + 4 - 5 + => evaluates to 12
Enter another postfix expression or press enter to end: 20 3 5 * + 5 /
20 3 5 * + 5 / => evaluates to 7
Enter another postfix expression or press enter to end: 2 3 /
2 3 / => evaluates to 0.666667
Enter another postfix expression or press enter to end:
Press any key to continue . . .
*/