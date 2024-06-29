#include "../include/Cure.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &toCopy) : AMateria(toCopy) {}

Cure &Cure::operator=(const Cure &toCopy)
{
	if (this != &toCopy) {
		_type = toCopy._type;
	}
	return *this;
}

Cure *Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
