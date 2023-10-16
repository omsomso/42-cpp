#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>

class	Phonebook;

class	Contact
{
	private :
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	public :
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_phone_number();
	std::string get_darkest_secret();

	Contact		access_contact(Contact entry);
	std::string	fix_lenght(std::string s);
	int			display_contact(Contact entry, int index);
	Contact		create_contact(Contact entry);
};

class	PhoneBook
{
	public :
	Contact		entry[8];
	void		display_contacts(PhoneBook phonebook);
	// void		search_contacts(PhoneBook phonebook);
	// Contact		add_contact(Contact entry);
};

#endif