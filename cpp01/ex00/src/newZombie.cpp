#include "../include/Zombie.hpp"

#include <string>

Zombie*	newZombie( std::string name )
{
	return (new (std::nothrow) Zombie(name)); // don't throw an exception if an allocation fail
}