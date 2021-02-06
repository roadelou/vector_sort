/********************************** METADATA **********************************/

/*
* Contributors: roadelou
* Contacts: 
* Creation Date: 2021-02-06
* Language: Text File
*/

/************************************ BODY ************************************/

// Header Guard
#ifndef SORTED_VECTOR_IMPLEMENTATION_INCLUDED
#define SORTED_VECTOR_IMPLEMENTATION_INCLUDED

// The interface header is including us, hence we don't include it here to avoid
// a circular dependancy.
// #include "sorted_vector.hpp"
// NOTE
// ====
// The reason why we moved the implementation of SortedVector to a header is
// that "The implementation of a non-specialized template must be visible to a"
// "translation unit that uses it."
// 
// (source: https://stackoverflow.com/a/10632266)
//
// tl;dr: Templated class have to be implemented in header (their generic
// components at least).

// NOTE
// ----
// <vector> is included in the interface header, which in turns includes us.
// Because text based macros are a terrible system, this means we don't need to
// include it here. However, since that would be very disturbing, I am still
// including it here.
#include <vector>

// Used to iterate through std::vector.
#include <iterator>

// Constructor implementation.
template <typename Sortable> SortedVector<Sortable>::SortedVector(void) {
	// Creating inner vector.
	this->inner = new std::vector<Sortable>();
}


template <typename Sortable> void SortedVector<Sortable>::insert(Sortable element) {
	// The iterator used to insert our element.
	typename std::vector<Sortable>::iterator inner_iterator = this->inner->begin();

	// Increasing the index until we find the right position.
	while (inner_iterator != this->inner->end() and *inner_iterator < element) {
		// Moving the index...
		inner_iterator = std::next(inner_iterator);
	}

	// Inserting at the appropriate index.
	this->inner->insert(inner_iterator, element);
}


template <typename Sortable> size_t SortedVector<Sortable>::get_size(void) {
	// Calling the appropriate std::vector function.
	return this->inner->size();
}


template <typename Sortable> std::vector<Sortable> SortedVector<Sortable>::get_frozen(void) {
	// Creating a vew vector as a copy of the inner one.
	std::vector<Sortable> new_vector(*this->inner);
	// Returning the vector copy.
	return new_vector;
}

// End of header guard
#endif

/************************************ EOF *************************************/
