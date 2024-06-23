#include "../include/Fixed.hpp"

#include <iostream>

Fixed::Fixed() : fixedPointValue(0)
{

}

Fixed::Fixed(const Fixed &toCopy)
{
	*this = toCopy;
}

Fixed::Fixed(const int value)
{
	fixedPointValue = value << fractionalBits; 
}

Fixed::Fixed(const float value)
{
	float scaledValue = value * (1 << fractionalBits);
    fixedPointValue = static_cast<int>(std::roundf(scaledValue));
}

Fixed::~Fixed()
{

}

int Fixed::getRawBits(void) const
{
	return (fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixedPointValue) / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (fixedPointValue >> fractionalBits);
}

// Operator overloads

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	fixedPointValue = fixed.fixedPointValue;
	return *this;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return fixedPointValue > fixed.fixedPointValue;
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return fixedPointValue < fixed.fixedPointValue;
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return fixedPointValue >= fixed.fixedPointValue;
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return fixedPointValue <= fixed.fixedPointValue;
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return fixedPointValue == fixed.fixedPointValue;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return fixedPointValue != fixed.fixedPointValue;
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed res;
	int64_t temp = fixedPointValue * fixed.fixedPointValue;
	res.setRawBits(static_cast<int32_t>(temp >> fractionalBits));
	return res;
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed res;
	int64_t temp = ((static_cast<int64_t>(fixedPointValue) << fractionalBits) / fixed.fixedPointValue); // divide and convert the result to FP
	res.setRawBits(static_cast<int32_t>(temp));
	return res;
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed res;
	int64_t temp = fixedPointValue - fixed.fixedPointValue;
	res.setRawBits(static_cast<int32_t>(temp));
	return res;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed res;
	int64_t temp = fixedPointValue + fixed.fixedPointValue;
	res.setRawBits(static_cast<int32_t>(temp));
	return res;
}

Fixed &Fixed::operator++() // pres incrementation
{
	++this->fixedPointValue;
	return *this;
}

Fixed &Fixed::operator--() // pres decrementation
{
	--this->fixedPointValue;
	return *this;
}

Fixed Fixed::operator++(int) // post incrementation
{
	Fixed temp = *this;
	++this->fixedPointValue;
	return temp;
}

Fixed Fixed::operator--(int) // post decrementation
{
	Fixed temp = *this;
	--this->fixedPointValue;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
	{
		return (a);
	}
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
	{
		return (a);
	}
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}
