#include <iostream>
using namespace std;

int main(){
	const int N = 5;
	char textArray[N];		// Define an array with 5 chars
	int varAfterArray;		// Define an integer variable

	char x = cin.get();				// Get one character
	int i = 0;						// Create an array counter
	while (x != '\n' && i < N-1){	// Loop only if there is space and not line return
		textArray[i] = x;			// Store current char to the current array element
		i++;						// Update the array counter
		x = cin.get();				// Load the next character
	}
	textArray[i] = 0;		// Add a null termination character to end of text

	varAfterArray = 1;		// Update the integer varable

	cout << textArray;		// Output the text array
	return 0;
}