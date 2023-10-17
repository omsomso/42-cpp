#include "phonebook.hpp"

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

// check if input string isn't empty or isn't only whitespaces
int		Contact::check_validity(std::string input)
{
	if (input.length() == 0)
	{
		std::cout << "Field can't be left empty!" << std::endl;
		return (1);
	}
	if (all_of(input.begin(), input.end(), ::isspace))
	{
		std::cout << "Field can't be left empty!" << std::endl;
		return (1);
	}
	return (0);
}

// asks user to input contact and adds it to the memory
Contact	Contact::create_contact(Contact entry)
{
	std::cin.clear();
	std::cin.ignore();

	do	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, entry.first_name);
	}
	while (entry.check_validity(entry.first_name) == 1);
	do	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, entry.last_name);
	}
	while (entry.check_validity(entry.last_name) == 1);
	do	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, entry.nickname);
	}
	while (entry.check_validity(entry.nickname) == 1);
	do	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, entry.phone_number);
	}
	while (entry.check_validity(entry.phone_number) == 1);
	do	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, entry.darkest_secret);
	}
	while (entry.check_validity(entry.darkest_secret) == 1);

	std::cout << std::endl;

	return (entry);
}

// fixes input string lenght for preview display
std::string	Contact::fix_lenght(std::string s)
{
	if (s.length() > 10)
	{
		s.resize(9);
		s.append(".");
	}
	return (s);
}

// displays full contact info
int	Contact::display_contact(Contact entry)
{
	std::cout << "First Name\t: " << entry.get_first_name() << std::endl;
	std::cout << "Last Name\t: " << entry.get_last_name() << std::endl;
	std::cout << "Nickname\t: " << entry.get_nickname() << std::endl;
	std::cout << "Phone Number\t: " << entry.get_phone_number() << std::endl;
	std::cout << "Darkest Secret\t: " <<entry.get_darkest_secret() << std::endl;

	return (0);
}

// displays preview info for a contact
int	Contact::display_contact_preview(Contact entry, int index)
{
	std::string	tmp;

	// check if contact exists
	tmp = entry.get_first_name();
	if (tmp.length() == 0)
		return (1);
	
	// display contact
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << entry.fix_lenght(entry.get_first_name());
	std::cout << "|" << std::setw(10) << entry.fix_lenght(entry.get_last_name());
	std::cout << "|" << std::setw(10) << entry.fix_lenght(entry.get_nickname()) << std::endl;

	return (0);
}

// search functionality
void	PhoneBook::display_contacts(PhoneBook phonebook)
{
	Contact		contact;
	std::string	input;
	std::string	tmp;
	int			index;

	// check if there are any contacts
	tmp = phonebook.entry[0].get_first_name();
	if (tmp.length() == 0)
	{
		std::cout << "No contacts" << std::endl;
		return ;
	}

	// display contact preview table
	std::cout << std::setw(10) << "index" << "|" << std::setw(10) <<  "first name";
	std::cout << "|" << std::setw(10) <<  "last name";
	std::cout << "|" << std::setw(10) <<  "nickname" << std::endl;

	// display contact previews
	for (int i = 0; i < 8; i++)
		phonebook.entry[i].display_contact_preview(phonebook.entry[i], i);

	// ask for index input
	// std::getline(std::cin, input);
	std::cout << "Enter index: ";
	std::cin >> input;

	// check if index is a number
	if (!all_of(input.begin(), input.end(), ::isdigit))
	{
		std::cout << "Wrong index" << std::endl;
		return ;
	}

	// check if index is between 0 and 7
	index = stoi(input);
	if (input.length() > 1 || input[0] < '0' || input[0] > '7')
		std::cout << "Wrong index" << std::endl;

	// check if contact exists
	input = phonebook.entry[index].get_first_name();
	if (input.length() == 0)
		std::cout << "Empty entry!" << std::endl;

	// display contact
	else
		contact.display_contact(phonebook.get_contact_entry(entry, index));
	
	std::cin.clear();
	std::cin.ignore();
}

Contact		PhoneBook::get_contact_entry(PhoneBook phonebook, Contact entry, int index)
{
	return (phonebook.entry[index]);
}
// Contact		PhoneBook::add_contact_entry(Contact entry int index)
// {
// 	return (phonebook.entry)
// }

int	main(void)
{
	std::string	input;
	PhoneBook	phonebook;
	Contact		contact;
	int			entry_count = -1;

	while (1)
	{
		std::cin >> input;
		if (input == "EXIT" || input == "exit")
			return (0);
		if (input == "ADD" || input == "add")
			phonebook.entry[++entry_count] = contact.create_contact(contact);
		if (input == "SEARCH" || input == "search")
			phonebook.display_contacts(phonebook);
		if (entry_count == 7)
			entry_count = -1;
		// entry_count %= 7;
	}
	return (0);
}
