#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class	PhoneBook
{
	private :
	Contact		entry[8];

	public :
	PhoneBook();
	void		display_phonebook_entry(int index);
	void		add_phonebook_entry(int index);
	void		search();
	bool		str_isdigit(std::string input);

	int			entry_count;
};

#endif
