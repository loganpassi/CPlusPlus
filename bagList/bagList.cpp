// FILE: bagList.cxx
// CLASS implemented: bagList (see bagList.h for documentation)
// INVARIANT for the bagList ADT:
//   1. The items in the bagList are stored on a linked list;
//   2. The head pointer of the list is stored in the member variable head_ptr;
//   3. The total number of items in the list is stored in the member variable
//      many_nodes.

#include <cassert>  // Provides assert
#include <cstdlib>  // Provides rand and size_t
#include "node.h"  // Provides node and the linked list functions
#include "bagList.h"
using namespace std;


// DEFAULT CONSTRUCTOR for the bagList class:
//   bagList( )
//     Postcondition: The bagList is empty.
bagList::bagList() {
	head_ptr = nullptr;
	many_nodes = 0;
}

// COPY CONSTRUCTOR for the bagList class:
//   bagList(const bagList& source)
//     Postcondition: The bagList contains copies 
//     of items from source.
bagList::bagList(const bagList& source) {
	// Library facilities used: node.h
	node *tail_ptr;  // Needed for argument of list_copy

	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
}

// DESTRUCTOR for the bagList class:
//  ~bagList()
//     Postcondition: Memory for bagList nodes
//     have been released and bagList is empty.
bagList::~bagList() {
	// Library facilities used: node.h
	list_clear(head_ptr);
	many_nodes = 0;
}

//   size_type count(const value_type& target) const
//     Postcondition: Return value is number of times target is in the bagList
//
bagList::size_type bagList::count(const value_type& target) const {
	// Library facilities used: cstdlib, node.h
	size_type answer = 0;

	//use list_search function to obtain cursor matching the target
	const node *cursor = list_search(head_ptr, target);
	//check to see if value found 
	while(cursor != nullptr) {
		answer++;
		//search through the sublist
	cursor = list_search(cursor->link(), target);
	}

	return answer;
}

//   size_type erase(const value_type& target);
//     Postcondition: All copies of target have been removed from the bagList.
//     The return value is the number of copies removed (which could be zero).
//
bagList::size_type bagList::erase(const value_type& target) {
	// Library facilities used: cstdlib, node.h
	size_type answer = 0;
	//cannot use const since we will remove target
	node *target_ptr = list_search(head_ptr, target);
	//continue down linked list
	while (target_ptr != nullptr) {
		//erase one node
		erase_one(target);
		answer++;
		target_ptr = list_search(target_ptr->link(), target);
	}

	return answer;
}

//   void erase_one(const value_type& target)
//     Postcondition: If target was in the bagList, then one copy has been removed;
//     otherwise the bagList is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
bool bagList::erase_one(const value_type& target) {
	// Library facilities used: cstdlib, node.h
	node *target_ptr;

	target_ptr = list_search(head_ptr, target);
	if (target_ptr == nullptr)
		return false; // target isn't in the bagList, so no work to do
	target_ptr->set_data(head_ptr->data());
	list_head_remove(head_ptr);
	--many_nodes;
	return true;
}

//   value_type grab() const
//     Precondition:  size() of bag is > 0
//     Postcondition: Return value is random item in bagList
//
bagList::value_type bagList::grab() const {
	// Library facilities used: cassert, cstdlib, node.h
	size_type i;
	const node *cursor; // Use const node* since we don't change the nodes.
	// ensure there are items in bag
	assert(size() > 0);
	// get random number between 1 and size of bag
	i = (rand() % size()) + 1;
	cursor = list_locate(head_ptr, i);
	return cursor->data();
}

//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted into the bagList.
//
void bagList::insert(const value_type& entry) {
	list_head_insert(head_ptr, entry);
	many_nodes++;
}

//   void operator +=(const bagList& addend) 
//     Postcondition: Each item in addend has been added to this bagList.
//
void bagList::operator +=(const bagList& addend) {
	node *copy_head_ptr;
	node *copy_tail_ptr;
	if (addend.many_nodes > 0) {
		//copy nodes over from the addend
		list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
		//attach current list
		copy_tail_ptr->set_link(head_ptr);
		//reset head pointer of current list
		head_ptr = copy_head_ptr;
		//increment the number of nodes
		many_nodes += addend.many_nodes;
	}
}

//   void operator =(const bagList& source) 
//     Postcondition: Each item in source has been copied to this bagList.
//
void bagList::operator =(const bagList& source) {
	//check for possible self-assignment
	if (this == &source)
		return;
	//clear the old list
	list_clear(head_ptr);
	node *tail_ptr; //needed for list copy function
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
}

//   bagList operator +(const bagList& b1, const bagList& b2)
//   Postcondition: The bagList returned is the union of b1 and b2.
//
bagList operator +(const bagList& b1, const bagList& b2) {
	bagList answer;
	answer += b1;
	answer += b2;
	return answer;
}
