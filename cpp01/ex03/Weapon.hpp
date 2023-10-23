#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <unistd.h>

class	Weapon
{
	private :
		std::string	type;
	
	public :
		const std::string	&getType(void);
		void				setType(std::string type);
};

#endif