#ifndef Fixed_hpp
#define Fixed_hpp

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &toCopy);
		Fixed(const int value);
		Fixed(const float value);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed &operator=(const Fixed &fixed);

	private:
		int32_t fixedPointValue;
		static const int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif