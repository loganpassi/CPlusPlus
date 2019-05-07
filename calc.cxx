// FILE: calc.cxx
// Basic calculator program that takes a fully parenthesized arithmetic
// expression as input, and evaluates the arithmetic expression.
// The purpose is to illustrate a fundamental use of stacks.

#include <cctype>     // Provides isdigit
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <cstring>    // Provides strchr
#include <iostream>   // Provides cout, cin, peek, ignore
#include <stack>      // Provides the stack template class
#include <cassert>
using namespace std;

// PROTOTYPES for functions used by this demonstration program:
double read_and_evaluate(istream& ins);
// Precondition: The next line of characters in the istream ins is a fully
// parenthesized arithmetic expression formed from non-negative numbers and
// the four operations + - * /.
// Postcondition: A line has been read from the istream ins, and this line has
// been evaluated as an arithmetic expression. The value of the expression has
// been returned by the function.

void evaluate_stack_tops(stack<double>& numbers, char& operations);
// Precondition: The top of the operations stack contains + - * or /, and the
// numbers stack contains at least two numbers.
// Postcondition: The top two numbers have been popped from the number stack,
// and the top operation has been popped from the operation stack. The two
// numbers have been combined using the operation (with the second number
// popped as the left operand). The result of the operation has then been
// pushed back onto the numbers stack.


int main( )
{
    double answer;

	cout << "Type a post fix expression:";
	//loop while user has expressions to enter
	while (cin && cin.peek() != '\n') {
		answer = read_and_evaluate(cin);
		cout << "That evaluates => " << answer << endl;
		cin.ignore(); //remove trailing newLine
		cout << "Type another postfix expression or <Enter> to end: ";

	}
   // answer = read_and_evaluate(cin);
    //cout << "That evaluates to " << answer << endl;

    return EXIT_SUCCESS;
}


double read_and_evaluate(istream& ins)
// Library facilities used: cstring, iostream, stack
{
    const char DECIMAL = '.';
    const char RIGHT_PARENTHESIS = ')';

    stack<double> numbers;
    //stack<char> operations;
    double number;
    char symbol;
    
    // Loop continues while istream is not “bad” (tested by ins) and next character isn’t newline.
    while (ins && ins.peek( ) != '\n')
    {
        if (isdigit(ins.peek( )) || (ins.peek( ) == DECIMAL))
        {
            ins >> number;
            numbers.push(number);
        }
        else if (strchr("+-*/", ins.peek( )) != nullptr)
        {
            ins >> symbol;
			evaluate_stack_tops(numbers, symbol);
            //operations.push(symbol);
        }
        else if (ins.peek( ) == RIGHT_PARENTHESIS)
        {
            ins.ignore( );
            evaluate_stack_tops(numbers, symbol);
        }
        else
            ins.ignore( );
    }
	assert(numbers.size() == 1); //ensure only one value left
	double answer = numbers.top(); //get value
    numbers.pop( ); //remove value from stack
	return answer; //return value
}

void evaluate_stack_tops(stack<double>& numbers, char& operations)
// Library facilities used: stack
{
    double operand1, operand2;
	assert(numbers.size() >= 2); //ensure that there are two operands for operator
    operand2 = numbers.top( );
    numbers.pop( );
    operand1 = numbers.top( );
    numbers.pop( );
    switch (operations)
    {
        case '+': numbers.push(operand1 + operand2);
                  break;
        case '-': numbers.push(operand1 - operand2);
                  break;
        case '*': numbers.push(operand1 * operand2);
                  break;
        case '/': numbers.push(operand1 / operand2);
			assert(operand2 != 0);
                  break;
    }
    //operations.pop( );
}

