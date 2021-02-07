################################### METADATA ###################################

# Contributors: roadelou
# Contacts: 
# Creation Date: 2021-02-06
# Language: Makefile

################################### ALIASES ####################################

src = src/main.cpp

head_insert = include/insert_sorted_vector.hpp include/insert_sorted_vector_implementation.hpp
head_merge = include/merge_sorted_vector.hpp include/merge_sorted_vector_implementation.hpp
head_base = include/sorted_vector.hpp include/sorted_vector_factory.hpp
head_performance = include/performance_sorted_vector.hpp
head_general = $(head_base) $(head_performance)
head = $(head_insert) $(head_merge) $(head_general)

exec = build/sort.elf

################################### SPECIAL ####################################

.PHONY: clean

#################################### RULES #####################################

# Note that C++17 is required for optional.
$(exec): $(src) $(head)
	mkdir -p build
	clang++ -Wall -pedantic -std=c++17 $(src) -I include -o $(exec)

clean:
	rm -f $(exec)

##################################### EOF ######################################
