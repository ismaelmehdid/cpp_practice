#include "../include/Cure.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &toCopy) : AMateria(toCopy) {}

Cure &Cure::operator=(const Cure &toCopy) {}

Cure *Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
