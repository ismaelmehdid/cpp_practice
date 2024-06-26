#pragma once

#include "ClapTrap.hpp"

#include <string>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap &toCopy);
		void attack(const std::string& target);
		void getStatus() const;
		void guardGate();
		ScavTrap &operator=(const ScavTrap &toCopy);
	private:
		bool _gateMode;
};

