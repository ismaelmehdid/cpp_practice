#include "../include/FragTrap.hpp"

#include <iostream>
#include <string>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "A new FragTrap named " << name << " spawned!" << '\n';
	m_hp = 100;
	m_energy = 100;
	m_attackDamages = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap named " << m_name << " left the game!" << '\n';
}

void FragTrap::getStatus() const
{
	std::cout << "------------------" << '\n';
	std::cout << "FragTrap " << m_name << ":" << '\n';
	std::cout << "HP: " << m_hp << '\n';
	std::cout << "Energy: " << m_energy << '\n';
	std::cout << "Attack damages: " << m_attackDamages << '\n';
	std::cout << "------------------" << '\n';
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "**high five**" << '\n';
}
