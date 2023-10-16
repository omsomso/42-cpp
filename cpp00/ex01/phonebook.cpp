#include "phonebook.hpp"

Contact	Contact::access_contact(Contact entry)
{
	return (entry);
}

Contact	Contact::save_contact(Contact entry)
{
	std::cout << "Enter first name: ";
	std::getline(std::cin, entry.first_name);
	std::cout << "Enter last name: ";
	std::getline(std::cin, entry.last_name);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, entry.nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, entry.phone_number);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, entry.darkest_secret);
	std::cout << std::endl;
	// std::cout << "First name: " << entry.first_name << std::endl;
	// std::cout << "Last name: " << entry.last_name << std::endl;
	// std::cout << "Nickname: " << entry.nickname << std::endl;
	// std::cout << "Phone number: " << entry.phone_number << std::endl;
	// std::cout << "Darkest secret: " << entry.darkest_secret << std::endl;
	return (entry);
}

std::string	Contact::fix_lenght(std::string s)
{
	if (s.length() > 10)
	{
		s.resize(9);
		s.append(".");
	}
	return (s);
}

int	Contact::diplay_contact(Contact entry, int index)
{

	std::cout << std::setw(10) << index << "|";

	if (entry.first_name.length == 0)
		return (1);
	std::cout << std::setw(10) << entry.fix_lenght(entry.first_name);
	std::cout << "|" << std::setw(10) << fix_lenght(entry.last_name);
	std::cout << "|" << std::setw(10) << fix_lenght(entry.nickname) << std::endl;
	return (0);
}

void	PhoneBook::diplay_contacts(PhoneBook phonebook)
{
	int		index = 0;

	if (phonebook.entry[0].diplay_contact(phonebook.entry[0], index) == 1)
		std::cout << "No contacts" << std::endl;
}
void	add_contact(PhoneBook phonebook)
{
	Contact entry;

	// setiosflags(ios::left);
	phonebook.entry[0] = entry.save_contact(phonebook.entry[0]);
	std::cout << std::setw(10) << "index" << "|" << std::setw(10) <<  "first name";
	std::cout << "|" << std::setw(10) <<  "last name";
	std::cout << "|" << std::setw(10) <<  "nickname" << std::endl;
}

int	main(void)
{
	PhoneBook	phonebook;

	add_contact(phonebook);
	return (0);
}