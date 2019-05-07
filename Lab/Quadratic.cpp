//Logan Passi
//CIS2542
//09/06/2017
//Lab #2 Classes and Namespaces
#include "Quadratic.h"

quadratic::quadratic()
{
	a = 0.0F;
	b = 0.0F;
	c = 0.0F;
}

void quadratic::setA(float A) {
	a = A;
}

void quadratic::setB(float B) {
	b = B;
}

void quadratic::setC(float C) {
	c = C;
}

quadratic operator + (const quadratic& q1, const quadratic& q2) {
	quadratic abc;
	abc.setA(q1.getA() + q2.getA());
	abc.setB(q1.getB() + q2.getB());
	abc.setC(q1.getC() + q2.getC());
	return abc;
}

quadratic operator * (double m, const quadratic& q)
{
	quadratic abc;
	abc.setA(m * q.getA());
	abc.setB(m * q.getB());
	abc.setC(m * q.getC());
	return abc;
}

double quadratic::evalQuadForX(double x)
{
	double result;
	result = (a*x*x) + (b*x) + c;
	return result;
}

/*
Input the values for the first quadratic expression.
a: 3.2
b: 5.5
c: 1.7

The quadratic expression is:
3.2x^2 + 5.5x + 1.7

Enter a value for x: 2
Evaluation of the quadratic expression is: 25.5

Input the values for the second quadratic expression
to add to the first.
a: 1.8
b: 5
c: 3.2

The quadratic expression is:
1.8x^2 + 5x + 3.2

Added quadratic expression is: 5x^2 + 10.5x + 4.9

Enter a value for x: 3.5

Evaluation of the quadratic expression is: 102.9

Input the multiplier value for the third quadratic expression
to multiply with the first: 7.7

The multiplied quadratic expression is: 24.64x^2 + 42.35x + 13.09

Please enter a value for x: 8.1

Evaluation of the quadratic expression is: 1972.76
Press any key to continue . . .*/