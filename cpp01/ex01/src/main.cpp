#include "../include/Zombie.hpp"

#include <string>
#include <iostream>

int main(void)
{
	std::cout << "=====---------------------------------------=====" << std::endl;
	std::cout << "=====------------ Zombie Horde -------------=====" << std::endl;
	std::cout << "=====---------------------------------------=====" << std::endl;

	int nbrOfZombies = 10;
	Zombie *zombieArray = zombieHorde(nbrOfZombies, "foo");
	if (zombieArray != 0)
	{
		for (int i = 0; i < nbrOfZombies; i++)
		{
			std::cout << i + 1 << ": ";
			zombieArray[i].announce();
		}
		delete[] zombieArray; // call destructors on all zombies slots and free the memory of the array
		zombieArray = 0;
	}
	return 0;
}