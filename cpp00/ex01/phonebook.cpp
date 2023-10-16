#include "phonebook.hpp"

Contact	Contact::access_contact(Contact entry)
{
	return (entry);
}

std::string	Contact::get_first_name()
{
	return (this->first_name);
}

std::string Contact::get_last_name()
{
	return (this->last_name);
}

std::string Contact::get_nickname()
{
	return (this->nickname);
}

std::string Contact::get_phone_number()
{
	return (this->phone_number);
}

std::string Contact::get_darkest_secret()
{
	return (this->darkest_secret);
}

Contact	Contact::create_contact(Contact entry)
{
	std::cin.clear();
	std::cin.ignore();

	std::cout << "Enter first name: ";
	std::getline(std::cin, this->first_name);
	std::cout << "Enter last name: ";
	std::getline(std::cin, this->last_name);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, this->nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, this->phone_number);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, this->darkest_secret);
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

int	Contact::display_contact(Contact entry, int index)
{
	// std::cout << std::setw(10) << index << "|";

	// if (!get_first_name())
	// 	return (1);
	// std::cout << std::setw(10) << 
	// std::cout << "|" << std::setw(10) 
	// std::cout << "|" << std::setw(10) << entry.get_nickname() << std::endl;

	(void) index;
	std::cout << "First Name\t: " << entry.get_first_name() << std::endl;
	std::cout << "Last Name\t: " << entry.get_last_name() << std::endl;
	std::cout << "Nickname\t: " << entry.get_nickname() << std::endl;
	std::cout << "Phone Number\t: " << entry.get_phone_number() << std::endl;
	std::cout << "Darkest Secret\t: " <<entry.get_darkest_secret() << std::endl;

	return (0);
}

void	PhoneBook::display_contacts(PhoneBook phonebook)
{
	int		index = 0;
	int		i = 0;
	Contact	contact;

	// if (phonebook.entry[0].display_contact(phonebook.entry[0], index) == 1)
	// 	std::cout << "No contacts" << std::endl;
	std::cout << std::setw(10) << "index" << "|" << std::setw(10) <<  "first name";
	std::cout << "|" << std::setw(10) <<  "last name";
	std::cout << "|" << std::setw(10) <<  "nickname" << std::endl;

	std::cout << std::setw(10) << index << "|";

	contact.display_contact(phonebook.entry[0], index);
}
// void	add_contact(PhoneBook phonebook)
// {
// 	Contact entry;

// 	// setiosflags(ios::left);
// 	phonebook.entry[0] = entry.save_contact(phonebook.entry[0]);
// }

int	main(void)
{
	std::string	input;
	PhoneBook	phonebook;
	int			entry_count = -1;

	while (1)
	{
		std::cin >> input;
		if (input == "EXIT" || input == "exit")
			return (0);
		if (input == "ADD" || input == "add")
		{
			entry_count++;
			phonebook.entry[entry_count].create_contact(phonebook.entry[entry_count]);
		}
		if (input == "SEARCH" || input == "search")
			phonebook.display_contacts(phonebook);
		// 	phonebook.entry[0].search_contacts(phonebook);
		if (entry_count == 7)
			entry_count = -1;
	}
	return (0);
}
