#pragma once

#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(std::string const & type); 
		AMateria(const AMateria &toCopy);
		virtual ~AMateria();
		AMateria &operator=(const AMateria &toCopy);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
