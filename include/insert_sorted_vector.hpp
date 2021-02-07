/********************************** METADATA **********************************/

/*
 * Contributors: roadelou
 * Contacts:
 * Creation Date: 2021-02-06
 * Language: C++
 */

/************************************ BODY ************************************/

// Header Guard
#ifndef INSERT_SORTED_VECTOR_INCLUDED
#define INSERT_SORTED_VECTOR_INCLUDED

// Including the base class.
#include "sorted_vector.hpp"

// Including the required headers.
#include <vector>

// A resizable array of integers sorted on insertion.
template <typename Sortable>
class InsertSortedVector : public SortedVector<Sortable> {
  public:
    // Constructor, takes no arguments.
    InsertSortedVector(void);
    // Inserts the element into the array.
    void insert(Sortable element) override;
    // Get the size of the array.
    size_t get_size(void) override;
    // Returns a frozen copy of the content of the array.
    std::vector<Sortable> get_frozen(void) override;
    // Using default destructor.
    ~InsertSortedVector() {}
};

// Including the implementation of SortedVector in the header because this is a
// templated class.
#include "insert_sorted_vector_implementation.hpp"

// End of header guard
#endif

/************************************ EOF *************************************/
