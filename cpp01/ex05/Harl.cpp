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

void Harl::complain(std::string level) {
	void(Harl::*f[4])(void) = {
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
	};
	std::string message[4] = {
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR"
	};
	for (int i = 0; i < 4; i++) {
		if (level == message[i]) {
			(this->*f[i])();
			return ;
		}
	}
	std::cout << "Invalid level" << std::endl;
}

// The `(this->*f[i])()` syntax is used for calling a member function through a pointer-to-member function in C++. The parentheses are necessary to specify the order of operations and to ensure that the member function is called correctly.

// Let's break down the syntax:

// 1. `(this->*f[i])` is an expression that combines the `this` pointer with the member function pointer `f[i]` to create a pointer to a member function call. 

//    - `this` refers to the instance of the class, which is the object on which the member function will be called.
//    - `f[i]` is the pointer to the member function that you want to call.

// 2. `(this->*f[i])()` is a function call. The additional parentheses `()` are used to invoke the member function pointed to by `f[i]` on the instance `this`.

// In C++, when you have a pointer to a member function, you need to use this syntax to call the function, and the extra parentheses are used to ensure that the call is correctly interpreted by the compiler. It's a specific syntax used to distinguish member function pointer calls from regular function calls.