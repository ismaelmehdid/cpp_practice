#include "../include/Fixed.hpp"

#include <iostream>

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const Fixed &toCopy)
{
	std::cout << "Copy constructor called" << '\n';
	*this = toCopy;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << '\n';
	fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << '\n';
	float scaledValue = value * (1 << fractionalBits); //can't bitshift with float so *256
    fixedPointValue = static_cast<int32_t>(std::roundf(scaledValue));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << '\n';
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << '\n';
	return (fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << '\n';
	fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixedPointValue) / (1 << fractionalBits)); //reverse process
}

int Fixed::toInt(void) const
{
	return (fixedPointValue >> fractionalBits);
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << '\n';
	fixedPointValue = fixed.fixedPointValue;
	return *this;
}
