// FILE: bagDynamicdemo.cxx
// Demonstration program for the 2nd version of the bagDynamic (bagDynamic.h and bagDynamic.cxx).
// This is a the same as the demonstration program for bagDynamic1,
// except that we no longer need to check whether the bagDynamic reaches its
// capacity.

#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "bagDynamic.h"       // With Item defined as an int
using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void get_ages(bagDynamic& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members. These ages have been read and placed in the ages bagDynamic, stopping
// when the user types a negative number.

void check_ages(bagDynamic& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members once again. Each age is removed from the ages bagDynamic when it is typed,
// stopping when the bagDynamic is empty.


int main( )
{
    bagDynamic ages;

    get_ages(ages);	

	// created copied and assiged bagDynamics
	bagDynamic copiedAges(ages), assignedAges;
	assignedAges = ages;

	cout << "\nRemoving ORIGINAL ages...";
	check_ages(ages);
	cout << "\nRemoving COPIED ages...";
	check_ages(copiedAges);
	cout << "\nRemoving ASSIGNED ages...";
	check_ages(assignedAges);

	cout << "May your family live long and prosper." << endl;
    return EXIT_SUCCESS;  
}


void get_ages(bagDynamic& ages)
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

void check_ages(bagDynamic& ages)
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