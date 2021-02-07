/********************************** METADATA **********************************/

/*
 * Contributors: roadelou
 * Contacts:
 * Creation Date: 2021-02-07
 * Language: Text File
 */

/************************************ BODY ************************************/

// Header Guard
#ifndef PERFORMANCE_SORTED_VECTOR_INCLUDED
#define PERFORMANCE_SORTED_VECTOR_INCLUDED

// Used to measure time.
#include <chrono>

// Used for the array type.
#include <array>

// Used to generate an array of random numbers.
#include <random>

// Used for for_each.
#include <algorithm>

// Used to get access to the SortedVector type.
#include "sorted_vector.hpp"

// A function returning an array of 1000 random unsigned ints.
std::array<unsigned int, 1000> random_numbers(void);

// Returns the runtime in microseconds of the SortedVector to sort the 1000
// provided numbers. Note that we use a pass-by-reference here to borrow the
// unique_ptr to the SortedVector.
std::chrono::microseconds performance_sorted_vector(
    std::unique_ptr<SortedVector<unsigned int>> &sort_factory,
    std::array<unsigned int, 1000> workload);

std::array<unsigned int, 1000> random_numbers(void) {
    // Allocating the array first.
    std::array<unsigned int, 1000> numbers;
    // Filling the array with random unsigned ints. This the number of random
    // numbers is small and randomness doesn't matter, we may just use
    // random_device.
    std::for_each(numbers.begin(), numbers.end(),
                  [](unsigned int &n) { n = std::random_device()(); });
    // Returning the built array.
    return numbers;
}

std::chrono::microseconds performance_sorted_vector(
    std::unique_ptr<SortedVector<unsigned int>> &sort_factory,
    std::array<unsigned int, 1000> workload) {
    // Starting the chrono.
    std::chrono::time_point<std::chrono::system_clock> start =
        std::chrono::system_clock::now();
    // Adding all the elements of the workload to the SortedVector.
    for (unsigned int number : workload) {
        sort_factory->insert(number);
    }
    // Getting the sorted numbers back.
    std::vector<unsigned int> sorted = sort_factory->get_frozen();
    // Stopping the chrono.
    std::chrono::time_point<std::chrono::system_clock> end =
        std::chrono::system_clock::now();
    // Returning the time difference.
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

// End of header guard
#endif

/************************************ EOF *************************************/
