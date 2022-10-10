#include <stdint.h>

// Node for a binary search tree. Has a value and two child nodes.
struct Node {
	uint32_t value;
	struct Node *left;
	struct Node *right;
};

struct Node* init_node(uint32_t node_value);

// Binary search tree, has "size" for number of nodes and a pointer to the root node.
struct BinarySearchTree { 
	uint32_t size;
	struct Node *root;
};

struct BinarySearchTree* init_bst(struct Node* given_node);

// Given a BST and a value, adds a node with that value to the BST
int tree_add (struct BinarySearchTree* passed_tree, struct Node* new_node);