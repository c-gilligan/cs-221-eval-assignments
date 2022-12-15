#include <memory>

class Node {
public:
	template <typename T>
	unique_ptr <typename T>;
	shared_ptr<Node> left;
	shared_ptr<Node> right;
	weak_ptr<Node> prev;
}

class BinarySearchTree {
public:
	shared_ptr<Node> root() {
		return this -> root;
	}

	int size() {
		return this -> size;
	}

private:
	shared_ptr<Node> root;
	int size;
}