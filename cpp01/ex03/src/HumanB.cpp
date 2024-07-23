#include "../include/HumanB.hpp"

#include <string>
#include <iostream>

HumanB::HumanB(std::string name) : m_name(name), m_weapon(0) {}
HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
	m_weapon = &weapon;
}

void HumanB::attack() const
{
	if (m_weapon == 0)
	{
		std::cout << m_name << " has no weapon to attack with" << std::endl;
		return ;
	}
	std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
}