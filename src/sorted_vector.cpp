/********************************** METADATA **********************************/

/*
* Contributors: roadelou
* Contacts: 
* Creation Date: 2021-02-06
* Language: Text File
*/

/************************************ BODY ************************************/

// Including the header definition of the class we are implementing.
#include "sorted_vector.hpp"

// Used to iterate through std::vector.
#include <iterator>

// Constructor implementation.
SortedVector::SortedVector(void) {
	// Creating inner vector.
	this->inner = new std::vector<int>();
}

void SortedVector::insert(int element) {
	// The iterator used to insert our element.
	std::vector<int>::iterator inner_iterator = this->inner->begin();

	// Increasing the index until we find the right position.
	while (inner_iterator != this->inner->end() and *inner_iterator < element) {
		// Moving the index...
		inner_iterator = std::next(inner_iterator);
	}

	// Inserting at the appropriate index.
	this->inner->insert(inner_iterator, element);
}


size_t SortedVector::get_size(void) {
	// Calling the appropriate std::vector function.
	return this->inner->size();
}


void SortedVector::remove_or_skip(size_t index) {
	// Testing if index is within the right range.
	if (index < this->inner->size()) {
		// Getting the iterator to the beginning of the vector.
		std::vector<int>::iterator inner_iterator = this->inner->begin();
		// Moving the iterator to the required index.
		std::advance(inner_iterator, index);
		// Erasing the element under the index.
		this->inner->erase(inner_iterator);
	}
	// Else we skip.
}


std::vector<int> SortedVector::get_frozen(void) {
	// Creating a vew vector as a copy of the inner one.
	std::vector<int> new_vector(*this->inner);
	// Returning the vector copy.
	return new_vector;
}

/************************************ EOF *************************************/
