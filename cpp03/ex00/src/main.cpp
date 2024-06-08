#include "../include/ClapTrap.hpp"

#include <iostream>

int main(void)
{
	std::cout << "=====---------------------------------------=====" << std::endl;
	std::cout << "=====------------ Energy tests -------------=====" << std::endl;
	std::cout << "=====---------------------------------------=====" << std::endl;
	{
		ClapTrap bob("bob");
		for (int i = 0; i < 10; i++)
			bob.attack("gerard");
		bob.attack("cat");
		bob.getStatus();
	}
	std::cout << "=====---------------------------------------=====" << std::endl;
	std::cout << "=====-------------- Hp tests ---------------=====" << std::endl;
	std::cout << "=====---------------------------------------=====" << std::endl;
	{
		ClapTrap bob("bob");
		bob.takeDamage(2);
		bob.takeDamage(99);
		bob.getStatus();
		bob.attack("cat");
		bob.attack("cat");
		bob.attack("cat");
		bob.beRepaired(9999);
		bob.attack("cat");
	}
	return 0;
}