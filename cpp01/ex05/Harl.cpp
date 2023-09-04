#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "It rains but i like it" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Rain here is used as a literary device" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "It actually rains since 2 weeks" << std::endl;
}

void Harl::error(void)
{
	std::cout << "The basement flooded" << std::endl;
}

void Harl::complain(std::string level)
{
	if (level == "DEBUG")
		debug();
	else if (level == "INFO")
		info();
	else if (level == "WARNING")
		warning();
	else if (level == "ERROR")
		error();
	else
		std::cout << "Invalid level" << std::endl;
}