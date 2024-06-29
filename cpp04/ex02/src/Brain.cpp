#include "../include/Brain.hpp"

#include <iostream>

Brain::Brain()
{
	for (int i = 0; i < NBR_IDEAS; i++)
	{
		ideas[i] = "";
	}
	std::cout << "A brain has been created." << '\n';
}

Brain::~Brain()
{
	std::cout << "A brain has been destroyed" << '\n';
}

Brain::Brain(const Brain &brain)
{
	if (this != &brain) {
		*this = brain;
		std::cout << "A brain has been created." << '\n';
	}
}

Brain &Brain::operator=(const Brain &brain)
{
	if (this != &brain) {
		for (int i = 0; i < NBR_IDEAS; i++) {
			ideas[i] = brain.ideas[i];
		}
	}
	return *this;
}
