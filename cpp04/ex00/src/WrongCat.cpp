#include "../include/WrongCat.hpp"
#include "../include/WrongAnimal.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "A wrong cat has been created." << '\n';
}

WrongCat::~WrongCat()
{
	std::cout << "A wrong cat has been destroyed." << '\n';
}

WrongCat::WrongCat(const WrongCat &wrong_cat)
{
	if (this != &wrong_cat) {
		*this = wrong_cat;
	}
}

void WrongCat::makeSound() const
{
	std::cout << "Meow" << '\n';
}

WrongCat &WrongCat::operator=(const WrongCat &wrong_cat)
{
	if (this != &wrong_cat) {
		type = wrong_cat.type;
	}
	return *this;
}
