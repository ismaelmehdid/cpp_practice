#ifndef Zombie_hpp
#define Zombie_hpp

#include <string>

class Zombie
{
	public:
		Zombie( std::string name );
		void announce( void );
		~Zombie();
	private:
		std::string m_name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif