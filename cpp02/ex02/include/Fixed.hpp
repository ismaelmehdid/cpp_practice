#ifndef Fixed_hpp
#define Fixed_hpp

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &toCopy);
		Fixed(const int value);
		Fixed(const float value);
		float toFloat(void) const;
		int toInt(void) const;
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		// Operator overloads
		Fixed &operator=(const Fixed &fixed);
		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;

		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator+(const Fixed &fixed) const;
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);
	private:
		int32_t fixedPointValue;
		static const int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif