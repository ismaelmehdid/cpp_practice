#ifndef ScavTrap_Hpp
#define ScavTrap_Hpp

#include "ClapTrap.hpp"

#include <string>

class ScavTrap : virtual public ClapTrap // virtual keyword so it doesn't include the instance of ClapTrap twice
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		virtual ~ScavTrap();
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