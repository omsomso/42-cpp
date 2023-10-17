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

	Contact		create_contact(Contact entry);
	int			display_contact_preview(Contact entry,  int index);
	int			display_contact(Contact entry);
	int			check_validity(std::string input);
	std::string	fix_lenght(std::string s);
};

class	PhoneBook
{
	private :
	Contact		entry[8];

	public :
	Contact		get_contact_entry(Contact entry, int index);
	Contact		add_contact_entry(Contact entry int index);
	void		display_contacts(PhoneBook phonebook);
};

#endif