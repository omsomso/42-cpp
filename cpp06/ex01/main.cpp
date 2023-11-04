#include "Serializer.hpp"
#include "Data.hpp"

Data* initData() {
	Data *out = new Data;
	out->c = 'a';
	out->i = 1337;
	out->l = 713705;
	out->s = "salut world!";
	return (out);
}

void printData(Data* data) {
	std::cout << "char c\t: " << data->c << std::endl;
	std::cout << "int i\t: " << data->i << std::endl;
	std::cout << "long l\t: " << data->l << std::endl;
	std::cout << "str s\t: " << data->s << std::endl;
}

void printRaw(uintptr_t raw) {
	char* rawChar = reinterpret_cast<char*>(raw);
	for (size_t i = 0; i < sizeof(Data); i++)
		std::cout << rawChar[i];
	std::cout << std::endl;
}

int main() {
	Data* originalData = initData();

	std::cout << GREEN "Before serialization : " RESET << std::endl;
	printData(originalData);

	std::cout << GREEN "Serialized Data : " RESET << std::endl;
	uintptr_t ptrToRaw = Serializer::serialize(originalData);
	printRaw(ptrToRaw);

	std::cout << GREEN "After deserialization : " RESET << std::endl;
	Data *reserializedData = Serializer::deserialize(ptrToRaw);
	printData(reserializedData);

	delete originalData;
	return (0);
}