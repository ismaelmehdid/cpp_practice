#pragma once

#include "ClapTrap.hpp"

#include <string>

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap &toCopy);
		void attack(const std::string& target);
		void getStatus() const;
		void highFivesGuys(void);
		FragTrap &operator=(const FragTrap &toCopy);
};
