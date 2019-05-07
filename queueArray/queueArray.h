// FILE: queueArray.h 
// TEMPLATE CLASS PROVIDED: queueArray<Item> (a queueArray of items)
//
// TEMPLATE PARAMETER, ALIASES and MEMBER CONSTANTS for the stack<Item> class:
//   The template parameter, Item, is the data type of the items in the queueArray,
//   also defined as queueArray<Item>::value_type. It may be any of the C++ built-in
//   types (int, char, etc.), or a class with a default constructor, a copy
//   constructor, and an assignment operator. The definition
//   queueArray<Item>::size_type is the data type of any variable that keeps track of
//   how many items are in a queueArray. The static const CAPACITY is the
//   maximum capacity of a queueArray for this first queueArray implementation.
// NOTE:
//   Many compilers require the use of the new keyword typename before using
//   the expressions queueArray<Item>::value_type and queueArray<Item>::size_type.
//   Otherwise the compiler doesn't have enough information to realize that it
//   is the name of a data type.
//
// CONSTRUCTOR for the queueArray<Item> template class:
//   queueArray( )
//     Postcondition: The queueArray has been initialized as an empty queueArray.
//
// MODIFICATION MEMBER FUNCTIONS for the queueArray<Item> template class:
//   void pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The front item of the queueArray has been removed.
//
//   void push(const Item& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted at the rear of the
//     queueArray.
//
// CONSTANT MEMBER FUNCTIONS for the queueArray<Item> template class:
//   bool empty( ) const
//     Postcondition: The return value is true if the queueArray is empty.
//
//   Item front( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is the front item of the queueArray (but the queueArray is
//     unchanged). 
//
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the queueArray.
//
// VALUE SEMANTICS for the queueArray<Item> template class:
//   Assignments and the copy constructor may be used with queueArray<Item> objects.

#ifndef MAIN_SAVITCH_queueArray_H
#define MAIN_SAVITCH_queueArray_H
#include <cstdlib> // Provides size_t

template <class Item>
class queueArray
{
public:
	// ALIASES and MEMBER CONSTANTS -- See Appendix E if this fails to compile.
	using size_type = std::size_t;
	using value_type = Item;
	static const size_type CAPACITY = 30;
	// CONSTRUCTOR
	queueArray();
	// MODIFICATION MEMBER FUNCTIONS
	void pop();
	void push(const Item& entry);
	// CONSTANT MEMBER FUNCTIONS
	bool empty() const { return (count == 0); }
	Item front() const;
	size_type size() const { return count; }
private:
	Item data[CAPACITY];     // Circular array
	size_type first;         // Index of item at front of the queueArray
	size_type last;          // Index of item at rear of the queueArray
	size_type count;         // Total number of items in the queueArray
	// HELPER MEMBER FUNCTION
	size_type next_index(size_type i) const { return (i + 1) % CAPACITY; }
};

#include "queueArrayImplementation.h" // Include the implementation.
#endif
