#include "../include/Dog.hpp"
#include "../include/Animal.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "A Dog has been created." << '\n';
	brain = new Brain();
}

Dog::~Dog()
{
	delete brain;
	std::cout << "A Dog has been destroyed." << '\n';
}

Dog::Dog(const Dog &dog)
{
	if (this != &dog) {
		brain = new Brain(*dog.brain);
		type = dog.type;
	}
}

void Dog::makeSound() const
{
	std::cout << "Woof" << '\n';
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this == &dog)
		return *this;
	
	delete brain;

	brain = new Brain(*dog.brain);
	type = dog.type;

	return *this;
}

void Dog::printBrainAddr() const
{
	std::cout << brain << std::endl;
}
