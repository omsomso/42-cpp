#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "It rains but i like it" << std::endl;
}

void Harl::info(void) {
	std::cout << "Rain here is used as a literary device" << std::endl;
}

void Harl::warning(void) {
	std::cout << "It actually rains since 2 weeks" << std::endl;
}

void Harl::error(void) {
	std::cout << "The basement flooded" << std::endl;
}

int Harl::find_level(std::string level) {
	std::string message[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (int i = 0; i < 4; i++) {
		if (level == message[i])
			return (i);
	}
	return (-1);
}

void Harl::complain(int level) {
	switch (level) {
		default :
			std::cout << "Invalid level" << std::endl;
			return ;
		case DEBUG :
			this->debug();
		case INFO :
			this->info();
		case WARNING :
			this->warning();
		case ERROR :
			this->error();
	}
}