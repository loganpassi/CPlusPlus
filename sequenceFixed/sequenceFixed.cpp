//Logan Passi
//CIS1451
//sequencedFixed.cpp
//09/13/2017
//Implementation file for the sequenceFixed class

#include "sequenceFixed.h"

const sequenceFixed::size_type CAPACITY = 30;

//constructor
//Postcondition: sequenceFixed has been initalize as empty
sequenceFixed::sequenceFixed() {
	used = 0;
	current_index = 0;
}

//const member function to return the current size
// Postcondition: return the number of items in the container
sequenceFixed::size_type sequenceFixed::size() const {
	return used;
}


//const member function to determin if current index is valid
//Postcondition: return value of true indicates current_index is valid
//return value of false indicates current_value is not valid
bool sequenceFixed::is_item() const {
	return (current_index < used);
}


//member function to set the current_index at the beginning
//of the sequence
//Postcondition: make the first item in the sequence the current_item
void sequenceFixed::start() {
	current_index = 0;
}


//const member function to return the value at the current index
//Precondition is_item returns true (i.e. valid index)
//Postcondition: item in the current_index position is returned
sequenceFixed::value_type sequenceFixed::current() const {
	assert(is_item());
	return data[current_index];
}


//member function to move the current index by 1
//Precondition: is_item returns tru (i.e. valid index)
//Postcondition: current_index has been increased by 1
void sequenceFixed::advance() {
	//ensure that current_index is less than used
	assert(is_item());
	current_index++;
}

//member function to insert an item at the current_index
//if current_index is not valid insert at beginning
//Precondition: make sure to have enough space in sequence to add item
//Postcondition: item inserted and current_index points to new item
void sequenceFixed::insert(const value_type& entry) {
	//ensure that enough avaibale space for new entry
	assert(size() < CAPACITY);
	// see if current_index is valid; if not reset current index to front
	if (is_item())
		current_index = 0;
	

	//move items over from current_index
	for (size_type i = used; i > current_index; --i)
	{
		data[i] = data[i - 1];
	}
	//insert new entry at current_index
	data[current_index] = entry;
	
	used++;
	//increment number of items used
}

//   void attach(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequenceFixed after
//     the current item. If there was no current item, then the new entry has 
//     been attached to the end of the sequenceFixed. In either case, the newly
//     inserted item is now the current item of the sequenceFixed.
void sequenceFixed::attach(const value_type& entry) {
	assert(size() < CAPACITY);

	if (current_index == used){
		data[current_index] = entry;
	}
	else {
		current_index++;
		for (size_type i = current_index; i < used; i++){
			data[i + 1] = data[i];
			}
	data[current_index] = entry;
		}
	used++;
}
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequenceFixed, and the
//     item after this (if there is one) is now the new current item.
void sequenceFixed::remove_current() {
	if (current_index == used - 1) {
		data[current_index - 1] == data[current_index];
		--current_index;
	}
	else {
		for (size_type i = current_index; i < used; i++) {
			data[i] = data[i + 1];
		}
	}
	
	--used;
}