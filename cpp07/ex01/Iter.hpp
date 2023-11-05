#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

template <typename T> void iter(T* array, size_t size, void (*f)(T&)) {
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}


template <typename T> void toFortyTwoer(T& i) {
		i = 42;
}

#endif