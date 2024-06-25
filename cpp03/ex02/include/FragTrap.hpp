#ifndef FragTrap_Hpp
#define FragTrap_Hpp

#include "ClapTrap.hpp"

#include <string>

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap &toCopy);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void getStatus() const;
		void highFivesGuys(void);
		FragTrap &operator=(const FragTrap &toCopy);
};

#endif