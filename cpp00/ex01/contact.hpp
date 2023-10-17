#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
// # include "phonebook.hpp"

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

	void		create_contact();
	int			display_contact_preview(int index);
	void		display_contact();
	int			check_validity(std::string input);
	std::string	fix_lenght(std::string s);
};

#endif
