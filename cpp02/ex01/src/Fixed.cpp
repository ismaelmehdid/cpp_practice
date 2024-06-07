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
	fixedPointValue = value << fractionalBits; // converting int to FP nbr, we shift all bits to the right so we leave space for the decimal part
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << '\n';
	float scaledValue = value * (1 << fractionalBits); // moving fractional bits from the decimal part to the whole number part
    fixedPointValue = static_cast<int>(std::roundf(scaledValue)); //rouding up the value and casting it to int to store it in fixedpointvalue which is an int
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

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << '\n';
	fixedPointValue = fixed.fixedPointValue;
	return *this;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixedPointValue) / (1 << fractionalBits)); // reverting the process of converting float to FP nbr, moving the bits from the whole number part to the decimal part
}

int Fixed::toInt(void) const
{
	return (fixedPointValue >> fractionalBits); // invert the process of int to FP convertion, we bitshift all bits to the right 
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat(); // converting the fixed point to float and puting the result in the output stream passed in parameter
	return os;
}