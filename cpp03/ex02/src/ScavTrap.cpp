#include "../include/ScavTrap.hpp"

#include <string>
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	m_hp = 100;
	m_energy = 50;
	m_attackDamages = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "A new ScavTrap named " << name << " spawned!" << '\n';
	m_hp = 100;
	m_energy = 50;
	m_attackDamages = 20;
	_gateMode = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap named " << m_name << " left the game!" << '\n';
}

ScavTrap::ScavTrap(const ScavTrap &toCopy) : ClapTrap(toCopy)
{

}

ScavTrap &ScavTrap::operator=(const ScavTrap &toCopy)
{
	if (this == &toCopy) {
		return *this;
	}
	ClapTrap::operator=(toCopy);
	_gateMode = toCopy._gateMode;
	return *this;
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

void ScavTrap::takeDamage(unsigned int amount)
{
	if (amount > (unsigned int)m_hp)
		std::cout << "ScavTrap " << m_name << " lost " << m_hp << " hp!" << '\n';
	else
		std::cout << "ScavTrap " << m_name << " lost " << amount << " hp!" << '\n';
	m_hp -= amount;
	if (m_hp < 0)
		m_hp = 0;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (m_energy == 0)
	{
		std::cout << "You are too tired!" << '\n';
		return ;
	}
	if (amount + m_hp > 100)
		std::cout << "ScavTrap " << m_name << " got repaired and gained " << 100 - m_hp << " hp" << '\n';
	else
		std::cout << "ScavTrap " << m_name << " got repaired and gained " << amount << " hp" << '\n';
	m_energy--;
	m_hp += amount;
	if (m_hp > 100)
	{
		m_hp = 100;
	}
}

void ScavTrap::getStatus() const
{
	std::cout << "------------------" << '\n';
	std::cout << "ScavTrap " << m_name << ":" << '\n';
	std::cout << "HP: " << m_hp << '\n';
	std::cout << "Energy: " << m_energy << '\n';
	std::cout << "Attack damages: " << m_attackDamages << '\n';
	std::cout << "Gate Keeper Mode : " << (_gateMode ? "On" : "Off") << std::endl;
	std::cout << "------------------" << '\n';
}

void ScavTrap::guardGate()
{
	_gateMode = !_gateMode;
	if (_gateMode) {
		std::cout << "ScavTrap " << m_name << " is now in Gate keeper mode" << '\n';
	}
	else {
		std::cout << "ScavTrap " << m_name << " is no longer in Gate keeper mode" << '\n';
	}
}
