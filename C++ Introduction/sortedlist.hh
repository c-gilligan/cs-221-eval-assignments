#include <string>
#include <memory>

class Node {
public:
	basic_string<char> value;
	const int length;

	Node* prev;
	Node* next;
}

class SortedList {
public:
	enum how_sorted{length, chars};

	// Using an int return type so that I can return success or failure to add
	int add_element(basic_string<char> new_value);

	enum how_sorted current_sorting();

private:
	Node* first;
	Node* last;
}
