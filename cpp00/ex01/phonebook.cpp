#include "phonebook.hpp"

// phonebook constructor
PhoneBook::PhoneBook()	{
	entry_count = 0;
}

void	PhoneBook::display_phonebook_entry(int index)	{
	this->entry[index].display_contact();
}

void	PhoneBook::add_phonebook_entry(int index)	{
	this->entry[index].create_contact();
}

// search functionality
void	PhoneBook::search()
{
	Contact		contact;
	std::string	input;
	std::string	tmp;
	int			index;

	// check if there are any contacts
	tmp = this->entry[0].get_first_name();
	if (tmp.length() == 0)
	{
		std::cout << "No contacts :(" << std::endl;
		return ;
	}

	// display contact preview table
	std::cout << std::setw(10) << "index" << "|" << std::setw(10) <<  "first name";
	std::cout << "|" << std::setw(10) <<  "last name";
	std::cout << "|" << std::setw(10) <<  "nickname" << std::endl;

	// display contact previews
	for (int i = 0; i < 8; i++)
		this->entry[i].display_contact_preview(i);

	// ask for index input
	std::cout << "Enter index: ";
	std::cin >> input;

	// check if index is a number
	if (!all_of(input.begin(), input.end(), ::isdigit))
	{
		std::cout << "Error : Wrong index" << std::endl;
		return ;
	}

	// check if index is between 0 and 7
	index = stoi(input);
	if (input.length() > 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "Error : Wrong index" << std::endl;
		return ;
	}

	// check if contact exists
	input = this->entry[index].get_first_name();
	if (input.length() == 0)
	{
		std::cout << "Error : Empty entry" << std::endl;
		return ;
	}

	// display contact
	else
		this->display_phonebook_entry(index);
	
	std::cin.clear();
	std::cin.ignore();
}

int	main(void)
{
	std::string	input;
	PhoneBook	phonebook;

	std::cout << "AVALIABLE COMMANDS : ADD / SEARCH / EXIT" << std::endl;
	while (1)
	{
		std::cin >> input;
		if (input == "EXIT" || input == "exit")
		{
			std::cout << "Your contacts are gone lol bye" << std::endl;
			return (0);
		}
		if (input == "ADD" || input == "add")
			phonebook.add_phonebook_entry(phonebook.entry_count++);
		if (input == "SEARCH" || input == "search")
			phonebook.search();
		phonebook.entry_count %= 8;
	}
	return (0);
}
