#include "../include/Cat.hpp"

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
	*this = cat;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << '\n';
}

Cat &Cat::operator=(const Cat &cat)
{
	type = cat.type;
	return *this;
}
