//Logan Passi
//CIS2542
//09/06/2017
//Lab #2 Classes and Namespaces
using namespace std;
#include <iostream>
#include <string>

class quadratic {
	float a;
	float b;
	float c;
public:
	float x;
	//default constructor
	quadratic();
	void setA(float A);
	void setB(float B);
	void setC(float C);
	double getA() const { return a; }
	double getB() const { return b; }
	double getC() const { return c; }
	double evalQuadForX(double x);

};