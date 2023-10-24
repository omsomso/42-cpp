#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2) {
		std::cout << "Usage: ./harl <level>" << std::endl;
		return (1);
	}
	std::string level = argv[1];
	std::transform(level.begin(), level.end(), level.begin(), ::toupper);
	harl.complain(harl.find_level(level));
	return (0);
}
