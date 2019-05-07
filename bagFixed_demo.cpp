// FILE: bagFixedFixed_demo.cpp
// This is a small demonstration program showing how the bagFixed class is used.

// Taken from Data Structures and Other Objects 
// Using C++ by Michael Main and Walter Savitch

#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <set> // Proviedes access to a multiset container
using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void get_ages(multiset<int>& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members. These ages have been read and placed in the ages bagFixed, stopping
// when the bagFixed is full or when the user types a negative number.

void check_ages(multiset<int>& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members once again. Each age is removed from the ages bagFixed when it is typed,
// stopping when the bagFixed is empty.


void display_all_ages(multiset<int>& ages);
//Postcondition: all ages in multiset are displayed in order

int main( )
{
    multiset<int> ages;

    get_ages(ages);
	//display all items in multiset
	cout << "Here are the items in the multiset...";
	display_all_ages(ages);
    check_ages(ages);
    cout << "May your family live long and prosper." << endl;
    return EXIT_SUCCESS;  
}


void get_ages(multiset<int>& ages)
{
    int user_input;

    cout << "Type the ages in your family." << endl;
    cout << "Type a negative number when you are done:" << endl;
    cin >> user_input;
    while (user_input >= 0)
    {
		ages.insert(user_input);
        cin >> user_input;
    }
}

void check_ages(multiset<int>& ages)
{
    int user_input;

    cout << "Type those ages again. Press return after each age:" << endl;
    while (ages.size( ) > 0)
    {
        cin >> user_input;
        if (ages.erase(user_input))
            cout << "Yes, I've got that age and will remove it." << endl;
        else
            cout << "No, that age does not occur!" << endl;   
    }
}


void display_all_ages(multiset<int>& ages) {
	
	//display all ages in set using an iterator
	multiset<int>::const_iterator itr;

	for (itr = ages.begin(); itr != ages.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
}