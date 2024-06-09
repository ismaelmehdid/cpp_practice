#include "../include/HumanA.hpp"
#include "../include/HumanB.hpp"
#include "../include/Weapon.hpp"

#include <iostream>
#include <string>

int main( void )
{
	{
		// reference so it's mandatory for the HumanA to have a weapon
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		// pointer so it's not mandatory for the HumanB to have a weapon
		// (either have one, or weapon object pointer set to 'nullptr')
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
