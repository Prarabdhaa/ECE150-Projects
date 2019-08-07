#include <iostream>
using namespace std;

struct Item{
	// Data component
	int num;
	// Linked list component
	Item* next;
};

Item* addItem(Item* head, int number){
	Item* curr = new Item;
	curr->num = number;
	curr->next = head;
	return curr;
}

void print(Item* curr){
	for (; curr != NULL; curr=curr->next)
		cout << curr->num << " ";
	cout << endl;
	return;
}

int main(){
	
	// Create a stack head
	Item* stack = NULL;

	// Start expanding the list
	int x;
	while (cin.peek() != '\n'){
		cin >> x;
		if ( cin.good() && 
			(cin.peek() == ' ' || cin.peek() == '\n') )
			stack = addItem(stack, x);
		else{
			cerr << "Error in input!\n";
			return -1;
		}
	}
	while (cin.get() != '\n');	// Flush past the line return in the cin stream

	// Print the stack items
	cout << endl << "The stack contains: ";
	print(stack);
	
	return 0;
}
