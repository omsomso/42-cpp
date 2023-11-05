#include <iostream>
#include "Array.hpp"

#define MAX_VAL 21
int main(int, char**) {
	std::cout << GREEN "main.cpp tests provided in the subject" RESET << std::endl;
	std::cout << GREEN "Creating int array and its mirror with " << MAX_VAL << " random values" << std::endl;
	std::cout << "Printing max. 10 first values" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
		if (i < 10)
		std::cout << numbers[i] << " ";
    }
	std::cout << std::endl;
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

	std::cout << "Testing if array and mirror are the same" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	std::cout << "Testing array out of bounds exceptions" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	// whats the point of this
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}