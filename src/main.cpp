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
#include "insert_sorted_vector.hpp"

// Alternative merge sort implementation.
#include "merge_sorted_vector.hpp"

int main(int argc, char **argv) {
    // Creating the SortedVector for the int class.
    // Note that we use the constructor without arguments, hence no
    // parenthesis. This is different from the behavior in C, which is a bit
    // unexpected.
    InsertSortedVector<int> sort_factory;
    // Same, but for the alternative merge sort implementation.
    MergeSortedVector<int> merge_sort_factory;

    // Iterate over the command line arguments and add them to the
    // SortedVector. We skip the first argument which is the name of the
    // program itself.
    for (int i = 1; i < argc; i++) {
        int value_to_insert = std::stoi(argv[i]);
        // Inserting the value into the SortedVector.
        sort_factory.insert(value_to_insert);
        merge_sort_factory.insert(value_to_insert);
    }

    // Get the vector of sorted integers back.
    std::vector<int> sort_result = sort_factory.get_frozen();

    // Outputting theresult of insertion sort.
    std::cout << "Insertion Sort: ";
    // Iterating over the result to print it.
    for (int element : sort_result) { // C++11
        // Printing the element and a space.
        std::cout << element << ' ';
    }
    // Printing final newline.
    std::cout << std::endl;

    // Getting the merge sort result.
    std::vector<int> merge_sort_result = merge_sort_factory.get_frozen();

    // Same output for the merge sort.
    std::cout << "Merge Sort: ";
    // Iterating over the result to print it.
    for (int element : sort_result) { // C++11
        // Printing the element and a space.
        std::cout << element << ' ';
    }
    // Printing final newline.
    std::cout << std::endl;

    // Ending the process.
    return EXIT_SUCCESS;
}

/************************************ EOF *************************************/
