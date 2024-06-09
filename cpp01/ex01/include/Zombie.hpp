#ifndef Zombie_hpp
#define Zombie_hpp

#include <string>

class Zombie
{
	public:
		Zombie( void );
		void setName(std::string name);
		void announce( void );
		~Zombie();
	private:
		std::string m_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif