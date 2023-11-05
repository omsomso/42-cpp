#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstring>

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

template <typename T>
class Array {
	private :
	T* _values;
	unsigned int _size;

	public :
	Array() : _values(new T[_size]), _size(0) {}
	Array(unsigned int n) : _values(new T[n]), _size(n) {}
	~Array() {
		delete[] this->_values;
	}
	Array(const Array &other) {
		*this = other;
	}
	Array& operator=(const Array &other) {
		this->_size = other._size;
		delete[] this->_values;
		this->_values = new T[other._size];
		std::memcpy(this->_values, other._values, other._size);
		return (*this);
	}
	T& operator[](unsigned int index) {
		if (index >= _size)
			throw std::out_of_range("Array index out of bounds.");
		return _values[index];
	}
};

#endif