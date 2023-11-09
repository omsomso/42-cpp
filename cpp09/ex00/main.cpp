#include <iostream>
#include <fstream>
#include <vector>
#include <map>

class Btc {
	private:
	std::map<std::string, std::string> _db;

	public:
	int initDatabase(std::string input);

};

int Btc::initDatabase(std::string input) {
	std::ifstream inputFile;
	try {
		inputFile.open("data.csv");
	}
	catch (std::ios_base::failure& e) {
		std::cerr << "Error : couldn't open file" << std::endl;
	}
	
}

int main(int ac, char** av) {
	if (ac != 2) {
		std::cerr << "Error : couldn't find file" << std::endl;
		return (1);
	}
	std::string input = av[1];
	return (0);
}