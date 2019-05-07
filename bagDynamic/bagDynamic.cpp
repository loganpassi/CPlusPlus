// FILE: bagDynamic.cpp
// CLASS implemented: bagDynamic (see bagDynamic.h for documentation)
// INVARIANT for the bagDynamic class:
//   1. The number of items in the bagDynamic is in the member variable used;
//   2. The actual items of the bagDynamic are stored in a partially filled array.
//      The array is a dynamic array, pointed to by the member variable data;
//   3. The size of the dynamic array is in the member variable capacity.

#include <cassert>       // Provides assert function
#include "bagDynamic.h"
using namespace std;

const bagDynamic::size_type bagDynamic::DEFAULT_CAPACITY;

//   bagDynamic(size_type initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The bagDynamic is empty with an initial capacity given by the
//     parameter. The insert function will work efficiently (without
//     allocating new memory) until this capacity is reached.
//
bagDynamic::bagDynamic(size_type initial_capacity) {
	data = new value_type[initial_capacity];
	capacity = initial_capacity;
	used = 0;
}

bagDynamic::bagDynamic(const bagDynamic& b) {

}

//   ~bagDynamic()
//     Postcondition: dynamically allocated memory for data member has been released
//
bagDynamic::~bagDynamic() {
	delete[] data;
}

//   size_type count(const value_type& target) const
//     Postcondition: Return value is number of times target is in the bagDynamic
//
bagDynamic::size_type bagDynamic::count(const value_type& target) const {
	size_type answer;
	size_type i;

	// loop through array keeping track of matching items
	for (i = 0, answer = 0; i < used; ++i)
		if (target == data[i])
			++answer;
	return answer;
}

//   void erase_one(const value_type& target)
//     Postcondition: If target was in the bagDynamic, then one copy has been removed;
//     otherwise the bagDynamic is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
bool bagDynamic::erase_one(const value_type& target) {
	size_type index; // The location of target in the data array    

					 // First, set index to the location of target in the data array,
					 // which could be as small as 0 or as large as used-1.
					 // If target is not in the array, then index will be set equal to used.
	index = 0;
	while ((index < used) && (data[index] != target))
		++index;

	if (index == used) // target isn't in the bagDynamic, so no work to do
		return false;

	// When execution reaches here, target is in the bagDynamic at data[index].
	// So, reduce used by 1 and copy the last item onto data[index].
	--used;
	data[index] = data[used];
	return true;
}

//   size_type erase(const value_type& target);
//     Postcondition: All copies of target have been removed from the bagDynamic.
//     The return value is the number of copies removed (which could be zero).
//
bagDynamic::size_type bagDynamic::erase(const value_type& target) {
	// variables to step through array and keep track of items removed
	size_type index = 0;
	size_type many_removed = 0;

	// loop through available elements
	while (index < used)
	{
		// if data item found
		if (data[index] == target)
		{
			// decrement number of container items 
			--used;
			// replace current with end element
			data[index] = data[used];
			// increment number of items found

			++many_removed;
		}
		else
			// data item not found; increment index
			++index;
	}
	// return number of items removed
	return many_removed;
}

//   void reserve(size_type new_capacity)
//     Postcondition: The bagDynamic's current capacity is changed to the
//     new_capacity (but not less than the number of items already in the
//     bagDynamic). The insert function will work efficiently (without allocating
//     new memory) until the new capacity is reached.
//
void bagDynamic::reserve(size_type new_capacity) {

	// The allocated memory is already the right size.
	if (new_capacity == capacity)
		return;

	// Can’t allocate less than we are using.
	if (new_capacity < used)
		new_capacity = used;

	// allocate memory for larger capacity
	value_type *larger_array = new value_type[new_capacity];

	// copy items from current to larger array
	for (size_type i = 0; i < used; ++i)
		larger_array[i] = data[i];

	// release old data, reassign data pointer, and reset capacity
	delete[] data;
	data = larger_array;
	capacity = new_capacity;
}

//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted into the bagDynamic.
//
void bagDynamic::insert(const value_type& entry) {   
	// add additional memory if at capacity
    if (used == capacity)
        reserve(used+1);
	// place item at end and increment number used
    data[used] = entry;
    ++used;
}

//   void operator +=(const bagDynamic& addend) 
//     Postcondition: Each item in addend has been added to this bagDynamic.
//
void bagDynamic::operator +=(const bagDynamic& addend) {
	// see if additional memory needed
    if (used + addend.used > capacity)
        reserve(used + addend.used);

	// copy items from addend to current
	size_type addUsed = addend.used;
	for (size_type i = 0; i < addUsed; ++i)
		data[used++] = addend.data[i];
}

//   bagDynamic operator +(const bagDynamic& b1, const bagDynamic& b2)
//   Postcondition: The bagDynamic returned is the union of b1 and b2.
//
bagDynamic operator +(const bagDynamic& b1, const bagDynamic& b2) {
	// create new bagDynamic with size equal to sum of both bagDynamic parameters
	bagDynamic answer(b1.size( ) + b2.size( ));
	// add items from first bagDynamic
	answer += b1; 
	// add items from second bagDynamic
	answer += b2;
	return answer;
}
