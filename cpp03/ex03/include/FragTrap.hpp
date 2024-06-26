#ifndef FragTrap_Hpp
#define FragTrap_Hpp

#include "ClapTrap.hpp"

#include <string>

class FragTrap : virtual public ClapTrap // virtual keyword so it doesn't include the instance of ClapTrap twice
{
	public:
		FragTrap();
		FragTrap(std::string name);
		virtual ~FragTrap();
		FragTrap(const FragTrap &toCopy);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void getStatus() const;
		void highFivesGuys(void);
		FragTrap &operator=(const FragTrap &toCopy);
};

#endif