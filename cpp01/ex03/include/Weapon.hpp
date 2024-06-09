#ifndef Weapon_hpp
#define Weapon_hpp

#include <string>

class Weapon
{
	public:
		Weapon(std::string type);
		const std::string &getType() const;
		void setType(std::string type);
		~Weapon();
	private:
		std::string m_type;
};

#endif