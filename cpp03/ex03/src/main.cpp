#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

#include <iostream>

int main(void)
{
	std::cout << "=====---------------ClapTrap----------------=====" << std::endl;
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


	std::cout << "=====---------------ScavTrap----------------=====" << std::endl;
	std::cout << "=====---------------------------------------=====" << std::endl;
	std::cout << "=====------------ Energy tests -------------=====" << std::endl;
	std::cout << "=====---------------------------------------=====" << std::endl;
	{
		ScavTrap bob("bob");
		for (int i = 0; i < 50; i++)
			bob.attack("gerard");
		bob.attack("cat");
		bob.getStatus();
	}
	std::cout << "=====---------------------------------------=====" << std::endl;
	std::cout << "=====-------------- Hp tests ---------------=====" << std::endl;
	std::cout << "=====---------------------------------------=====" << std::endl;
	{
		ScavTrap bob("bob");
		bob.takeDamage(2);
		bob.takeDamage(99);
		bob.getStatus();
		bob.attack("cat");
		bob.attack("cat");
		bob.attack("cat");
		bob.beRepaired(9999);
		bob.attack("cat");
		bob.guardGate();
	}
	std::cout << "=====---------------------------------------=====" << std::endl;
	std::cout << "=====------- Gate Keeper Mode Test ---------=====" << std::endl;
	std::cout << "=====---------------------------------------=====" << std::endl;
	{
		ScavTrap bob("bob");
		bob.guardGate();
		bob.guardGate();
		bob.guardGate();
		bob.getStatus();
	}
	std::cout << "=====---------------FragTrap----------------=====" << std::endl;
	std::cout << "=====---------------------------------------=====" << std::endl;
	std::cout << "=====------------ Energy tests -------------=====" << std::endl;
	std::cout << "=====---------------------------------------=====" << std::endl;
	{
		FragTrap bob("bob");
		for (int i = 0; i < 100; i++)
			bob.attack("gerard");
		bob.attack("cat");
		bob.getStatus();
	}
	std::cout << "=====---------------------------------------=====" << std::endl;
	std::cout << "=====-------------- Hp tests ---------------=====" << std::endl;
	std::cout << "=====---------------------------------------=====" << std::endl;
	{
		FragTrap bob("bob");
		bob.takeDamage(2);
		bob.takeDamage(99);
		bob.getStatus();
		bob.attack("cat");
		bob.attack("cat");
		bob.attack("cat");
		bob.beRepaired(9999);
		bob.attack("cat");
		bob.highFivesGuys();
		bob.highFivesGuys();
		bob.highFivesGuys();
	}
	std::cout << "=====--------------DiamondTrap--------------=====" << std::endl;
	std::cout << "=====---------------------------------------=====" << std::endl;
	{
		DiamondTrap bob("bob");
		bob.getStatus();
		bob.whoAmI();
		bob.attack("dog");
	}
	return 0;
}