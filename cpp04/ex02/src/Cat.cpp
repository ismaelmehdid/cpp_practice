#include "../include/Cat.hpp"
#include "../include/Animal.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "A cat has been created." << '\n';
	brain = new Brain();
}

Cat::~Cat()
{
	delete brain;
	std::cout << "A cat has been destroyed." << '\n';
}

Cat::Cat(const Cat &cat)
{
	if (this != &cat) {
		brain = new Brain(*cat.brain);
		type = cat.type;
	}
}

void Cat::makeSound() const
{
	std::cout << "Meow" << '\n';
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this == &cat)
		return *this;
	
	delete brain;

	brain = new Brain(*cat.brain);
	type = cat.type;

	return *this;
}

void Cat::printBrainAddr() const
{
	std::cout << brain << std::endl;
}
