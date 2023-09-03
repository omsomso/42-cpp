#include "phonebook.hpp"

// using namespace std;

Contact	add_contact(void)
{
	std::string	input;
	Contact	entry;

	std::cout << "Input First Name : " << std::endl;
	std::cin >> input;
	entry.first_name = input;
	std::cout << "Input Last Name : " << std::endl;
	std::cin >> input;
	entry.last_name = input;
	std::cout << "Input Nickname : " << std::endl;
	std::cin >> input;
	entry.nickname = input;
	std::cout << "Input Phone Number : " << std::endl;
	std::cin >> input;
	entry.phone_number = input;
	std::cout << "Input Darkest Secret : " << std::endl;
	std::cin >> input;
	entry.darkest_secret = input;
	return (entry);
}

std::string	fix_lenght(std::string s)
{
	if (s.length() > 10)
	{
		s.resize(9);
		s.append(".");
	}
	return (s);
}

int	display_contacts(PhoneBook phonebook)
{
	int		idx = 0;
	std::string	input;

	if (phonebook.entry[0].first_name.length() == 0)
	{
		std::cout << "No contacts" << std::endl;
		return (1);
	}
	while (idx < 8 && phonebook.entry[idx].first_name.length() > 0)
	{
		// setiosflags(ios::left);
		std::cout << std::setw(10) << "index" << "|" << std::setw(10) <<  "first name";
		std::cout << "|" << std::setw(10) <<  "last name";
		std::cout << "|" << std::setw(10) <<  "nickname" << std::endl;

		std::cout << std::setw(10) << idx << "|";
		std::cout << std::setw(10) << fix_lenght(phonebook.entry[idx].first_name);
		std::cout << "|" << std::setw(10) << fix_lenght(phonebook.entry[idx].last_name);
		std::cout << "|" << std::setw(10) << fix_lenght(phonebook.entry[idx].nickname) << std::endl;
		idx++;
	}
	return (0);
}

void	search_contacts(PhoneBook phonebook)
{
	int		idx = 0;
	std::string	input;

	if (display_contacts(phonebook))
		return ;
	std::cout << "Input index : " << std::endl;
	std::cin >> input;
	if (!all_of(input.begin(), input.end(), ::isdigit))
	{
		std::cout << "Wrong index" << std::endl;
		return ;
	}
	idx = stoi(input);
	if (input.length() > 1 || input[0] < '0' || input[0] > '7')
		std::cout << "Wrong index" << std::endl;
	else if (phonebook.entry[idx].first_name.length() == 0)
		std::cout << "Wrong index" << std::endl;
	else
	{
		std::cout << "First Name : " << phonebook.entry[idx].first_name << std::endl;
		std::cout << "Last Name : " << phonebook.entry[idx].last_name << std::endl;
		std::cout << "Nickname : " << phonebook.entry[idx].nickname << std::endl;
		std::cout << "Phone Number : " << phonebook.entry[idx].phone_number << std::endl;
		std::cout << "Darkest Secret : " << phonebook.entry[idx].darkest_secret << std::endl;
	}
}

int	main(void)
{
	std::string	input;
	PhoneBook	phonebook;
	int			entry_count = -1;

	while (1)
	{
		std::cin >> input;
		if (input == "exit")
			return (0);
		if (input == "add")
			phonebook.entry[++entry_count] = add_contact();
		if (input == "search")
			search_contacts(phonebook);
		if (entry_count == 7)
			entry_count = -1;
	}
	return (0);
}
