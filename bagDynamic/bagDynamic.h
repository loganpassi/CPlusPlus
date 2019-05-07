// FILE: bagDynamic.h
// CLASS PROVIDED: bagDynamic (a container class for a collection of items)
//
// ALIASES and MEMBER CONSTANTS for the bagDynamic class:
//   alias _____ value_type
//     bagDynamic::value_type is the data type of the items in the bagDynamic. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
//   alias _____ size_type
//     bagDynamic::size_type is the data type of any variable that keeps track of how
//     many items are in a bagDynamic.
//
//   static const size_type DEFAULT_CAPACITY = _____
//     bagDynamic::DEFAULT_CAPACITY is the initial capacity of a bagDynamic that is created
//     by the default constructor.
//
// CONSTRUCTORS for the bagDynamic class:
//   bagDynamic(size_type initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The bagDynamic is empty with an initial capacity given by the
//     parameter. The insert function will work efficiently (without
//     allocating new memory) until this capacity is reached.
//
//   bagDynamic(const bagDynamic& source)
//     Postcondition: The bagDynamic has capacity set to the bagDynamic source parameter.
//     The bagDynamic object is filled with data members given by the bagDynamic source
//     parameter.
//
// DESTRUCTOR for the bagDynamic class:
//   ~bagDynamic()
//     Postcondition: dynamically allocated memory for data member has been released
//
// MODIFICATION MEMBER FUNCTIONS for the bagDynamic class:
//   void reserve(size_type new_capacity)
//     Postcondition: The bagDynamic's current capacity is changed to the
//     new_capacity (but not less than the number of items already in the
//     bagDynamic). The insert function will work efficiently (without allocating
//     new memory) until the new capacity is reached.
//
//   size_type erase(const value_type& target);
//     Postcondition: All copies of target have been removed from the bagDynamic.
//     The return value is the number of copies removed (which could be zero).
//
//   void erase_one(const value_type& target)
//     Postcondition: If target was in the bagDynamic, then one copy has been removed;
//     otherwise the bagDynamic is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted into the bagDynamic.
//
//   void operator +=(const bagDynamic& addend) 
//     Postcondition: Each item in addend has been added to this bagDynamic.
//
//   void operator =(const bagDynamic& source) 
//     Postcondition: Each item in source has been copied to this bagDynamic.
//
// CONSTANT MEMBER FUNCTIONS for the bagDynamic class:
//   size_type size( ) const 
//     Postcondition: Return value is the total number of items in the bagDynamic.
//
//   size_type count(const value_type& target) const
//     Postcondition: Return value is number of times target is in the bagDynamic
//
// NONMEMBER FUNCTIONS for the bagDynamic class:
//   bagDynamic operator +(const bagDynamic& b1, const bagDynamic& b2)
//   Postcondition: The bagDynamic returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the bagDynamic class:
//   Assignments and the copy constructor may be used with bagDynamic objects.
//
// DYNAMIC MEMORY USAGE by the bagDynamic:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: The constructors, reserve, insert, operator += ,
//   operator +, and the assignment operator.

#ifndef MAIN_SAVITCH_bagDynamic_H
#define MAIN_SAVITCH_bagDynamic_H
#include <cstdlib>  // Provides size_t

class bagDynamic
{
public:
	// aliases and MEMBER CONSTANTS
	using value_type = int;
	using size_type = std::size_t;
    static const size_type DEFAULT_CAPACITY = 30;        
    // CONSTRUCTORS and DESTRUCTOR
    bagDynamic(size_type initial_capacity = DEFAULT_CAPACITY);
	// override default copy constructor
	bagDynamic(const bagDynamic&);
    ~bagDynamic( );
    // MODIFICATION MEMBER FUNCTIONS
    void reserve(size_type new_capacity);
    bool erase_one(const value_type& target);
	size_type erase(const value_type& target);
    void insert(const value_type& entry);
    void operator +=(const bagDynamic& addend);
	void operator =(const bagDynamic&); // overrride default assignment
    // CONSTANT MEMBER FUNCTIONS
    size_type size( ) const { return used; }
    size_type count(const value_type& target) const;
private:
    value_type *data;     // Pointer to partially filled dynamic array
    size_type used;       // How much of array is being used
    size_type capacity;   // Current capacity of the bagDynamic
};

// NONMEMBER FUNCTIONS for the bagDynamic class
bagDynamic operator +(const bagDynamic& b1, const bagDynamic& b2);

#endif
