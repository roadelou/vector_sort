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

// Used for std::unique_ptr
#include <memory>

// Used for optional return
#include <optional>

// Factory to create the sorted vectors.
#include "sorted_vector_factory.hpp"

int main(int argc, char **argv) {
    // Creating the SortedVector for the int class.
    // Note that we use the constructor without arguments, hence no
    // parenthesis. This is different from the behavior in C, which is a bit
    // unexpected.
    std::optional<std::unique_ptr<SortedVector<int>>> insert_sort_factory_option = make_sorted_vector<int>(std::string("insert"));
    // Same, but for the alternative merge sort implementation.
    std::optional<std::unique_ptr<SortedVector<int>>> merge_sort_factory_option = make_sorted_vector<int>(std::string("merge"));

    // Unwrapping the options here since it is safe. We need to move the
    // unique_ptr out of the option though.
    std::unique_ptr<SortedVector<int>> insert_sort_factory = std::move(insert_sort_factory_option.value());
    std::unique_ptr<SortedVector<int>> merge_sort_factory = std::move(merge_sort_factory_option.value());

    // Iterate over the command line arguments and add them to the
    // SortedVector. We skip the first argument which is the name of the
    // program itself.
    for (int i = 1; i < argc; i++) {
        int value_to_insert = std::stoi(argv[i]);
        // Inserting the value into the SortedVector.
        insert_sort_factory->insert(value_to_insert);
        merge_sort_factory->insert(value_to_insert);
    }

    // Get the vector of sorted integers back.
    std::vector<int> sort_result = insert_sort_factory->get_frozen();

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
    std::vector<int> merge_sort_result = merge_sort_factory->get_frozen();

    // Same output for the merge sort.
    std::cout << "Merge Sort: ";
    // Iterating over the result to print it.
    for (int element : sort_result) { // C++11
        // Printing the element and a space.
        std::cout << element << ' ';
    }
    // Printing final newline.
    std::cout << std::endl;

    // Testing the factory with an invalid value.
    std::optional<std::unique_ptr<SortedVector<int>>> quick_sort_option = make_sorted_vector<int>(std::string("quick"));
    // Matching the option...
    if (quick_sort_option) {
    	std::cout << "Quick sort has been implemented!" << std::endl;
    }
    else {
    	std::cout << "Quick sort is not implemented!" << std::endl;
    }

    // Ending the process.
    return EXIT_SUCCESS;
}

/************************************ EOF *************************************/
