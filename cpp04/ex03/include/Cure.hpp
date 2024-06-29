#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure &toCopy);
		Cure &operator=(const Cure &toCopy);
		Cure* clone() const;
		void use(ICharacter& target);
};