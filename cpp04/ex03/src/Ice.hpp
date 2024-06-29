#include "../include/Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &toCopy) : AMateria(toCopy) {}

Ice &Ice::operator=(const Ice &toCopy) {}

Ice *Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
