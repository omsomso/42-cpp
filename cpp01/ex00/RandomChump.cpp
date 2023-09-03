void	RandomChump::announce(void)
{
	std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void	RandomChump::randomChump(std::string name)
{
	Zombie	new_zombie;

	new_zombie.name = name;
	new_zombie.announce();
}

RandomChump::~RandomChump()
{
	std::cout << "Zombie " << this->name << " dieded further" << std::endl;
}