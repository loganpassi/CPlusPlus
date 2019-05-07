//Logan Passi
//08/23/2017
//QuadraticProblem.cpp
//CIS2542

//#define NDEBUG // turn off assertion checks
#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip>

using namespace std;

void quad_form(double, double, double, double&, double&);
void quad_form_except(double, double, double, double&, double&);

//main function
int main()
{
	double a, b, c, x1, x2;
	cout << "Enter in the value for a: ";
	cin >> a;
	cout << "Enter in the value for b: ";
	cin >> b;
	cout << "Enter in the value for c: ";
	cin >> c;
	//quad_form(a, b, c, x1, x2);
	quad_form_except(a, b, c, x1, x2);
	cout << fixed;
	cout << setprecision(3);
	cout << "X1: " << x1 << endl;
	cout << "X2: " << x2 << endl;

	return EXIT_SUCCESS;
}


//quadratic formula function
//function with assert statement
void quad_form(double a, double b, double c, double &x1, double &x2)
{
	//precondition
	assert(a != 0);
	assert(b*b > 4*a*c);
	//postcondition
	x1 = (-b + sqrt((b*b) - 4 * a*c)) / (2 * a);
	x2 = (-b - sqrt((b*b) - 4 * a*c)) / (2 * a);
}

//exception handling funciton
void quad_form_except(double a, double b, double c, double &x1, double &x2)
{
	try
	{
		if ((a == 0) || (b*b < 4*a*c))
			throw "ERROR! Cannot divide by zero or take the root of a negative number.";
	}
	catch (char* str)
	{
		cerr << str << endl;
		exit(EXIT_FAILURE);
	}
	x1 = (-b + sqrt((b*b) - 4 * a*c)) / (2 * a);
	x2 = (-b - sqrt((b*b) - 4 * a*c)) / (2 * a);
}