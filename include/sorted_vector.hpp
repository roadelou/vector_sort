/********************************** METADATA **********************************/

/*
* Contributors: roadelou
* Contacts: 
* Creation Date: 2021-02-06
* Language: C++
*/

/************************************ BODY ************************************/

// Header Guard
#ifndef SORTED_VECTOR_INCLUDED
#define SORTED_VECTOR_INCLUDED

// Including the required headers.
#include <vector>

// A resizable array of integers sorted on insertion.
template <typename Sortable> class SortedVector {
	private:
		// Inner vector used by composition.
		std::vector<Sortable>* inner;
	public:
		// Constructor, takes no arguments.
		SortedVector(void);
		// Inserts the element into the array.
		void insert(Sortable element);
		// Get the size of the array.
		size_t get_size(void);
		// Remove an element from the array if possible.
		void remove_or_skip(size_t index);
		// Returns a frozen copy of the content of the array.
		std::vector<Sortable> get_frozen(void);
};

// Including the implementation of SortedVector in the header because this is a
// templated class.
#include "sorted_vector_implementation.hpp"

// End of header guard
#endif

/************************************ EOF *************************************/
