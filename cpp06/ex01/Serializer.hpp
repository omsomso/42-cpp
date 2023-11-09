#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

#include "Data.hpp"

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

class Serializer {
	private:
	Serializer();
	Serializer(Serializer const &other);
	Serializer& operator=(Serializer const &other);
	~Serializer();

	public :
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
