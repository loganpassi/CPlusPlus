/*
Logan Passi
CIS2542
11/27/2017
ABC_Example.cpp
*/
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

//abstract base class
class shape {
public:
	virtual double getArea() = 0; //pure virtual function
	virtual double getPerimeter() = 0;
};

//derived classes
class circle : public shape{
protected:
	double radius;
public:
	//constructor
	circle() : radius(1.0) {};
	circle(double r) : radius(r) {};
	//override virtual funciton
	double getArea() { return M_PI * radius * radius; }
	double getPerimeter();
};

//define outside class definition
double circle::getPerimeter() {
	return 2 * M_PI * radius;
}

class rectangle : public shape {
protected:
	double width, length;
public:
	rectangle() : width(1.0), length(1.0) {};
	rectangle(double l, double w) {
		width = w;
		length = l;
	}
	double getArea() { return width * length; }
	double getPerimeter() { return 2 * (width + length); }
};

class triangle : public shape {
protected:
	double side1, side2, side3;
public:
	triangle() : side1(1.0), side2(1.0), side3(1.0) {};
	triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {};
	double getArea() {
		double s = (side1 + side2 + side3) / 2;
		return sqrt(s * (s - side1) * (s - side2) * (s - side3));
	}
	double getPerimeter() { return side1 + side2 + side3; }
};

void displayShape(shape& s) {
	cout << "The area of the shape is " << s.getArea() << "." << endl;
	cout << "The perimeter of the shape is " << s.getPerimeter() << "." << endl;
}

int main() {
	circle c;
	rectangle r;
	triangle t;
	cout << "***CIRCLE***" << endl;
	displayShape(c);
	cout << "***RECTANGLE***" << endl;
	displayShape(r);
	cout << "***TRIANGLE***" << endl;
	displayShape(t);
	return EXIT_SUCCESS;
}