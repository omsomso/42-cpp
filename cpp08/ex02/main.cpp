#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;
	std::cout << ORANGE "MutantStack inheritance test :" RESET << std::endl;
	mstack.push(7);
	mstack.push(42);
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	mstack.pop();

	std::cout << ORANGE "MutantStack iteration test:" RESET << std::endl;
	MutantStack<int>::mindfck it = mstack.begin();
	for (int i = 0; i < 20; i++)
		mstack.push(i);
	it = mstack.begin();
	while(it != mstack.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	return (0);
}