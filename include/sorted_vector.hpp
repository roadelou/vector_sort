/********************************** METADATA **********************************/

/*
 * Contributors: roadelou
 * Contacts:
 * Creation Date: 2021-02-07
 * Language: Text File
 */

/************************************ BODY ************************************/

// Header Guard
#ifndef SORTED_VECTOR_INCLUDED
#define SORTED_VECTOR_INCLUDED

// Used for std::vector
#include <vector>

// Abstract base class for all the SortedVector kinds.
template <typename Sortable> class SortedVector {
    // The inner vector must be accessible within the child classes.
  protected:
    // Inner vector used by composition.
    std::vector<Sortable> *inner;

  public:
    // Abstract destructor to avoid memory leak.
    virtual ~SortedVector(void) = default;
    // Inserts the element into the array.
    virtual void insert(Sortable element) = 0;
    // Get the size of the array.
    virtual size_t get_size(void) = 0;
    // Returns a frozen copy of the content of the array.
    virtual std::vector<Sortable> get_frozen(void) = 0;
};

// End of header guard
#endif

/************************************ EOF *************************************/
