// FILE: sequenceList.cpp
// CLASS implemented: sequenceList (see sequenceList.h for documentation)
// INVARIANT for the sequenceList ADT:
//   1. The items in the sequenceList are stored on a linked list,
//      in order from the start of the sequenceList at the head of the list;
//   2. The head pointer of the list is stored in the member variable head_ptr;
//   3. The tail pointer of the list is stored in the member variable tail_ptr;
//   4. If there is a current item, then the cursor points to the node that
//      contains this item; otherwise the cursor is nullptr.
//   5. If there is an item before the current item, then the precursor points
//      to the node that contains this item; otherwise the precursor is nullptr.
//   3. The total number of items in the list is stored in the member variable
//      many_nodes.

#include <cassert>  // Provides assert
#include <cstdlib>  // Provides rand, size_t
#include "node.h"  // Provides node and the linked list functions
#include "sequenceList.h"
using namespace std;

// utility function to create a new list from section of an existing list
// Precondition: start_ptr and end_ptr are pointers to nodes on the same
// linked list, with the start_ptr node at or before the end_ptr node.
// Postcondition: head_ptr and tail_ptr are the head and tail pointers
// for a new list that contains the items from start_ptr up to but
// not including end_ptr.  The end_ptr may also be nullptr, in which case
// the new list contains elements from start_ptr to the end of the list.
// Library facilities used: cstdlib
void list_piece(const node* start_ptr, const node* end_ptr, node*& head_ptr, 
	node*& tail_ptr) {

	head_ptr = nullptr;
	tail_ptr = nullptr;

	// Handle the case of the empty list.
	if (start_ptr == end_ptr)
		return;

	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, start_ptr->data());
	tail_ptr = head_ptr;

	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	start_ptr = start_ptr->link();
	while (start_ptr != end_ptr)
	{
		list_insert(tail_ptr, start_ptr->data());
		tail_ptr = tail_ptr->link();
		start_ptr = start_ptr->link();
	}
}

// default constructor
sequenceList::sequenceList() {
	head_ptr = tail_ptr = cursor = precursor = nullptr;
	many_nodes = 0;
}

// copy constructor ==>TO COMPLETE FOR LAB
sequenceList::sequenceList(const sequenceList& source) {
	if (this == &source)
		return;
	if (source.cursor == nullptr) {
		list_copy(source.head_ptr, head_ptr, tail_ptr);  // current item is at the end of the list
		cursor = nullptr;
		precursor = nullptr;
	}
	else if (source.many_nodes == 0) {
		head_ptr = tail_ptr = cursor = precursor = nullptr;
		many_nodes = 0;
	}
	else if (source.precursor == nullptr) {
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		cursor = head_ptr;
		precursor = nullptr;
	}
	else if (source.cursor->link() == nullptr) {
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		cursor = tail_ptr;
		precursor = nullptr;
	}
	else {
		list_copy(source.precursor, head_ptr, tail_ptr);
		cursor = head_ptr->link();
		precursor = head_ptr;

		size_type difNodes = source.many_nodes - list_length(head_ptr);
		while (difNodes > 0) {
			list_head_insert(head_ptr, (list_locate(source.head_ptr, difNodes))->data());
			difNodes--;
		}
	}
	many_nodes = source.many_nodes;
}

// the destructor
sequenceList::~sequenceList() {
	list_clear(head_ptr);
	many_nodes = 0;
}

// method to set cursor to beginning of list
void sequenceList::start() {
	precursor = nullptr;
	cursor = head_ptr;
}

// method to advance cursor
void sequenceList::advance() {
	assert(is_item());
	precursor = cursor;
	cursor = cursor->link();
	if (cursor == nullptr)
		precursor = nullptr;
}

// method to insert item before cursor
void sequenceList::insert(const value_type& entry) {
	if (precursor == nullptr)
	{   // The new entry goes at the front:
		list_head_insert(head_ptr, entry);
		cursor = head_ptr;
		if (tail_ptr == nullptr)
			tail_ptr = head_ptr; // There were no other nodes.
	}
	else
	{   // The new entry goes between precursor and cursor,
		// and the cursor is set to point at this new entry.
		list_insert(precursor, entry);
		cursor = precursor->link();
	}
	++many_nodes;
}


//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequenceList after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequenceList. In either case, the newly
//     inserted item is now the current item of the sequenceList.
// method to attach item after cursor ==>TO COMPLETE FOR LAB
void sequenceList::attach(const value_type& entry) {
	node *attach_ptr;
	if (!is_item())
		cursor = tail_ptr;
	if (cursor == nullptr) {
		list_head_insert(head_ptr, entry);
		cursor = tail_ptr = head_ptr;
	}
	else {
		attach_ptr = new node(entry, cursor->link());
		precursor = cursor;
		cursor->set_link(attach_ptr);
		cursor = attach_ptr;
		if (cursor->link() == nullptr)
			tail_ptr = cursor;
	}
	many_nodes++;
}

//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequenceList, and
//     the item after this (if there is one) is now the new current item.
// method to remove item at cursor ==>TO COMPLETE FOR LAB
void sequenceList::remove_current() {
	assert(is_item());
	if (cursor == nullptr)
		return;

	if (many_nodes == 1) {
		cursor = nullptr;
		head_ptr = nullptr;
		tail_ptr = nullptr;
		precursor = nullptr;
	}

	else if (cursor == tail_ptr) {
		cursor = nullptr;
		precursor->set_link(nullptr);
		tail_ptr = precursor;
	}
	else if (cursor == head_ptr){

		list_head_remove(head_ptr);

		if (many_nodes == 1)
			cursor = tail_ptr;
		else
			cursor = head_ptr;

	}
	else {
		list_remove(precursor);
		cursor = precursor->link();
	}

	many_nodes--;
}

// overloaded = assignment operator ==>TO COMPLETE FOR LAB
void sequenceList::operator =(const sequenceList& source) {
	if (this == &source)
		return;
	if (source.cursor == nullptr) {
		list_copy(source.head_ptr, head_ptr, tail_ptr);  // current item is at the end of the list
		cursor = nullptr;
		precursor = nullptr;
	}
	else if (source.many_nodes == 0) {
		head_ptr = tail_ptr = cursor = precursor = nullptr;
		many_nodes = 0;
	}
	else if (source.precursor == nullptr) {
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		cursor = head_ptr;
		precursor = nullptr;
	}
	else if (source.cursor->link() == nullptr) {
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		cursor = tail_ptr;
		precursor = nullptr;
	}
	else {
		list_copy(source.precursor, head_ptr, tail_ptr);
		cursor = head_ptr->link();
		precursor = head_ptr;

		size_type difNodes = source.many_nodes - list_length(head_ptr);
		while (difNodes > 0) {
			list_head_insert(head_ptr, (list_locate(source.head_ptr, difNodes))->data());
			difNodes--;
		}
	}
	many_nodes = source.many_nodes;
}

// method to return item at cursor
sequenceList::value_type sequenceList::current() const {
	assert(is_item());
	return cursor->data();
}


/*
==========>TEST RESULTS<==========
If you submit this sequenceList class now, you will have
30 points out of the 30 points from this test program.
==========>POINT SUMMARY<==========
Testing insert, attach, and the constant member functions
POINTS = 5 out of 5
Testing situations where the cursor goes off the sequenceList
POINTS = 5 out of 5
Testing remove_current
POINTS = 6 out of 6
Testing the copy constructor
POINTS = 5 out of 5
Testing the assignment operator
POINTS = 5 out of 5
Testing insert/attach for somewhat larger sequenceLists
POINTS = 4 out of 4
Press any key to continue . . .
*/