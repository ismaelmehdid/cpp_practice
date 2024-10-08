#include "../include/Cat.hpp"
#include "../include/Animal.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "A cat has been created." << '\n';
}

Cat::~Cat()
{
	std::cout << "A cat has been destroyed." << '\n';
}

Cat::Cat(const Cat &cat)
{
	if (this != &cat) {
		*this = cat;
		std::cout << "A cat has been created." << '\n';
	}
}

void Cat::makeSound() const
{
	std::cout << "Meow" << '\n';
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this != &cat) {
		type = cat.type;
	}
	return *this;
}
