#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

#include "Data.hpp"

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

class Serializer {	
	public :
	Serializer();
	Serializer(Serializer const &other);
	~Serializer();
	Serializer& operator=(Serializer const &other);
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
