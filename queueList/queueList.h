// FILE: queueList.h (part of the namespace
// TEMPLATE CLASS PROVIDED: queueList<Item> (a queueList of items)
//
// TEMPLATE PARAMETER, ALIASES and MEMBER CONSTANTS for the stack<Item> class:
//   The template parameter, Item, is the data type of the items in the queueList,
//   also defined as queueList<Item>::value_type. It may be any of the C++ built-in
//   types (int, char, etc.), or a class with a default constructor, a copy
//   constructor, and an assignment operator. The definition
//   queueList<Item>::size_type is the data type of any variable that keeps track of
//   how many items are in a queueList.
// NOTE:
//   Many compilers require the use of the new keyword typename before using
//   the expressions queueList<Item>::value_type and queueList<Item>::size_type.
//   Otherwise the compiler doesn't have enough information to realize that it
//   is the name of a data type.
//
// CONSTRUCTOR for the queueList<Item> template class:
//   queueList( )
//     Postcondition: The queueList has been initialized as an empty queueList.
//
// MODIFICATION MEMBER FUNCTIONS for the queueList<Item> template class:
//   void pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The front item of the queueList has been removed.
//
//   void push(const Item& entry)
//     Postcondition: A new copy of entry has been inserted at the rear of the
//     queueList.
//
// CONSTANT MEMBER FUNCTIONS for the queueList<Item> template class:
//   bool empty( ) const
//     Postcondition: The return value is true if the queueList is empty.
//
//   Item front( ) const
//     Precondition: size( ) > 0
//     Postcondition: The return value is a copy of the item at
//     the front of the queueList (and the queueList is unaltered).
//
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the queueList.
//
// VALUE SEMANTICS for the queueList<Item> template class:
//   Assignments and the copy constructor may be used with queueList<Item> objects.

#ifndef MAIN_SAVITCH_queueList_H     // Prevent duplicate definition
#define MAIN_SAVITCH_queueList_H
#include <cstdlib>   // Provides std::size_t
#include "nodeTemplate.h"   // Node template class

template <class Item>
class queueList
{
public:
	// ALIASES
	using size_type = std::size_t;
	using value_type = Item;
	// CONSTRUCTORS and DESTRUCTOR
	queueList();
	queueList(const queueList<Item>& source);
	~queueList();
	// MODIFICATION MEMBER FUNCTIONS
	void pop();
	void push(const Item& entry);
	void operator =(const queueList<Item>& source);
	// CONSTANT MEMBER FUNCTIONS
	bool empty() const { return (count == 0); }
	Item front() const;
	size_type size() const { return count; }
private:
	nodeTemplate<Item> *front_ptr;
	nodeTemplate<Item> *rear_ptr;
	size_type count;       // Total number of items in the queueList
};

#include "queueListImplementation.h" // Include the implementation

#endif
