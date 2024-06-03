#include "../include/HumanB.hpp"

#include <string>
#include <iostream>

HumanB::HumanB(std::string name) : m_name(name), m_weapon(nullptr) {}
HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
	m_weapon = &weapon;
}

void HumanB::attack() const
{
	std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
}