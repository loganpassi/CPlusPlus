/*
Logan Antonio Passi
CIS542
11/19/17
Candy.cpp
*/

#include "Candy.h"


candy::candy() {
	name = "";
	calories = 0;
}

void candy::set_name(string s) {
	name = s;
}

void candy::set_calories(int c) {
	calories = c;
}