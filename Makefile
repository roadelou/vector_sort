################################### METADATA ###################################

# Contributors: roadelou
# Contacts: 
# Creation Date: 2021-02-06
# Language: Makefile

################################### ALIASES ####################################

src = src/main.cpp

head = include/sorted_vector.hpp include/sorted_vector_implementation.hpp

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
