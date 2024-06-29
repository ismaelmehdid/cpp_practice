#pragma once

#include "IMateriaSource.hpp"

#define BAG_CAPACITY 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_bag[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &toCopy);
		MateriaSource &operator=(const MateriaSource &toCopy);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};