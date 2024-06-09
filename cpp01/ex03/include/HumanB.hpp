#ifndef HumanB_hpp
#define HumanB_hpp

#include "Weapon.hpp"
#include <string>

class HumanB
{
	public:
		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
		void attack() const;
		~HumanB();
	private:
		std::string m_name;
		Weapon *m_weapon;
};

#endif