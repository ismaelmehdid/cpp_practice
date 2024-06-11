#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

#include <iostream>

#define NBR_OF_ANIMALS 10

int main()
{
	Animal *animals[NBR_OF_ANIMALS];

	for (int i = 0; i < NBR_OF_ANIMALS; i++)
	{
		if (i < NBR_OF_ANIMALS / 2)
		{
			animals[i] = new Dog();
		}
		else
		{
			animals[i] = new Cat();
		}
	}

	std::cout << '\n';

	for (int i = 0; i < NBR_OF_ANIMALS; i++)
	{
		delete animals[i];
	}

	std::cout << '\n';

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; //should not create a leak
	delete i;

	std::cout << '\n';

	Dog basic;
	{
		Dog tmp = basic;
	}

	return 0;
}