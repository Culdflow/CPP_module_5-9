#include "Iter.hpp"

// Example function to apply to array elements
void printInt(int& n)
{
	std::cout << n << " ";
}

void increment(int& n)
{
	n += 1;
}

int main()
{
	// Test array
	int arr[] = {1, 2, 3, 4, 5};
	size_t len = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Original array: ";
	iter(arr, len, printInt);  // prints: 1 2 3 4 5
	std::cout << std::endl;

	iter(arr, len, increment); // increment all elements

	std::cout << "After increment: ";
	iter(arr, len, printInt);  // prints: 2 3 4 5 6
	std::cout << std::endl;

	return 0;
}