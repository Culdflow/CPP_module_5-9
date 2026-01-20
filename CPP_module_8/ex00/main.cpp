#include "easyFind.hpp"

int main()
{
	std::vector<int> numbers;

	numbers.push_back(1);
	numbers.push_back(3);
	numbers.push_back(5);
	numbers.push_back(7);

	try
	{
		// Should succeed
		std::vector<int>::iterator it = easyfind(numbers, 5);
		std::cout << "Found value: " << *it << std::endl;

		// Should throw
		it = easyfind(numbers, 42);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const ValueNotFound& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}