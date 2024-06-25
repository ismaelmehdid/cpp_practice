#ifndef ClapTrap_Hpp
#define ClapTrap_Hpp

#include <string>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &toCopy);
		virtual ~ClapTrap();
		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
		virtual void getStatus() const;
		ClapTrap &operator=(const ClapTrap &toCopy);
	protected:
		std::string m_name;
		int m_hp;
		int m_energy;
		int m_attackDamages;
};

#endif