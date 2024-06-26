#include "../include/FragTrap.hpp"

#include <iostream>
#include <string>

FragTrap::FragTrap() : ClapTrap()
{
	m_hp = 100;
	m_energy = 100;
	m_attackDamages = 30;
}

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

FragTrap::FragTrap(const FragTrap &toCopy) : ClapTrap(toCopy)
{
	std::cout << "A new FragTrap named " << m_name << " spawned!" << '\n';
}

FragTrap &FragTrap::operator=(const FragTrap &toCopy)
{
	if (this != &toCopy) {
		this->ClapTrap::operator=(toCopy);	
	}
	return *this;
}

void FragTrap::attack(const std::string& target)
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
	std::cout << "FragTrap " << m_name << " attacks " << target << ", causing " << m_attackDamages << " points of damage!" << '\n';
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
