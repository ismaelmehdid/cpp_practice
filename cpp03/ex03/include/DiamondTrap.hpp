#pragma once

#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &toCopy);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &toCopy);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void getStatus() const;
		void whoAmI();
	private:
		std::string m_name;
};