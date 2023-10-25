#include "contact.hpp"
#include "phonebook.hpp"

std::string	Contact::get_first_name() {
	return (this->first_name);
}

std::string Contact::get_last_name() {
	return (this->last_name);
}

std::string Contact::get_nickname() {
	return (this->nickname);
}

std::string Contact::get_phone_number() {
	return (this->phone_number);
}

std::string Contact::get_darkest_secret() {
	return (this->darkest_secret);
}

bool	Contact::str_isspace(std::string input)
{
	int i = 0;
	int count = 0;
	int n = input.length();

	while (i < n)
	{
		if (std::isspace(input[i]) == 1)
			count++;
		i++;
	}
	if (count == n)
		return (1);
	return(0);
}

// check if input string isn't empty or isn't only whitespaces
int		Contact::check_validity(std::string input)
{
	if (input.length() == 0)
	{
		std::cout << "Error : Field can't be left empty!" << std::endl;
		return (1);
	}
	else if (str_isspace(input))
	{
		std::cout << "Error : Field can't be left empty!" << std::endl;
		return (1);
	}
	return (0);
}

// ask user to input contact and add it to the memory
void	Contact::create_contact()
{
	std::cin.clear();
	std::cin.ignore();

	do	{
		std::cout << "Enter first name : ";
		std::getline(std::cin, this->first_name);
	}
	while (this->check_validity(this->first_name) == 1);
	do	{
		std::cout << "Enter last name : ";
		std::getline(std::cin, this->last_name);
	}
	while (this->check_validity(this->last_name) == 1);
	do	{
		std::cout << "Enter nickname : ";
		std::getline(std::cin, this->nickname);
	}
	while (this->check_validity(this->nickname) == 1);
	do	{
		std::cout << "Enter phone number : ";
		std::getline(std::cin, this->phone_number);
	}
	while (this->check_validity(this->phone_number) == 1);
	do	{
		std::cout << "Enter darkest secret : ";
		std::getline(std::cin, this->darkest_secret);
	}
	while (this->check_validity(this->darkest_secret) == 1);
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
void	Contact::display_contact()
{
	std::cout << "First Name\t: " << this->get_first_name() << std::endl;
	std::cout << "Last Name\t: " << this->get_last_name() << std::endl;
	std::cout << "Nickname\t: " << this->get_nickname() << std::endl;
	std::cout << "Phone Number\t: " << this->get_phone_number() << std::endl;
	std::cout << "Darkest Secret\t: " << this->get_darkest_secret() << std::endl;
}

// displays preview info for a contact
int	Contact::display_contact_preview(int index)
{
	std::string	tmp;

	// check if contact exists
	tmp = this->get_first_name();
	if (tmp.length() == 0)
		return (1);
	
	// display contact
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << this->fix_lenght(this->get_first_name());
	std::cout << "|" << std::setw(10) << this->fix_lenght(this->get_last_name());
	std::cout << "|" << std::setw(10) << this->fix_lenght(this->get_nickname()) << std::endl;

	return (0);
}
