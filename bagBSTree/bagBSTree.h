// FILE: bagBSTree.h 
// TEMPLATE CLASS PROVIDED: bagBSTree<Item>
//     (a container template class for a collection of items)
//
// ALIASES for the bagBSTree<Item> class:
//   bagBSTree<Item>::value_type
//     bagBSTree<Item>::value_type is the data type of the items in the bagBSTree. It may
//     be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, a copy constructor, an assignment operator, and a
//     less-than operator forming a strict weak ordering.
//
//   bagBSTree<Item>::size_type
//     bagBSTree<Item>::size_type is the data type of any variable that keeps track
//     of how many items are in a bagBSTree.
//
// CONSTRUCTOR for the bagBSTree<Item> class:
//   bagBSTree( )
//     Postcondition: The bagBSTree is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the bagBSTree<Item> class:
//   void insert(const Item& entry)
//     Postcondition: A new copy of entry has been inserted into the bagBSTree.
//
//   void operator +=(const bagBSTree& addend)
//     Postcondition: Each item in addend has been added to this bagBSTree.
//
// CONSTANT MEMBER FUNCTIONS for the bagBSTree<Item> class:
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the bagBSTree.
//
//   size_type count(const Item& target) const
//     Postcondition: Return value is number of times target is in the bagBSTree.
//
// NONMEMBER FUNCTIONS for the bagBSTree class:
//   bagBSTree operator +(const bagBSTree& b1, const bagBSTree& b2)
//     Postcondition: The bagBSTree returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the bagBSTree class:
//   Assignments and the copy constructor may be used with bagBSTree objects.
//
// DYNAMIC MEMORY USAGE by the bagBSTree: 
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc: The constructors, insert, operator +=, operator +, and
//   the assignment operator.

#ifndef BAG_BST_H 
#define BAG_BST_H
#include <cstdlib>     // Provides NULL and size_t
#include "bintree.h"   // Provides binary_tree_node and related functions

template <class Item>
class bagBSTree
{
public:
	// ALIASES
	using size_type = std::size_t;
	using value_type = Item;
	// CONSTRUCTORS and DESTRUCTOR
	bagBSTree();
	bagBSTree(const bagBSTree& source);
	~bagBSTree();
	// MODIFICATION functions
	void insert(const Item& entry);
	void operator +=(const bagBSTree& addend);
	void operator =(const bagBSTree& source);
	// CONSTANT functions
	size_type size() const;
	size_type count(const Item& target) const;
	//DISPLAY functions
	void displayBSTree(const size_type);
	void inOrderDisplay();
private:
	binary_tree_node<Item> *root_ptr; // Root pointer of binary search tree
	void insert_all(binary_tree_node<Item>* addroot_ptr);
};

// NONMEMBER functions for the bagBSTree<Item> template class
template <class Item>
bagBSTree<Item> operator +(const bagBSTree<Item>& b1, const bagBSTree<Item>& b2);

#include "bagBSTree_template.h" // Include the implementation.
#endif
