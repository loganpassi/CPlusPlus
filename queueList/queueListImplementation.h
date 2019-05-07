// FILE: queueListImplementation.h
// TEMPLATE CLASS IMPLEMENTED: queueList<Item> (see queueList.h for documentation)
// This file is included in the header file, and not compiled separately.
// INVARIANT for the queueList class:
//   1. The number of items in the queueList is stored in the member variable
//      count.
//   2. The items in the queueList are stored in a linked list, with the front of
//      the queueList stored at the head node, and the rear of the queueList stored at
//      the final node.
//   3. The member variable front_ptr is the head pointer of the linked list of
//      items. For a non-empty queueList, the member variable rear_ptr is the
//      tail pointer of the linked list; for an empty list, we don't care
//      what's stored in rear_ptr.

#include <cassert>   // Provides assert
#include "nodeTemplate.h"   // Node template class

template <class Item>
queueList<Item>::queueList()
{
	count = 0;
	front_ptr = nullptr;
}

template <class Item>
queueList<Item>::queueList(const queueList<Item>& source)
// Library facilities used: nodeTemplate
{
	count = source.count;
	list_copy(source.front_ptr, front_ptr, rear_ptr);
}

template <class Item>
queueList<Item>::~queueList()
{
	list_clear(front_ptr);
}

template <class Item>
void queueList<Item>::operator =(const queueList<Item>& source)
// Library facilities used: nodeTemplate
{
	if (this == &source) // Handle self-assignment
		return;
	list_clear(front_ptr);
	list_copy(source.front_ptr, front_ptr, rear_ptr);
	count = source.count;
}

template <class Item>
Item queueList<Item>::front() const
// Library facilities used: cassert
{
	assert(!empty());
	return front_ptr->data();
}

template <class Item>
void queueList<Item>::pop()
// Library facilities used: cassert, nodeTemplate
{
	assert(!empty());
	list_head_remove(front_ptr);
	--count;
}

template <class Item>
void queueList<Item>::push(const Item& entry)
// Library facilities used: nodeTemplate
{
	if (empty())
	{   // Insert first entry.
		list_head_insert(front_ptr, entry);
		rear_ptr = front_ptr;
	}
	else
	{   // Insert an entry that is not the first.
		list_insert(rear_ptr, entry);
		rear_ptr = rear_ptr->link();
	}
	++count;
}