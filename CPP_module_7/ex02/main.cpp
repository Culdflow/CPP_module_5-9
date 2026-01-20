#include "Array.hpp"

int main() {
    try {
        // Create an Array of 5 ints
        Array<int> arr(5);

        // Fill it
        for (unsigned int i = 0; i < arr.size(); i++)
            arr[i] = i * 10;

        // Print it
        std::cout << "Original array: ";
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        // Copy constructor
        Array<int> copyArr(arr);
        std::cout << "Copied array: ";
        for (unsigned int i = 0; i < copyArr.size(); i++)
            std::cout << copyArr[i] << " ";
        std::cout << std::endl;

        // Assignment operator
        Array<int> assignArr;
        assignArr = arr;
        std::cout << "Assigned array: ";
        for (unsigned int i = 0; i < assignArr.size(); i++)
            std::cout << assignArr[i] << " ";
        std::cout << std::endl;

        // Test out-of-bounds
        std::cout << "Accessing out-of-bounds element: ";
        std::cout << arr[10] << std::endl; // throws exception

    } catch (const Array<int>::IndexOutOfRange& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}