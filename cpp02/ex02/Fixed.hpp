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
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		~Fixed();

		Fixed&	operator=(const Fixed &other);
		Fixed	operator+(const Fixed &other);
		Fixed	operator-(const Fixed &other);
		Fixed	operator*(const Fixed &other);
		Fixed	operator/(const Fixed &other);
		Fixed	operator++(int);
		Fixed&	operator++();
		bool	operator>(const Fixed &other);
		bool	operator>=(const Fixed &other);
		bool	operator<(const Fixed &other);
		bool	operator<=(const Fixed &other);
		bool	operator!=(const Fixed &other);

		static Fixed&		min(Fixed &one, Fixed &two);
		static Fixed&		max(Fixed &one, Fixed &two);
		static const Fixed&	min(const Fixed &one, const Fixed &two);
		static const Fixed&	max(const Fixed &one, const Fixed &two);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream &operator << (std::ostream& str, const Fixed& number);

#endif