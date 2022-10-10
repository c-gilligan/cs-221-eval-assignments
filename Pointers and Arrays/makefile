tests : tests.c binary_search_tree.o arr_to_bst.o
	gcc tests.c -o tests binary_search_tree.o arr_to_bst.o

binary_search_tree.o : binary_search_tree.c
	gcc binary_search_tree.c -c

arr_to_bst.o : arr_to_bst.c 
	gcc arr_to_bst.c -c

clean : 
	rm tests; rm binary_search_tree.o; rm arr_to_bst.o

rebuild : 
	make clean; make && ./tests

debug_tests : tests.c debug_binary_search_tree.o
	gcc tests.c -o debug_tests debug_binary_search_tree.o -O0

debug_binary_search_tree.o : binary_search_tree.c 
	gcc binary_search_tree.c -c -o debug_binary_search_tree.o