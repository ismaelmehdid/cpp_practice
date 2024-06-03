#include "../include/Zombie.hpp"

#include <iostream>
#include <string>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombieArray = new Zombie[N]; // allocate memory to store N zombies and call the default constructor for every zombies
	for (int i = 0; i < N; i++)
		zombieArray[i].setName(name);
	return zombieArray;
}
