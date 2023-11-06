#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
	// Test vector
	std::cout << ORANGE "Test with vector : " RESET << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(108);
	vec.push_back(323);
	vec.push_back(34);
	vec.push_back(4);

	std::vector<int>::iterator it;
	it = easyfind(vec, 34);
	testFound(vec, it);
	it = easyfind(vec, 666);
	testFound(vec, it);
	vec.push_back(666);
	std::cout << "...added new element to the vector vec : " << vec[vec.size() - 1] << std::endl;
	it = easyfind(vec, 666);
	testFound(vec, it);

	// Test list
	std::cout << ORANGE "Test with list : " RESET << std::endl;

	std::list<long> lst;
	lst.push_back(84376);
	lst.push_front(2);
	testFound(lst, easyfind(lst, 84376));
	lst.pop_back();
	std::cout << "...popped back the list" << std::endl;
	testFound(lst, easyfind(lst, 84376));

	std::cout << ORANGE "Test with deque : " RESET<< std::endl;
	std::deque<int> deq;
	deq.assign(9, 42); // puts 10 times 42 in the beginning of the deque
	deq.push_back(41);
	testFound(deq, easyfind(deq, 41));
	std::cout << "...assigning 20 x 42..." << std::endl;
	deq.assign(20, 42);
	testFound(deq, easyfind(deq, 41));

	return (0);
}