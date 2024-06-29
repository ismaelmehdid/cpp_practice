#include "../include/Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &toCopy) : AMateria(toCopy) {}

Ice &Ice::operator=(const Ice &toCopy)
{
	if (this != &toCopy) {
		_type = toCopy._type;
	}
	return *this;
}

Ice *Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
