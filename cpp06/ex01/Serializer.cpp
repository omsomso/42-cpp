#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::Serializer(Serializer const &other) {
	*this = other;
}

Serializer::~Serializer() {
}

Serializer& Serializer::operator=(Serializer const &other) {
	(void) other;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t out = reinterpret_cast<uintptr_t>(ptr);
	return (out);
}

Data* Serializer::deserialize(uintptr_t raw) {
	Data *out = reinterpret_cast<Data *>(raw);
	return (out);
}