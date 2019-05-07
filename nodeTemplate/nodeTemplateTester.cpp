//Logan Passi
//10/02/2017
// nodeTemplateTester.cpp
//In Class exercise to demonstrate use of nodeTemplate class
//and toolkit functions
#include "nodeTemplate.h"
#include <iostream>;
#include <string>;
using namespace std;

//toolkit function to display item
template <class Item>
void display_list(const nodeTemplate<Item>* head_ptr) {
	const nodeTemplate<Item> *cursor;

	for (cursor = head_ptr; cursor != nullptr; cursor = cursor->link())
		cout << cursor->data() << " ";
	cout << endl;
	return;
}


int main() {
	//create some nodes for integer linked list
	nodeTemplate<int> *int_head = new nodeTemplate<int>(22);
	list_head_insert(int_head, 33);
	list_head_insert(int_head, 44);
	cout << "There are " << list_length(int_head) << " items in the list.\n";
	display_list(int_head);

	//create some nodes for integer linked list
	nodeTemplate<string> *string_head = new nodeTemplate<string>("end");
	list_head_insert(string_head, static_cast<string>("the"));
	list_head_insert(string_head, static_cast<string>("loli"));
	cout << "There are " << list_length(string_head) << " items in the list.\n";
	display_list(string_head);
	return EXIT_SUCCESS;
}