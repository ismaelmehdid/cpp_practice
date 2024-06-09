#include "../include/Weapon.hpp"
#include <string>

Weapon::Weapon(std::string type) : m_type(type) {}
Weapon::~Weapon() {}

const std::string& Weapon::getType() const
{
	const std::string &typeRef = m_type;
	return typeRef;
}

void Weapon::setType(std::string type)
{
	m_type = type;
}
