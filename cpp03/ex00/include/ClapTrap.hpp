#pragma once

#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &toCopy);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void getStatus() const;
		ClapTrap &operator=(const ClapTrap &toCopy);
	private:
		std::string m_name;
		int m_hp;
		int m_energy;
		int m_attackDamages;
};
