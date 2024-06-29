#include "../include/Animal.hpp"

#include <iostream>

Animal::Animal() : type("Animal")
{
	std::cout << "An animal has been created." << '\n';
}

Animal::~Animal()
{
	std::cout << "An animal has been destroyed." << '\n'; 
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
	if (this != &animal) {
		*this = animal;
	}
}

Animal &Animal::operator=(const Animal &animal)
{
	if (this != &animal) {
		type = animal.type;
	}
	return *this;
}
