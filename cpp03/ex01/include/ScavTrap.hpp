#ifndef ScavTrap_Hpp
#define ScavTrap_Hpp

#include "ClapTrap.hpp"

#include <string>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		~ScavTrap();
		void attack(const std::string& target);
		void getStatus() const;
		void guardGate() const;
};

#endif