#include "../include/Dog.hpp"
#include "../include/Animal.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "A Dog has been created." << '\n';
}

Dog::~Dog()
{
	std::cout << "A Dog has been destroyed." << '\n';
}

Dog::Dog(const Dog &dog)
{
	(void)dog;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << '\n';
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this != &dog)
		Animal::operator=(dog);
	return *this;
}
