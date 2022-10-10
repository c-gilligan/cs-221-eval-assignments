#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "binary_search_tree.h"

struct BinarySearchTree* arr_to_bst(int* input_array[], uint32_t arr_length) {
	// Initialize first node and BST
	struct Node *first_node = init_node(*input_array[0]);
	struct BinarySearchTree *new_bst = init_bst(first_node);

	// Initialize and run while loop
	uint32_t i = 1;
	while (i <= arr_length){
		struct Node *new_node = init_node(*input_array[i]);
		assert(tree_add(new_bst, new_node) == 0);

		i++;
	}


	return new_bst;
}