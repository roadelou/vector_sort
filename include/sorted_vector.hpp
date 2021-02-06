/********************************** METADATA **********************************/

/*
* Contributors: roadelou
* Contacts: 
* Creation Date: 2021-02-06
* Language: C++
*/

/************************************ BODY ************************************/

// Including the required headers.
#include <vector>

// A resizable array of integers sorted on insertion.
class SortedVector {
	private:
		// Inner vector used by composition.
		std::vector<int>* inner;
	public:
		// Constructor, takes no arguments.
		SortedVector(void);
		// Inserts the element into the array.
		void insert(int element);
		// Get the size of the array.
		size_t get_size(void);
		// Remove an element from the array if possible.
		void remove_or_skip(size_t index);
		// Returns a frozen copy of the content of the array.
		std::vector<int> get_frozen(void);
};

/************************************ EOF *************************************/
