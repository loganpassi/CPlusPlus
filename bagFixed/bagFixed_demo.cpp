// FILE: bagFixedFixed_demo.cpp
// This is a small demonstration program showing how the bagFixed class is used.

// Taken from Data Structures and Other Objects 
// Using C++ by Michael Main and Walter Savitch

#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "bagFixed.h"      // With value_type defined as an int
using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void get_ages(bagFixed& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members. These ages have been read and placed in the ages bagFixed, stopping
// when the bagFixed is full or when the user types a negative number.

void check_ages(bagFixed& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members once again. Each age is removed from the ages bagFixed when it is typed,
// stopping when the bagFixed is empty.


int main( )
{
    bagFixed ages, copyBag, addBag;

	
    get_ages(ages);
	//copy to another bag
    check_ages(ages);
	//combine both bags
	addBag = ages + copyBag;
	//remove from copy
	copyBag += ages;
	check_ages(copyBag);
	check_ages(addBag);
    cout << "May your family live long and prosper." << endl;
    return EXIT_SUCCESS;  
}


void get_ages(bagFixed& ages)
{
    int user_input;

    cout << "Type the ages in your family." << endl;
    cout << "Type a negative number when you are done:" << endl;
    cin >> user_input;
    while (user_input >= 0)
    {
        if (ages.size( ) < ages.CAPACITY) 
            ages.insert(user_input);
        else 
            cout << "I have run out of room and can’t add that age." << endl;
        cin >> user_input;
    }
}

void check_ages(bagFixed& ages)
{
    int user_input;

    cout << "Type those ages again. Press return after each age:" << endl;
    while (ages.size( ) > 0)
    {
        cin >> user_input;
        if (ages.erase_one(user_input))
            cout << "Yes, I've got that age and will remove it." << endl;
        else
            cout << "No, that age does not occur!" << endl;   
    }
}
