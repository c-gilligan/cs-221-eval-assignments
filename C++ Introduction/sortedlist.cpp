#include <iostream>
#include <string>


class Node {
public:
	basic_string<char> value;
	const int length = value.length();

	weak_ptr<Node> prev;	// Using weak pointer for prev to prevent pointer
	shared_ptr<Node> next;	// loops that would cause memory leaks
}

// Note to self, make next pointers shared and prev pointers weak
class SortedList {
public:
	enum how_sorted{length, chars};

	// Using an int return type so that I can return success or failure to add
	int add_element(basic_string<char> new_value){
		shared_ptr<Node> new_node = Node();

		// If list has no elements
		if (this -> first == nullptr){
			this -> first = new_node;
			this -> last = new_node;

			return 0;
		}

		// Add works differently depending on how the list is sorted
		switch (how_sorted) {

			case length:

				// Special case: if new_value < first element
				if(new_value.size() < (this -> first)length){
					(this -> first).prev = new_node;
					new_node -> next = this -> first;
					(this -> first) = new_node;
				}

				Node* current = this -> first;
				while (current -> next != nullptr) {
					if(new_value.size() <= current -> length){
						new_node -> next = current;
						new_node -> prev = current -> prev;
						current -> prev = new_node;
					}
				}

			case chars:
		}
	}

	enum how_sorted current_sorting() {
		return how_sorted;
	};

private:
	Node* first;
	Node* last;
}