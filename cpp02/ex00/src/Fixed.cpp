#include "../include/Fixed.hpp"

#include <iostream>

Fixed::Fixed() : m_nbrValue(0)
{
	std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const Fixed &toCopy)
{
	std::cout << "Copy constructor called" << '\n';
	*this = toCopy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << '\n';
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << '\n';
	return (m_nbrValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << '\n';
	m_nbrValue = raw;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << '\n';
	m_nbrValue = fixed.m_nbrValue;
	return *this;
}
