//Logan Passi
//CIS2542
//09/25/2017
//nodeSample.cpp
//Descr:
//In class exercise to demonstrate use of the node class in creating and manipulating a linked list.

#include <iostream>
#include "node.h"
using namespace std;

int main() {
	//create some nodes; start at end and link at front
	node *third = new node(22.0);
	node *second = new node(11.0, third);
	node *first = new node(33.0, second);

	//create node to insert between first and second node
	node *nodeToInsert = new node(44.0);
	//update pointers
	first->set_link(nodeToInsert);
	nodeToInsert->set_link(second);

	//remove second node from list
	nodeToInsert->set_link(second->link());
	

	//display all itemsin linked list
	cout << "****sample to linked list****" << endl;
	for (node *n = first; n != nullptr; n = n->link())
		cout << n->data() << " ";
	cout << "nullptr" << endl;

	//create singly linked list
	node *head_ptr = first;
	node *tail_ptr = third;
	cout << "Length of singly linked list is " << list_length(head_ptr) << endl;

	//search for item in list
	node::value_type valueToFind;
	cout << "Please input a value to search: ";
	cin >> valueToFind;
	node *nodeFound = list_search(head_ptr, valueToFind);
	if (nodeFound)
		cout << nodeFound->data() << " found in list!" << endl;
	else
		cout << valueToFind << " NOT FOUND IN LIST!" << endl;

	//locate an item by position in list
	size_t indexToFind;
	cout << "Please input an index to locate: ";
	cin >> indexToFind;
	node *indexFound = list_locate(head_ptr, indexToFind);
	if (indexFound)
		cout << indexFound->data() << " is at location " << indexToFind << endl;
	else
		cout << indexToFind << " not in list." << endl;

	//create a copy of the singly linked list
	node *copy_head_ptr = nullptr, *copy_tail_ptr = nullptr;
	list_copy(head_ptr, copy_head_ptr, copy_tail_ptr);

	//release memory
	list_clear(head_ptr); //releases all memory used by the linked  list
	list_clear(copy_head_ptr); //release copied link list
	/*delete first;
	delete second;
	delete third;
	delete nodeToInsert;*/
	return EXIT_SUCCESS;
}