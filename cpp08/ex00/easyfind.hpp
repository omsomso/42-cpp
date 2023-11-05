#include <iostream>
#include <algorithm>
#include <vector>

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

template <typename T>
typename T::iterator easyfind(T& container, int nb) {
	typename T::iterator it = (std::find(container.begin(), container.end(), nb));
	return (it);
}