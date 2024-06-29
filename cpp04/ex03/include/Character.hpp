#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define INVENTORY_SLOTS 4

class Character : public ICharacter
{
	public:
		Character();
		~Character();
		Character(const std::string &name);
		Character(const Character &toCopy);
		Character &operator=(const Character &toCopy);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	private:
		std::string _name;
		AMateria *_inventory[INVENTORY_SLOTS];
};
