#include "../include/AMateria.hpp"
#include "../include/Character.hpp"
#include "../include/Cure.hpp"
#include "../include/Ice.hpp"
#include "../include/ICharacter.hpp"
#include "../include/IMateriaSource.hpp"
#include "../include/MateriaSource.hpp"

#include <iostream>

int main()
{
	std::cout << "====------------SUBJECT TESTS------------====" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	std::cout << "====--------------MY TESTS---------------====" << std::endl;
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice()); // no space left test
		src->learnMateria(NULL); // null ptr test
		src->createMateria("??"); // unrecognized materia type

		ICharacter *me = new Character("me");
		me->equip(NULL);

		ICharacter *bob = new Character("bob");
		me->use(0, *bob);

		AMateria *ice = new Ice();
		AMateria *cure = new Cure();

		me->equip(ice);
		me->equip(cure);
		me->equip(cure);
		me->equip(cure);
		me->equip(cure); // already equipped

		std::cout << std::endl;
		std::cout << "Copy tests:" << std::endl;

		AMateria *cureCpy = new Cure();
		Character toCopy = Character("toCopy"); 
		toCopy.equip(cureCpy);
		Character newCopy = toCopy;// = overload
		std::cout << newCopy.getName() << std::endl;
		newCopy.use(0, *bob);

		AMateria *iceCpy = new Ice();
		Character bob2 = Character("bob2"); 
		bob2.equip(iceCpy);
		Character copyBob2 = Character(bob2);// copy constructor
		std::cout << copyBob2.getName() << std::endl;
		copyBob2.use(0, bob2);
		
		
		delete bob;
		delete me;
		delete src;
	}
	return 0;
}