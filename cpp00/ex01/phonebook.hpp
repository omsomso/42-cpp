#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>

class	Contact
{
	public :

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

class	PhoneBook
{
	public :

	Contact entry[8];
};

Contact		add_contact(void);
std::string	fix_lenght(std::string s);
int			display_contacts(PhoneBook phonebook);
void		search_contacts(PhoneBook phonebook);

#endif