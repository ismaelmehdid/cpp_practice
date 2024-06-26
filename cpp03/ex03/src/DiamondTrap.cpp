#include <iostream>

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap(), m_name("undefined_name")
{
	ClapTrap::m_name = "undefined_name";
	m_hp = FragTrap::m_hp;
	m_energy = ScavTrap::m_energy;
	m_attackDamages = FragTrap::m_attackDamages;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name), m_name(name)
{
	std::cout << "A new DiamondTrap named " << m_name << " spawned!" << '\n';
	this->ClapTrap::m_name = name + "_clap_name";
	m_hp = FragTrap::m_hp;
	m_energy = ScavTrap::m_energy;
	m_attackDamages = FragTrap::m_attackDamages;
}

DiamondTrap::DiamondTrap(const DiamondTrap &toCopy) : FragTrap(toCopy), ScavTrap(toCopy), m_name(toCopy.m_name)
{
	if (this != &toCopy) {
		this->ClapTrap::m_name = toCopy.ClapTrap::m_name;
	}
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap named " << m_name << " left the game!" << '\n';
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &toCopy)
{
	if (this != &toCopy) {
		FragTrap::operator=(toCopy);
		ScavTrap::operator=(toCopy);
		m_name = toCopy.m_name;
		this->ClapTrap::m_name = toCopy.ClapTrap::m_name;
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (amount > (unsigned int)m_hp)
		std::cout << "FragTrap " << m_name << " lost " << m_hp << " hp!" << '\n';
	else
		std::cout << "FragTrap " << m_name << " lost " << amount << " hp!" << '\n';
	m_hp -= amount;
	if (m_hp < 0)
		m_hp = 0;
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (m_energy == 0)
	{
		std::cout << "You are too tired!" << '\n';
		return ;
	}
	if (amount + m_hp > 100)
		std::cout << "DiamondTrap " << m_name << " got repaired and gained " << 100 - m_hp << " hp" << '\n';
	else
		std::cout << "DiamondTrap " << m_name << " got repaired and gained " << amount << " hp" << '\n';
	m_energy--;
	m_hp += amount;
	if (m_hp > 100)
	{
		m_hp = 100;
	}
}

void DiamondTrap::getStatus() const
{
	std::cout << "------------------" << '\n';
	std::cout << "DiamondTrap " << m_name << ":" << '\n';
	std::cout << "HP: " << m_hp << '\n';
	std::cout << "Energy: " << m_energy << '\n';
	std::cout << "Attack damages: " << m_attackDamages << '\n';
	std::cout << "------------------" << '\n';
}

void DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is " << m_name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::m_name << std::endl;
}
