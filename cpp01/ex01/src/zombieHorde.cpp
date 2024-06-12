#include "../include/Zombie.hpp"

#include <iostream>
#include <string>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombieArray = 0;
	try {
		zombieArray = new Zombie[N]; // allocate memory to store N zombies and call the default constructor for every zombies
		for (int i = 0; i < N; i++)
			zombieArray[i].setName(name);
	} catch (std::bad_alloc &bad_alloc){
		std::cerr << "Memory allocation failure: " << bad_alloc.what() << '\n';
		return 0;
	}
	return zombieArray;
}
