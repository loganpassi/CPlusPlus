// FILE: queueArrayImplementation.h
// TEMPLATE CLASS IMPLEMENTED: queueArray<Item> (see queueArray.h for documentation)
// This file is included in the header file, and not compiled separately.
// INVARIANT for the queueArray class:
//   1. The number of items in the queueArray is in the member variable count;
//   2. For a non-empty queueArray, the items are stored in a circular array
//      beginning at data[first] and continuing through data[last].
//      The array's total capacity of the array is CAPACITY.
//   3. For an empty array, last is some valid index, and first is
//      always equal to next_index(last).
//      

#include <cassert>  // Provides assert

template <class Item>
const typename queueArray<Item>::size_type queueArray<Item>::CAPACITY;

template <class Item>
queueArray<Item>::queueArray()
{
	count = 0;
	first = 0;
	last = CAPACITY - 1;
}

template <class Item>
Item queueArray<Item>::front() const
// Library facilities used: cassert
{
	assert(!empty());
	return data[first];
}

template <class Item>
void queueArray<Item>::pop()
// Library facilities used: cassert
{
	assert(!empty());
	first = next_index(first);
	--count;
}

template <class Item>
void queueArray<Item>::push(const Item& entry)
// Library facilities used: cassert
{
	assert(size() < CAPACITY);
	last = next_index(last);
	data[last] = entry;
	++count;
}

