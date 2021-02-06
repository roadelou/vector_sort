/********************************** METADATA **********************************/

/*
 * Contributors: roadelou
 * Contacts:
 * Creation Date: 2021-02-06
 * Language: Text File
 */

/************************************ BODY ************************************/

// Header Guard
#ifndef MERGE_SORTED_VECTOR_IMPLEMENTATION_INCLUDED
#define MERGE_SORTED_VECTOR_IMPLEMENTATION_INCLUDED

// Alread included in parent header, but needed here so we remind it.
#include <vector>

// Used to iterate through std::vector.
#include <iterator>

// Prototype of the merge sort function.
template <typename Sortable>
std::vector<Sortable> merge_sort(std::vector<Sortable> unsorted);

// Constructor implementation.
template <typename Sortable>
MergeSortedVector<Sortable>::MergeSortedVector(void) {
    // Creating inner vector.
    this->inner = new std::vector<Sortable>();
}

template <typename Sortable>
void MergeSortedVector<Sortable>::insert(Sortable element) {
    // We simply add the element at the end of the vector, the sort is
    // performed in this->get_frozen.
    this->inner->push_back(element);
}

template <typename Sortable>
size_t MergeSortedVector<Sortable>::get_size(void) {
    // Calling the appropriate std::vector function.
    return this->inner->size();
}

template <typename Sortable>
std::vector<Sortable> MergeSortedVector<Sortable>::get_frozen(void) {
    // Returning the result of merge sort on the inner vector.
    return merge_sort<Sortable>(*this->inner);
}

// Internal function used to perform the recursive merge sort.
template <typename Sortable>
std::vector<Sortable> merge_sort(std::vector<Sortable> unsorted) {
    // Grabbing the size of the unsorted input vector.
    size_t size = unsorted.size();
    // Base case, the size of unsorted is 1 (or edge case 0).
    if (size <= 1) {
        // The vector is already sorted, we merely need to return it.
        return unsorted;
    } else {
        // We create two new vectors, one for each part of the original
        // unsorted vector.
        int half = size / 2;
        std::vector<Sortable> first_vector(unsorted.begin(),
                                           std::next(unsorted.begin(), half));
        std::vector<Sortable> second_vector(std::next(unsorted.begin(), half),
                                            unsorted.end());

        // Recursively sorting the two halves of the input vector.
        std::vector<Sortable> sorted_first_vector =
            merge_sort<Sortable>(first_vector);
        std::vector<Sortable> sorted_second_vector =
            merge_sort<Sortable>(second_vector);

        // Creating a third vector to store the sorted result. Note the
        // constructor without arguments doesn't use parenthesis.
        std::vector<Sortable> sorted_vector;
        // We already know the future size of the sorted vector, we may
        // reserve it in advance.
        sorted_vector.reserve(unsorted.size());

        // Getting the iterator for the two sorted half vectors.
        typename std::vector<Sortable>::iterator first_iterator =
            sorted_first_vector.begin();
        typename std::vector<Sortable>::iterator second_iterator =
            sorted_second_vector.begin();

        // Emptying the first sorted vector first.
        while (first_iterator != sorted_first_vector.end()) {
            // We first insert the elements from the second vector
            // which should come before the inspected element from
            // the first list.
            while (second_iterator != sorted_second_vector.end() and
                   *first_iterator > *second_iterator) {
                // Inserting the element from the second vector,
                // because it is smaller.
                sorted_vector.push_back(*second_iterator);
                // Moving the second iterator.
                second_iterator = std::next(second_iterator);
            }
            // The element from the first vector comes next, we
            // insert it now.
            sorted_vector.push_back(*first_iterator);
            // We move on to the next element of the first vector.
            first_iterator = std::next(first_iterator);
        }

        // EDGE CASE
        // ---------
        // The first vector is now empty, but the second one still has
        // more elements. We add them all in their current sorted order
        // at the end of the returned sorted vector.
        while (second_iterator != sorted_second_vector.end()) {
            sorted_vector.push_back(*second_iterator);
            second_iterator = std::next(second_iterator);
        }

        // The sorted vector is now ready, we may return it.
        return sorted_vector;
    }
}

// End of header guard
#endif

/************************************ EOF *************************************/
