#pragma once
//Logan Passi
//Date: 09/11/2017
//File: bagFixed.h
//Descr:
//Header file for the bagFixed container class.

#include <cstdlib> //includes the std::size_t
class bagFixed {
public:
	//create alias reference to existing data type
	using value_type = int;
	//create alias reference to size
	using size_type = std::size_t;
	//static member for maximum size
	static const size_type CAPACITY = 30;
	//creat a default constructor to initialize the emply bagFixed
	bagFixed() { used = 0; }
	//member function to return size
	size_type size() const { return used; }
	// member function to insert and item
	void insert(const value_type& entry);
	//member function to count the number of items
	size_type count(const value_type& entry);
	//member function to remove an item if it exists in the bagFixed 
	bool erase_one(const value_type& entry);
	//overload += to add one bagFixed to another
	void operator +=(const bagFixed& rhs);
private:
	value_type data[CAPACITY]; //stored data memebers
	size_type used; //number of data items stored
	
};

//nonmember function to add the bagFixed objects
bagFixed operator + (const bagFixed& lhs, const bagFixed& rhs);