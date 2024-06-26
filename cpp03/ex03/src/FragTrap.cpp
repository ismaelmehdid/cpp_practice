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

}

FragTrap &FragTrap::operator=(const FragTrap &toCopy)
{
	if (this == &toCopy) {
		return *this;
	}
	this->ClapTrap::operator=(toCopy);
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

void FragTrap::takeDamage(unsigned int amount)
{
	if (amount > (unsigned int)m_hp)
		std::cout << "FragTrap " << m_name << " lost " << m_hp << " hp!" << '\n';
	else
		std::cout << "FragTrap " << m_name << " lost " << amount << " hp!" << '\n';
	m_hp -= amount;
	if (m_hp < 0)
		m_hp = 0;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (m_energy == 0)
	{
		std::cout << "You are too tired!" << '\n';
		return ;
	}
	if (amount + m_hp > 100)
		std::cout << "FragTrap " << m_name << " got repaired and gained " << 100 - m_hp << " hp" << '\n';
	else
		std::cout << "FragTrap " << m_name << " got repaired and gained " << amount << " hp" << '\n';
	m_energy--;
	m_hp += amount;
	if (m_hp > 100)
	{
		m_hp = 100;
	}
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
