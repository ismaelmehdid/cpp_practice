#include "../include/Animal.hpp"

#include <iostream>

Animal::Animal() : type("Animal")
{
	std::cout << "An animal has been created." << '\n';
	brain = new Brain();
}

Animal::~Animal()
{
	std::cout << "An animal has been destroyed." << '\n'; 
	delete brain;
}

Animal::Animal(const std::string &custom_type) : type(custom_type)
{
	std::cout << "An animal has been created." << '\n'; 
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "??" << '\n';
}

Animal::Animal(const Animal &animal)
{
	brain = new Brain(*animal.brain);
	type = animal.type;
}

Animal &Animal::operator=(const Animal &animal)
{
	if (this == &animal) // if operator called on himself no need to copy : my_cat = my_cat
		return *this;
	
	delete brain;

	brain = new Brain(*animal.brain);

	type = animal.type;
	return *this;
}
