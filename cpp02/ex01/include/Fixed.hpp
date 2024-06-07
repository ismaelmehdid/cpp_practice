#ifndef Fixed_hpp
#define Fixed_hpp

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &toCopy);
		Fixed(const int value);
		Fixed(const float value);
		float toFloat(void) const;
		int toInt(void) const;
		Fixed &operator=(const Fixed &fixed);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int fixedPointValue;
		static const int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif