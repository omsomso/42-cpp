#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

template <typename T> void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T max(T a, T b) {
	return (a > b ? a : b);
}

template <typename T> T min(T a, T b) {
	return(a < b ? a : b);
}

#endif