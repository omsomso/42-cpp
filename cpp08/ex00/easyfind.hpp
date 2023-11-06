#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

#define GREEN "\033[0;32m"
#define ORANGE "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

template <typename Container>
typename Container::iterator easyfind(Container& container, int nb) {
	typename Container::iterator it = (std::find(container.begin(), container.end(), nb));
	return (it);
}

template <typename Container>
void testFound(Container& container, const typename Container::iterator& it) {
	if (it == container.end())
		std::cout << "Value not found!" << std::endl;
	else 
		std::cout << "Element found at index " << std::distance(container.begin(), it) << std::endl;
}

#endif