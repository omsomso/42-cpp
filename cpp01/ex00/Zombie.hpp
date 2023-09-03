#include <iostream>

class Zombie
{
	private :
		std::string name;
	
	public :
		~Zombie();
		void 	announce(void);
		Zombie	*newZombie(std::string name);
		void	RandomChump(std::string name);
		~RandomChump();
		// void	randomChump(std::string name);
};

class RandomChump
{
	private :
		std::string name;
	
	public :
		void	announce(void);
};