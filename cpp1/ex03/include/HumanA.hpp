#ifndef HumanA_hpp
#define HumanA_hpp

#include "Weapon.hpp"
#include <string>

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		void attack() const;
		~HumanA();
	private:
		std::string m_name;
		Weapon &m_weapon;
};

#endif