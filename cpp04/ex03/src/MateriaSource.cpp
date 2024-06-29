#include "../include/MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < BAG_CAPACITY; i++) {
		_bag[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < BAG_CAPACITY; i++) {
		if (_bag[i] != NULL) {
			delete _bag[i];
			_bag[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource &toCopy)
{
	if (this != &toCopy) {
		for (int i = 0; i < BAG_CAPACITY; i++) {
			if (toCopy._bag[i] != NULL) {
				_bag[i] = toCopy._bag[i];
			}
			else {
				_bag[i] = NULL;
			}
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &toCopy)
{
	if (this != &toCopy) {
		for (int i = 0; i < BAG_CAPACITY; i++) {
			if (_bag[i] != NULL) {
				_bag[i] = NULL;
			}
			if (toCopy._bag[i] != NULL) {
				_bag[i] = toCopy._bag[i];;
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m) {
		std::cout << "Materia you want to learn is empty!" << std::endl;
		return ;
	}
	for (int i = 0; i < BAG_CAPACITY; i++) {
		if (_bag[i] == NULL) {
			_bag[i] = m;
			return ;
		}
	}
	delete m;
	m = NULL;
	std::cout << "No slots left in MateriaSource couldn't learn a new Materia!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	
	while (i < BAG_CAPACITY && (_bag[i] == NULL || _bag[i]->getType() != type)) {
		i++;
	}
	if (i == BAG_CAPACITY) {
		std::cout << "No materia found of type " << type << "!" << std::endl;
	}
	else {
		return _bag[i]->clone();
	}
	return 0;
}
