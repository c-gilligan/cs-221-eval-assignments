#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>

#include "arr_to_bst.h"

int main (int argc, char *argv[]){

	/* 
		node tests (I don't know if this is terrible formatting but I wanted a header that stands out)
	*/
	printf("Starting Node tests.\n");

	uint32_t some_int_1 = 8;
	struct Node *node_1 = init_node(some_int_1);

	assert(node_1 -> value == 8);
	printf("Node Checkpoint 1: node_1 is properly initialized \n");

	uint32_t some_int_2 = 4;
	struct Node *node_2 = init_node(some_int_2);
	node_1 -> left = node_2;

	assert(node_2 -> value == 4);
	printf("Node Checkpoint 2: node_2 is properly initialized \n");

	// Check that the values of the nodes are assigned properly
	printf("Node 1 Value: %i \n", node_1 -> value);
	printf("Node 2 Value: %i \n", node_2 -> value);
	assert(node_1 -> value == 8);
	assert(node_2 -> value == 4);

	// Check that node1.left points to the address of node2
	assert(node_1 -> left == node_2);

	// Check that node2's value can be obtained from node1.left's value 
	assert((node_1 -> left) -> value == 4);

	printf("Node tests complete. \n");
	printf("\n");

	/*
		BinarySearchTree tests
	*/
	printf("Starting BinarySearchTree tests. \n");

	struct BinarySearchTree *test_tree = init_bst(node_1);
	//test_tree.root = node_1;

	assert(test_tree -> root == node_1);

	printf("BinarySearchTree tests complete. \n");
	printf("\n");

	/*
		tree_add tests
		(You can tell how much trouble this gave me by the number of diagnostic print statements)
	*/
	printf("Starting tree_add tests. \n");

	// Init new BST
	struct Node *branch_1 = init_node(3);
	struct BinarySearchTree *redwood = init_bst(branch_1);

	assert(branch_1 -> value == 3);
	assert((redwood -> root) == branch_1);
	assert(redwood -> size == 1);

	// Test adding new node to BST
	struct Node *branch_2 = init_node(2);
	uint32_t redw_ret_code = tree_add(redwood, branch_2);
	printf("Redwood Return Code: %i \n", redw_ret_code);

	assert(redw_ret_code == 0);
	assert(branch_2 -> value == 2);

	// redwood tree diagnostic info
	if(1){
		printf("\n");
		printf("** Redwood Tree Diagnostic Info **\n");
		printf("Redwood Root Left Child Pointer: %p \n", (redwood -> root) -> left);
		printf("Redwood Right Child Pointer: %p \n", (redwood -> root) -> right);
		printf("\n");
	}

	assert((redwood -> root) -> left == branch_2);

	printf("tree_add tests complete. \n");

	/*
		Free memory so that we don't have memory leaks
	*/

	printf("Attempting to free memory. \n");

	free(node_1);
	free(node_2);
	free(branch_1);
	free(branch_2);
	free(test_tree);
	free(redwood);

	printf("Memory freed. \n");

	// All done
	printf("All tests completed. \n");
	return 0;
}