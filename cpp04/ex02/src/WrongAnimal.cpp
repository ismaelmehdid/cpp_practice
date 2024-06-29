#include "../include/WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "An wrong animal has been created." << '\n'; 
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "An wrong animal has been destroyed." << '\n'; 
}

WrongAnimal::WrongAnimal(const std::string &custom_type) : type(custom_type)
{
	std::cout << "An wrong animal has been created." << '\n'; 
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "??" << '\n';
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrong_animal)
{
	if (this != &wrong_animal) {
		*this = wrong_animal;
	}
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrong_animal)
{
	if (this != &wrong_animal) {
		type = wrong_animal.type;
	}
	return *this;
}
