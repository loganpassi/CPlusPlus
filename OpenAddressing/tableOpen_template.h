// FILE: tableOpen_template.h
// TEMPLATE CLASS IMPLEMENTED: tableOpen (see tableOpen.h for documentation)
// INVARIANT for the table ADT:
//   1. The number of records in the table is in the member variable used.
//   2. The actual records of the table are stored in the array data, with
//      a maximum of CAPACITY entries. Each used spot in the array has a 
//      non-negative key. Any unused record in the array has a key field of
//      NEVER_USED (if it has never been used) or PREVIOUSLY_USED (if it once
//      was used, but is  now vacant).

#include <cassert>  // Provides assert
#include <cstdlib>  // Provides size_t


template <class RecordType>
const std::size_t tableOpen<RecordType>::CAPACITY;

template <class RecordType>
const int tableOpen<RecordType>::NEVER_USED;

template <class RecordType>
const int tableOpen<RecordType>::PREVIOUSLY_USED;

template <class RecordType>
tableOpen<RecordType>::tableOpen()
{
	std::size_t i;

	used = 0;
	for (i = 0; i < CAPACITY; ++i)
		data[i].key = NEVER_USED;  // Indicates a spot that's never been used.
}

template <class RecordType>
void tableOpen<RecordType>::insert(const RecordType& entry)
// Library facilities used: cassert
{
	bool already_present;   // True if entry.key is already in the table
	std::size_t index;        // data[index] is location for the new entry

	assert(entry.key >= 0);

	// Set index so that data[index] is the spot to place the new entry.
	find_index(entry.key, already_present, index);

	// If the key wasn't already there, then find the location for the new entry.
	if (!already_present)
	{
		assert(size() < CAPACITY);
		index = hash(entry.key);
		while (!is_vacant(index))
			index = next_index(index);
		++used;
	}

	data[index] = entry;
}

template <class RecordType>
void tableOpen<RecordType>::remove(int key)
// Library facilities used: cassert
{
	bool found;        // True if key occurs somewhere in the table
	std::size_t index;   // Spot where data[index].key == key

	assert(key >= 0);

	find_index(key, found, index);
	if (found)
	{   // The key was found, so remove this record and reduce used by 1.
		data[index].key = PREVIOUSLY_USED; // Indicates a spot that's no longer in use.
		--used;
	}
}

template <class RecordType>
bool tableOpen<RecordType>::is_present(int key) const
// Library facilities used: assert.h
{
	bool found;
	std::size_t index;

	assert(key >= 0);

	find_index(key, found, index);
	return found;
}

template <class RecordType>
void tableOpen<RecordType>::find(int key, bool& found, RecordType& result) const
// Library facilities used: cassert.h
{
	std::size_t index;

	assert(key >= 0);

	find_index(key, found, index);
	if (found)
		result = data[index];
}

template <class RecordType>
inline std::size_t tableOpen<RecordType>::hash(int key) const
{
	return (key % CAPACITY);
}

template <class RecordType>
inline std::size_t tableOpen<RecordType>::next_index(std::size_t index) const
// Library facilities used: cstdlib
{
	return ((index + 1) % CAPACITY);
}

template <class RecordType>
void tableOpen<RecordType>::find_index(int key, bool& found, std::size_t& i) const
// Library facilities used: cstdlib
{
	std::size_t count; // Number of entries that have been examined

	count = 0;
	i = hash(key);
	while ((count < CAPACITY) && (data[i].key != NEVER_USED) && (data[i].key != key))
	{
		++count;
		i = next_index(i);
	}
	found = (data[i].key == key);
}

template <class RecordType>
inline bool tableOpen<RecordType>::never_used(std::size_t index) const
{
	return (data[index].key == NEVER_USED);
}

template <class RecordType>
inline bool tableOpen<RecordType>::is_vacant(std::size_t index) const
{
	return (data[index].key == NEVER_USED) || (data[index].key == PREVIOUSLY_USED);
}
