#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	private:
		int value;
		static const int bits = 8;
	
	public:
		Fixed();
		Fixed(Fixed &other);
		Fixed &operator=(Fixed &other);
		~Fixed();
	
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif