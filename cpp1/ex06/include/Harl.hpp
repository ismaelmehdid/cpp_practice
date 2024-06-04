#ifndef Harl_hpp
#define Harl_hpp

#include <string>

class Harl
{
	public:
		Harl();
		void complain( std::string filter );
		~Harl();
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif
