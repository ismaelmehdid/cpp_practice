#include "../include/Character.hpp"
#include "../include/AMateria.hpp"

#include <iostream>

Character::Character() : _name("undefined_name")
{
	for (int i = 0; i < INVENTORY_SLOTS; i++) {
		_inventory[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < INVENTORY_SLOTS; i++) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < INVENTORY_SLOTS; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(const Character &toCopy) : _name(toCopy._name)
{
	if (this != &toCopy){
		for (int i = 0; i < INVENTORY_SLOTS; i++) {
			if (toCopy._inventory[i] != NULL) {
				_inventory[i] = toCopy._inventory[i]->clone();
			} else {
				_inventory[i] = NULL;
			}
		}
	}
}

Character &Character::operator=(const Character &toCopy)
{
	if (this != &toCopy) {
		for (int i = 0; i < INVENTORY_SLOTS; i++) {
			if (_inventory[i] != NULL) {
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (toCopy._inventory[i] != NULL) {
				_inventory[i] = toCopy._inventory[i]->clone();
			}
		}
		_name = toCopy._name;
	}
	return *this;
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	int i = 0;
	
	while (i < INVENTORY_SLOTS) {
		if (_inventory[i] == m) {
			std::cout << "Item already equipped!" << std::endl;
			return ;
		}
		i++;
	}
	i = 0;
	while (i < INVENTORY_SLOTS) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return ;
		}
		i++;
	}
	std::cout << "Couldn't equip item of type " << m->getType() << " because no slots are availible." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= INVENTORY_SLOTS || idx < 0) {
		std::cout << "Slot index doesn't exist!" << std::endl;
	} else if (_inventory[idx] == NULL) {
		std::cout << "Nothing to unequip at index " << idx << "!" << std::endl;
	} else {
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < INVENTORY_SLOTS && idx >= 0 && _inventory[idx] != NULL) {
		_inventory[idx]->use(target);
	} else {
		std::cout << "No item to use at index " << idx << "!" << std::endl;
	}
}
