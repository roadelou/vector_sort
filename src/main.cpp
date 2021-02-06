/********************************** METADATA **********************************/

/*
* Contributors: roadelou
* Contacts: 
* Creation Date: 2021-02-06
* Language: Text File
*/

/************************************ BODY ************************************/

// Used for std::stoi.
#include <string>

// Used to print the result of the sort.
#include <iostream>

// The class we implemented.
#include "sorted_vector.hpp"

int main(int argc, char **argv) {
	// Creating the SortedVector.
	SortedVector sort_factory = SortedVector();

	// Iterate over the command line arguments and add them to the
	// SortedVector. We skip the first argument which is the name of the
	// program itself.
	for (int i = 1; i < argc; i++) {
		int value_to_insert = std::stoi(argv[i]);
		// Inserting the value into the SortedVector.
		sort_factory.insert(value_to_insert);
	}

	// Get the vector of sorted integers back.
	std::vector<int> sort_result = sort_factory.get_frozen();

	// Iterating over the result to print it.
	for (int element: sort_result) {	// C++11
		// Printing the element and a space.
		std::cout << element << ' ';
	}
	// Printing final newline.
	std::cout << std::endl;

	return EXIT_SUCCESS;
}

/************************************ EOF *************************************/
