/*
Logan Passi
CIS2542
11/27/2017
inheritExample.cpp
*/

#include <iostream>
using namespace std;


//create a base rectangle class
class rectangle {
protected:
	double width;
	double length;
public:
	//default constructor
	rectangle() : width(1.0), length(1.0) {};
	//parameterized constructor
	rectangle(double w, double l) : width(w), length(l) {};
	//getters
	double getWidth() const { return width; }
	double getLength() const { return length; }
	//calculation
	virtual double getArea() const { return width * length; }//need to add virtual because it is a base class function
};

//derived rectangular prism class from base rectangle
class rectPrism : public rectangle {
private:
	double height;
public:
	//constructors
	rectPrism() {
		height = 1.0;
		length = 1.0;
		width = 1.0;
	}
	rectPrism(double l, double w, double h) {
		length = l;
		height = h;
		width = w;

	}
	//getter
	double getHeight() const { return height; }
	//calculation function
	double getArea() const { return 2 * (width* height) * 2 * (rectangle::getArea()) + 2 * (height); }
	double getVolume() const { return rectangle::getArea() * height; }
};
void displayArea(const rectangle& r) {
	cout << "The area is " << r.getArea() << "." << endl;
}
int main() {
	rectangle r;
	rectPrism rP;
	cout << "***RECTANGLE***" << endl;
	displayArea(r);
	cout << "***RECTANGULAR PRISM***" << endl;
	displayArea(rP);
	cout << "The volume is " << rP.getVolume() << "." << endl;
	return EXIT_SUCCESS;
}
