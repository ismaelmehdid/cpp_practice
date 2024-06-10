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
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	for (int i = 0; i < NBR_IDEAS; i++)
	{
		ideas[i] = brain.ideas[i];
	}
	return *this;
}
