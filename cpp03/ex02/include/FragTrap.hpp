#ifndef FragTrap_Hpp
#define FragTrap_Hpp

#include "ClapTrap.hpp"

#include <string>

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		~FragTrap();
		void getStatus() const;
		void highFivesGuys(void);
};

#endif