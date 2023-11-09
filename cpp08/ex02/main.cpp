#include <iostream>
#include <deque>
#include <list>
#include "MutantStack.hpp"

void subjectTest() {
	std::cout << ORANGE "Subject test :" RESET << std::endl;
	std::cout << "MutantStack output :" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::mindfck it = mstack.begin();
	MutantStack<int>::mindfck ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << "List output :" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);
	std::list<int>::iterator lt = lst.begin();
	std::list<int>::iterator lte = lst.end();
	++lt;
	--lt;
	while (lt != lte)
	{
	std::cout << *lt << std::endl;
	++lt;
	}
	std::list<int> t(lst);
}

void inheritanceTest() {
	std::cout << ORANGE "MutantStack inheritance test :" RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(7);
	mstack.push(42);
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	mstack.pop();
}

void iterationTest() {
	std::cout << ORANGE "MutantStack iteration test:" RESET << std::endl;
	MutantStack<int> mstack;
	MutantStack<int>::mindfck it = mstack.begin();
	for (int i = 0; i < 20; i++)
		mstack.push(i);
	it = mstack.begin();
	while(it != mstack.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

void copyTest() {
	std::cout << ORANGE "MutantStack copy test :" RESET << std::endl;
	MutantStack<int> a, c;
	a.push(1);
	MutantStack<int> b(a);
	c.push(2);
	std::cout << "a \tb\tc" << std::endl;

	std::cout << a.top() << "\t" << b.top() << "\t" << c.top() << std::endl;
	c = b = a;
	std::cout << a.top() << "\t" << b.top() << "\t" << c.top() << std::endl;
}

int main() {
	subjectTest();
	inheritanceTest();
	iterationTest();
	copyTest();
	return (0);
}