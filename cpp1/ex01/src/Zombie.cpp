#include "../include/Zombie.hpp"

#include <iostream>
#include <string>

Zombie::Zombie( void ) : m_name("") {}

Zombie::~Zombie()
{
	std::cout << "Zombie " << m_name << " is dead :(" << std::endl;
}

void Zombie::setName(std::string name)
{
	m_name = name;
}

void Zombie::announce( void )
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


