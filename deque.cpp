#include "Deque.hpp"
#include <iostream>

Deque_DEFINE(int)

int main() {
	Deque_int deq;
	// deq.push_front(5);

	std::cout << "definition of deque" << std::endl;
	std::cout << sizeof(long) << std::endl;
	std::cout << INT32_MAX << std::endl;
	std::cout << INT64_MAX << std::endl;
	
	std::cout << "Size of char: " << sizeof(char) << " byte" << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of long: " << sizeof(long) << " bytes" << std::endl;

    std::cout << "Size of float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
	return 0;
}