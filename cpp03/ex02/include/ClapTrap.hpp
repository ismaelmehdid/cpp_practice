#ifndef ClapTrap_Hpp
#define ClapTrap_Hpp

#include <string>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void getStatus() const;
	protected:
		std::string m_name;
		int m_hp;
		int m_energy;
		int m_attackDamages;
};

#endif