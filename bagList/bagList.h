// FILE: bagList.h 
// CLASS PROVIDED: bagList
//
// ALIASES for the bagList class:
//   bagList::value_type
//     is the data type of the items in the bagList. It may be any 
//     of the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, a copy constructor, an assignment
//     operator, and a test for equality (x == y).
//
//   bagList::size_type
//     is the data type of any variable that keeps track of how many items are
//     in a bagList
//
// CONSTRUCTOR for the bagList class:
//   bagList( )
//     Postcondition: The bagList is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the bagList class:
//   size_type erase(const value_type& target)
//     Postcondition: All copies of target have been removed from the bagList.
//     The return value is the number of copies removed (which could be zero).
//
//   bool erase_one(const value_type& target)
//     Postcondition: If target was in the bagList, then one copy of target has
//     been removed from the bagList; otherwise the bagList is unchanged. A true
//     return value indicates that one copy was removed; false indicates that
//     nothing was removed.
//
//   void insert(const value_type& entry) 
//     Postcondition: A new copy of entry has been inserted into the bagList.
//
//   void operator +=(const bagList& addend) 
//     Postcondition: Each item in addend has been added to this bagList.
//
// CONSTANT MEMBER FUNCTIONS for the bagList class:
//   size_type size( ) const 
//     Postcondition: Return value is the total number of items in the bagList.
//
//   size_type count(const value_type& target) const 
//     Postcondition: Return value is number of times target is in the bagList.
//
//   value_type grab( ) const 
//     Precondition: size( ) > 0.
//     Postcondition: The return value is a randomly selected item from the bagList.
// 
// NONMEMBER FUNCTIONS for the bagList class:
//   bagList operator +(const bagList& b1, const bagList& b2) 
//     Postcondition: The bagList returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the bagList class:
//    Assignments and the copy constructor may be used with bagList objects.
//
// DYNAMIC MEMORY USAGE by the bagList: 
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: The constructors, insert, operator +=, operator +, and the
//   assignment operator.

#ifndef MAIN_SAVITCH_bagList_H
#define MAIN_SAVITCH_bagList_H
#include <cstdlib>   // Provides size_t
#include "node.h"   // Provides node class

class bagList
{
public:
	// ALIASES
	using size_type = std::size_t;
	using value_type = node::value_type;
	// CONSTRUCTORS and DESTRUCTOR
	bagList();
	bagList(const bagList& source);
	~bagList();
	// MODIFICATION MEMBER FUNCTIONS
	size_type erase(const value_type& target);
	bool erase_one(const value_type& target);
	void insert(const value_type& entry);
	void operator +=(const bagList& addend);
	void operator =(const bagList& source);
	// CONSTANT MEMBER FUNCTIONS
	size_type size() const { return many_nodes; }
	size_type count(const value_type& target) const;
	value_type grab() const;
private:
	node *head_ptr;       // List head pointer 
	size_type many_nodes; // Number of nodes on the list
};

// NONMEMBER FUNCTIONS for the bagList class:    
bagList operator +(const bagList& b1, const bagList& b2);
#endif

