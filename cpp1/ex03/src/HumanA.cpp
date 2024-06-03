#include "../include/HumanA.hpp"

#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : m_name(name), m_weapon(weapon) {}
HumanA::~HumanA() {}

void HumanA::attack() const
{
	std::cout << m_name << " attacks with their " << m_weapon.getType() << std::endl;
}