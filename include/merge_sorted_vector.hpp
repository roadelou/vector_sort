/********************************** METADATA **********************************/

/*
* Contributors: roadelou
* Contacts: 
* Creation Date: 2021-02-06
* Language: Text File
*/

/************************************ BODY ************************************/

// Header Guard
#ifndef MERGE_SORTED_VECTOR_INCLUDED
#define MERGE_SORTED_VECTOR_INCLUDED

// Used for inheritance.
#include "sorted_vector.hpp"

// MergeSortedVector has the exact same API as SortedVector.
template <typename Sortable> class MergeSortedVector: SortedVector<Sortable> {
	private:
		// Inner vector used by composition.
		std::vector<Sortable>* inner;
	public:
		// Constructor, takes no arguments.
		MergeSortedVector(void);
		// Inserts the element into the array.
		void insert(Sortable element);
		// Get the size of the array.
		size_t get_size(void);
		// Returns a frozen copy of the content of the array.
		std::vector<Sortable> get_frozen(void);
};

// Include implementation of the MergeSortedVector class.
#include "merge_sorted_vector_implementation.hpp"

// End of header guard
#endif

/************************************ EOF *************************************/
