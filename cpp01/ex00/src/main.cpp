#include "../include/Zombie.hpp"

#include <string>
#include <iostream>

int main(void)
{
	std::cout << "=====---------------------------------------=====" << std::endl;
	std::cout << "=====------------ Stack Zombies ------------=====" << std::endl;
	std::cout << "=====---------------------------------------=====" << std::endl;

	randomChump("first");
	randomChump("second");
	randomChump("third");

	Zombie fourth = Zombie("fourth"); // scope so dead at the end of the main function
	fourth.announce();

	std::cout << "=====---------------------------------------=====" << std::endl;
	std::cout << "=====------------ Heap Zombies -------------=====" << std::endl;
	std::cout << "=====---------------------------------------=====" << std::endl;

	Zombie *foo = newZombie("foo");
	Zombie *bar = newZombie("bar");

	foo->announce();
	bar->announce();

	delete foo;
	foo = nullptr;
	delete bar;
	bar = nullptr;

	return 0;
}