#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

void testFoundVector(std::vector<int>& vec, std::vector<int>::iterator& it) {
	if (it == vec.end())
		std::cout << "Value not found!" << std::endl;
	else 
		std::cout << "Element found at index " << it - vec.begin() << std::endl;
}

void testFoundList(std::list<long>& lst, std::list<long>::iterator& it) {
	if (it == lst.end())
		std::cout << "Value not found!" << std::endl;
	else 
		std::cout << "Element found at index " << std::distance(lst.begin(), it) << std::endl;
}

void testFoundDeque(std::deque<int>& deq, std::deque<int>::iterator& it) {
	if (it == deq.end())
		std::cout << "Value not found!" << std::endl;
	else 
		std::cout << "Element found at index " << std::distance(deq.begin(), it) << std::endl;
}

int main() {
	// Test vector
	std::cout << GREEN "Test with vector : " RESET << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(108);
	vec.push_back(323);
	vec.push_back(34);
	vec.push_back(4);
	std::vector<int>::iterator it;

	it = easyfind(vec, 34);
	testFoundVector(vec, it);

	it = easyfind(vec, 666);
	testFoundVector(vec, it);

	vec.push_back(666);
	std::cout << "Added new element to the vector vec : " << vec[vec.size() - 1] << std::endl;
	it = easyfind(vec, 666);
	testFoundVector(vec, it);

	std::cout << GREEN "Test with list : " RESET << std::endl;
	std::list<long> lst;
	std::list<long>::iterator lit;
	lst.push_back(84376);
	lst.push_front(2);
	lit = easyfind(lst, 84376);
	testFoundList(lst, lit);
	std::cout << "Popping back..." << std::endl;
	lst.pop_back();
	lit = easyfind(lst, 84376);
	testFoundList(lst, lit);

	std::cout << GREEN "Test with deque : " RESET<< std::endl;
	std::deque<int> deq;
	deq.assign(9, 42); // puts 10 times 42 in the beginning of the deque
	deq.push_back(41);
	std::deque<int>::iterator dequeit;
	dequeit = easyfind(deq, 41);
	testFoundDeque(deq, dequeit);
	std::cout << "Assigning 20 x 42..." << std::endl;
	deq.assign(20, 42);
	dequeit = easyfind(deq, 41);
	testFoundDeque(deq, dequeit);

	return (0);
}