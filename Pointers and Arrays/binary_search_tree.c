#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

// Nodes must have a value, pointer to the left child, and pointer to the right child.
struct Node {
	uint32_t value;
	struct Node *left;
	struct Node *right;
};

// Node initialization function sets child nodes to NULL by default
struct Node* init_node(uint32_t node_value){
	struct Node* new_node = malloc(sizeof(struct Node));

	printf("New Node Pointer: %p \n", new_node);

	new_node -> value = node_value;
	new_node -> left = NULL;
	new_node -> right = NULL;

	printf("New Node Value: %i \n", new_node -> value);
	assert(new_node -> value == node_value);

	return new_node;
}

// Binary search trees must have a size and a pointer to the first (root) node
struct BinarySearchTree {
	uint32_t size; // int for number of elements in tree
	struct Node *root;
};

struct BinarySearchTree* init_bst(struct Node* given_node){
	struct BinarySearchTree *new_tree = malloc(sizeof(struct BinarySearchTree));
	new_tree -> root = given_node;
	new_tree -> size = 1;

	return new_tree;
}

// tree_add has return type int so that it can return exit codes.
// 0 == added; -1 == failed to add; 1 == already in tree
int tree_add (struct BinarySearchTree* passed_tree, struct Node* new_node) {
	struct BinarySearchTree tree = *passed_tree;
	uint32_t new_value = new_node -> value;

	struct Node *current_node = tree.root;
	struct Node *next_node = NULL;

	// Int to track which child of the current node should be set to the new node
	// 0 = init value; 1 = left; 2 = right
	uint32_t which_way = 0;

	do {
		printf("Beginning loop in tree_add. \n");

		// Set value of next_node
		if (new_value < current_node -> value) {
			next_node = current_node -> left;
			which_way = 1;
			// printf("Debug: Moving left on tree. \n");
		}

		else if (new_value > current_node -> value) {
			next_node = current_node -> right;
			which_way = 2;
			// printf("Debug: Moving right on tree. \n");
		}

		else if (new_value == current_node -> value) {
			return 1;
		}

		else {
			printf("Oopsie woopsie! Looks like you did a fucky wucky! \n");
			return -1;
		}
		// printf("Debug: Loop iterated. \n");
	} while(next_node != NULL);

	// Add new node to tree
	switch(which_way){
		case 1:
			current_node -> left = new_node;
			tree.size++;

			return 0;

		case 2:
			current_node -> right = new_node;
			tree.size++;

			return 0;

		case 0:
			printf("ASDKJFHGSDFGSA it brokey \n");
			return -1;

	}
	return -1;
}