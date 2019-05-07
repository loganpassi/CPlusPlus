// FILE: bagListdemo.cxx
// Demonstration program for the 3rd version of the bag (bagList.h and bagList.cpp).
// This is a the same as the demonstration program for bagFixed,
// except that we no longer need to check whether the bagList reaches its
// capacity.

#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "bagList.h"       // With Item defined as an int
using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void get_ages(bagList& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members. These ages have been read and placed in the ages bagList, stopping
// when the user types a negative number.

void check_ages(bagList& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members once again. Each age is removed from the ages bagList when it is typed,
// stopping when the bagList is empty.


int main( )
{
    bagList ages, assignedAges, copiedAges;
    get_ages(ages);
	assignedAges = ages;
	copiedAges += ages;

	node::value_type searchVal;
	cout << "Input an age to count: ";
	cin >> searchVal;
	cout << "The number of " << searchVal << " is " << copiedAges.count(searchVal) << endl;
	size_t numRemoved = copiedAges.erase(searchVal);
	cout << "Number of items removed is " << numRemoved << endl;
	check_ages(ages);
	cout << "May your family live long and prosper." << endl;
    return EXIT_SUCCESS;  
}


void get_ages(bagList& ages)
{
    int user_input; // An age from the user's family

    cout << "Type the ages in your family. ";
    cout << "Type a negative number when you are done:" << endl;
    cin >> user_input;
    while (user_input >= 0)
    {
        ages.insert(user_input);
        cin >> user_input;
    }
}

void check_ages(bagList& ages)
{
    int user_input; // An age from the user's family

    cout << "Type those ages again. Press return after each age:" << endl;
    while (ages.size( ) > 0)
    {
        cin >> user_input;
        if (ages.erase_one(user_input))
            cout << "Yes, I've got that age and have removed it." << endl;
        else
            cout << "No, that age does not occur!" << endl;
    }
}
