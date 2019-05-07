// FILE: bagBSTree_template.h
// -------------------------------------------------------------------------
// TEMPLATE CLASS IMPLEMENTED: bagBSTree<Item> (see bagBSTree.h for documentation)
// INVARIANT of the ADT:
//   root_ptr is the root pointer of a binary search tree that contains the
//   bag's items.

#include <cassert>
#include <cstdlib>

template <class Item>
bagBSTree<Item>::bagBSTree()
// default constructor sets root pointer to nullptr
{
	root_ptr = nullptr;
}

template <class Item>
bagBSTree<Item>::bagBSTree(const bagBSTree<Item>& source)
// Library facilities used: bintree.h
{
	root_ptr = tree_copy(source.root_ptr);
}

template <class Item>
bagBSTree<Item>::~bagBSTree()
// Header file used: bintree.h
{
	tree_clear(root_ptr);
}

template <class Item>
typename bagBSTree<Item>::size_type bagBSTree<Item>::size() const
// Header file used: bintree.h
{
	return tree_size(root_ptr);
}

template <class Item>
void bagBSTree<Item>::insert(const Item& entry)
// Header file used: bintree.h
{
	binary_tree_node<Item> *cursor = root_ptr;
	bool done = false;

	if (root_ptr == nullptr)
	{
		root_ptr = new binary_tree_node<Item>(entry);
		return;
	}

	do
	{
		if (cursor->data() >= entry)
		{   // Go left
			if (cursor->left() == nullptr)
			{
				cursor->set_left(new binary_tree_node<Item>(entry));
				done = true;
			}
			else
				cursor = cursor->left();
		}
		else
		{   // Go right
			if (cursor->right() == nullptr)
			{
				cursor->set_right(new binary_tree_node<Item>(entry));
				done = true;
			}
			else
				cursor = cursor->right();
		}
	} while (!done);
}

template <class Item>
typename bagBSTree<Item>::size_type bagBSTree<Item>::count(const Item& target) const
{
	size_type answer = 0;
	binary_tree_node<Item> *cursor = root_ptr;

	while (cursor != nullptr)
	{
		if (cursor->data() < target)
			cursor = cursor->right();
		else
		{
			if (cursor->data() == target) answer++;
			cursor = cursor->left();
		}
	}
	return answer;
}

template <class Item>
void bagBSTree<Item>::operator =(const bagBSTree<Item>& source)
// Header file used: bintree.h
{
	if (root_ptr == source.root_ptr)
		return;
	tree_clear(root_ptr);
	root_ptr = tree_copy(source.root_ptr);
}

template <class Item>
void bagBSTree<Item>::operator +=(const bagBSTree<Item>& addend)
{
	if (root_ptr == addend.root_ptr)
	{
		bagBSTree<Item> copy = addend;
		insert_all(copy.root_ptr);
	}
	else
		insert_all(addend.root_ptr);
}

template <class Item>
bagBSTree<Item> operator +(const bagBSTree<Item>& b1, const bagBSTree<Item>& b2)
{
	bagBSTree<Item> answer = b1;
	answer += b2;
	return answer;
}

// private helper function for +=
template <class Item>
void bagBSTree<Item>::insert_all(binary_tree_node<Item>* addroot_ptr)
// Precondition: addroot_ptr is the root pointer of a binary search tree that
// is separate for the binary search tree of the bag that activated this
// method.
// Postcondition: All the items from the addroot_ptr's binary search tree
// have been added to the binary search tree of the bag that activated this
// method.
{
	if (addroot_ptr != nullptr)
	{
		insert(addroot_ptr->data());
		insert_all(addroot_ptr->left());
		insert_all(addroot_ptr->right());
	}
}

//***LAP*** added methods to display tree
template<class Item>
void bagBSTree<Item>::displayBSTree(const size_type depth) {
	pretty_print(root_ptr, depth);
}

//function to use when 'visiting' nodes
void display_int(int& i) {
	std::cout << i << ' ';
}

//method to invoke toolkit function to
//preform inorder BST traversal
template<class Item>
void bagBSTree<Item>::inOrderDisplay() {
	inorder(display_int, root_ptr);
}