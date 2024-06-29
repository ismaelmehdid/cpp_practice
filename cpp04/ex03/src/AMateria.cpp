#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"

#include <string>
#include <iostream>

AMateria::AMateria() : _type("undefined_type") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria &toCopy) : _type(toCopy._type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &toCopy)
{
	if (this != &toCopy) {
		_type = toCopy._type;
	}
	return *this;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* using " << _type << " on " << target.getName() << " *" << std::endl;
}
