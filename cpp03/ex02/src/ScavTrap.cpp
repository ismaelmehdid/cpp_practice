#include "../include/ScavTrap.hpp"

#include <string>
#include <iostream>
		
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "A new ScavTrap named " << name << " spawned!" << '\n';
	m_hp = 100;
	m_energy = 50;
	m_attackDamages = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap named " << m_name << " left the game!" << '\n';
}

void ScavTrap::attack(const std::string& target)
{
	if (m_hp == 0)
	{
		std::cout << "You are dead :(" << '\n';
		return ;
	}
	if (m_energy == 0)
	{
		std::cout << "You are too tired!" << '\n';
		return ;
	}
	m_energy--;
	std::cout << "ScavTrap " << m_name << " attacks " << target << ", causing " << m_attackDamages << " points of damage!" << '\n';
}

void ScavTrap::getStatus() const
{
	std::cout << "------------------" << '\n';
	std::cout << "ScavTrap " << m_name << ":" << '\n';
	std::cout << "HP: " << m_hp << '\n';
	std::cout << "Energy: " << m_energy << '\n';
	std::cout << "Attack damages: " << m_attackDamages << '\n';
	std::cout << "------------------" << '\n';
}

void ScavTrap::guardGate() const
{
	std::cout << "ScavTrap " << m_name << " is now in Gate keeper mode" << '\n';
}