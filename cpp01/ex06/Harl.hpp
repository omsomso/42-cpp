#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	private :
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	public :
	void complain(int level);
	int find_level(std::string level);
};

enum e_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

#endif