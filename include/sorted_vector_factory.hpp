/********************************** METADATA **********************************/

/*
 * Contributors: roadelou
 * Contacts:
 * Creation Date: 2021-02-07
 * Language: Text File
 */

/************************************ BODY ************************************/

// Header Guard
#ifndef SORTED_VECTOR_FACTORY_INCLUDED
#define SORTED_VECTOR_FACTORY_INCLUDED

// Used for base class.
#include "sorted_vector.hpp"

// Since we can't return an abstract class, we return a unique_ptr instead.
#include <memory>

// Used for optional return.
#include <optional>

// Used for insertion sort.
#include "insert_sorted_vector.hpp"

// Used for merge sort.
#include "merge_sorted_vector.hpp"

// Defining a single function which returns the appropriate SortedVector based
// on a choice string.
template <typename Sortable>
std::optional<std::unique_ptr<SortedVector<Sortable>>>
make_sorted_vector(std::string type_choice);

// The implementation of the function goes in the header because of the
// templates.
template <typename Sortable>
std::optional<std::unique_ptr<SortedVector<Sortable>>>
make_sorted_vector(std::string type_choice) {
    // I cannot switch on strings (nothing unexpected) and I can't be
    // bothered to make an enum here, so it will just use an if chain.
    if (type_choice == "insert") {
        return std::make_unique<InsertSortedVector<Sortable>>();
    } else if (type_choice == "merge") {
        return std::make_unique<MergeSortedVector<Sortable>>();
    } else {
        // Unrecognized choice, return nullopt instead.
        return std::nullopt;
    }
}

// End of header guard
#endif

/************************************ EOF *************************************/
