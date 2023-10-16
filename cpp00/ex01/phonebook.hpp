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
	Contact		access_contact(Contact entry);
	std::string	fix_lenght(std::string s);
	int			diplay_contact(Contact entry, int index);
	Contact		save_contact(Contact entry);
};

class	PhoneBook
{
	public :
	Contact		entry[8];
	void		display_contacts(PhoneBook phonebook);
	// void		search_contacts(PhoneBook phonebook);
	Contact		add_contact(Contact entry);
};

#endif