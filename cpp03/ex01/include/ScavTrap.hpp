#ifndef ScavTrap_Hpp
#define ScavTrap_Hpp

#include "ClapTrap.hpp"

#include <string>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap &toCopy);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void getStatus() const;
		void guardGate();
		ScavTrap &operator=(const ScavTrap &toCopy);
	private:
		bool _gateMode;
};

#endif