/*
Logan Antonio Passi
CIS542
11/14/17
Candy.h
*/
#ifndef CANDY_H
#define CANDY_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class candy {
public:
	//default constructor
	candy();
	
	//public getters
	string get_name() { return name; }
	int get_calories() { return calories; }

	//public setters
	void set_name(string s);
	void set_calories(int c);


	friend ostream& operator << (ostream& out, candy c) {
		cout << right << setw(10) << "Candy: " << left << c.get_name();
		cout << right << setw(10) << "\nCalories:  " << left << c.get_calories();
		cout << "\n\n===========================================\n";
		return out;
	}

private:
	string name;
	int calories;

};


#endif