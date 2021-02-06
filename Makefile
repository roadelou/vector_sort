################################### METADATA ###################################

# Contributors: roadelou
# Contacts: 
# Creation Date: 2021-02-06
# Language: Makefile

################################### ALIASES ####################################

src = src/main.cpp

head_insert = include/sorted_vector.hpp include/sorted_vector_implementation.hpp
head_merge = include/merge_sorted_vector.hpp include/merge_sorted_vector_implementation.hpp
head = $(head_insert) $(head_merge)

exec = build/sort.elf

################################### SPECIAL ####################################

.PHONY: clean

#################################### RULES #####################################

$(exec): $(src) $(head)
	mkdir -p build
	c++ $(src) -I include -o $(exec)

clean:
	rm -f $(exec)

##################################### EOF ######################################
