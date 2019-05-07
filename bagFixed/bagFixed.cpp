//Logan Passi
//Date: 09/11/2017
//File: bagFixed.cpp
//Descr:
//Implementation file for bagFixed container class.

#include "bagFixed.h"
#include <cassert>

//allocate the memory for the class static constant
const bagFixed::size_type CAPACITY = 30;

//member funtion to insert an item into the bag
void bagFixed::insert(const value_type& entry) {
	//check to see if size is avalible
	assert(size() < CAPACITY);
	//place item in next avalible location
	data[used] = entry;
	//increment number of items used
	used++;
}

//member function to count number specific items
bagFixed::size_type bagFixed::count(const value_type& entry) {
	//local variables to hold count
	size_type count, index;
	//loop through all used elements and count
	for (index = 0; index < used; index++) {
		if (entry == data[index])
			count++;
		return count;
	}
}

//member function to remove item, if in bagFixed container
bool bagFixed::erase_one(const value_type& entry) {
	size_type index;
	//loop through array elements
	for (index = 0; index < used; index++) {
		if (entry == data[index])
			break;
	}
	//see if element is not found
	if (index == used)
		return false;
	// element has been found, remove it and decrease the number of used
	--used;
	data[index] = data[used];
	//return true if value has been found
	return true;
}

//operator overloaded as member function
void bagFixed::operator +=(const bagFixed& rhs) {
	//insure enough room for items to add
	assert(size() + rhs.size() <= CAPACITY);
	//hold original sizes
	size_type index, toCopy = rhs.used;
	//copy each item from the right hand side to the object, increment used
	for (index = 0; index < toCopy; index++) {
		data[used] = rhs.data[index];
	}
}

bagFixed operator + (const bagFixed& lhs, const bagFixed& rhs) {
	//ensure enough capacity enough to hold both bags
	assert(lhs.size() + rhs.size() <= bagFixed::CAPACITY);
	//create bagFixed to return
	bagFixed retVal;
	retVal += lhs;
	retVal += rhs;
	return retVal;
}