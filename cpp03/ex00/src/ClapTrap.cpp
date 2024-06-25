#include "../include/ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(std::string name) : m_name(name), m_hp(10), m_energy(10), m_attackDamages(0)
{
	std::cout << "A new ClapTrap named " << name << " spawned!" << '\n';
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap named " << m_name << " left the game!" << '\n';
}

ClapTrap::ClapTrap(const ClapTrap &toCopy) : m_name(toCopy.m_name), m_hp(toCopy.m_hp), m_energy(toCopy.m_energy), m_attackDamages(toCopy.m_attackDamages)
{

}

ClapTrap &ClapTrap::operator=(const ClapTrap &toCopy)
{
	if (&toCopy == this)
	{
		return *this;
	}
	m_name = toCopy.m_name;
	m_hp = toCopy.m_hp;
	m_energy = toCopy.m_energy;
	m_attackDamages = toCopy.m_attackDamages;
	return *this;
}

void ClapTrap::attack(const std::string& target)
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
	std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_attackDamages << " points of damage!" << '\n';
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > (unsigned int)m_hp)
		std::cout << "ClapTrap " << m_name << " lost " << m_hp << " hp!" << '\n';
	else
		std::cout << "ClapTrap " << m_name << " lost " << amount << " hp!" << '\n';
	m_hp -= amount;
	if (m_hp < 0)
		m_hp = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (m_energy == 0)
	{
		std::cout << "You are too tired!" << '\n';
		return ;
	}
	if (amount + m_hp > 100)
		std::cout << "ClapTrap " << m_name << " got repaired and gained " << 100 - m_hp << " hp" << '\n';
	else
		std::cout << "ClapTrap " << m_name << " got repaired and gained " << amount << " hp" << '\n';
	m_energy--;
	m_hp += amount;
	if (m_hp > 100)
	{
		m_hp = 100;
	}
}

void ClapTrap::getStatus() const
{
	std::cout << "------------------" << '\n';
	std::cout << "ClapTrap " << m_name << ":" << '\n';
	std::cout << "HP: " << m_hp << '\n';
	std::cout << "Energy: " << m_energy << '\n';
	std::cout << "Attack damages: " << m_attackDamages << '\n';
	std::cout << "------------------" << '\n';
}