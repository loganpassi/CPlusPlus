//Logan Passi
//F2C_Convert.cpp
//02/20/2017
//In class activity to practive the use of functions.

#include <iostream>
using namespace std;

//global constant
const float FTOC_FACTOR = static_cast<float>(5) / 9;

//function prototype
float ftoc(float fahr);
void menuPrompt();
void getVal(float& fVAr);
void getVal(char& cVal);

//main function called by OS
int main() {
	float inpFahr, outCels;
	char inpChar;
	//loop while user wishes to continue
	do {
		//display menu
		menuPrompt();
		//get input data
		getVal(inpChar);
		//get input data
		if (toupper(inpChar) == 'F') {
			cout << "Please input a value to convert: ";
			getVal(inpFahr);
			//convert input fahrenheit to celsius
			outCels = ftoc(inpFahr);
			//display converted amount
			cout << "Celsius = " << outCels << endl;
		}
		//clears new line
		cin.ignore();
	} while (toupper(inpChar) != 'Q');
	return 0;
}

//function to display menu of options
void menuPrompt() {
	cout << "Input Menu\n";
	cout << "\tF: Fahr to Cels\n";
	cout << "\tQ: Quit\n";

}

//function to convert past fahrenheit value to celsius equivalent
float ftoc(float fahr) {
	static int numCalc;
	float cels;
	cels = (fahr - 32) * FTOC_FACTOR;
	cout << "\t\tNumber of conversions = " << ++numCalc << endl;
	return cels;
}

//function to take pass by reference parameter
//and return the user input value
void getVal(float& fVar) {
	cin >> fVar;
}

//overloaded function to take pass by reference parameter
//of type char and store single char input by user
void getVal(char& cVal) {
	cin.get(cVal);

}