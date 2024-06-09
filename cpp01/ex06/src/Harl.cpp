#include "../include/Harl.hpp"

#include <iostream>
#include <string>

#define NBR_OF_COMPLAINS 4

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain(std::string filter)
{
	const std::string types[NBR_OF_COMPLAINS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int levelNbr = -1;
	for (int i = 0; i < NBR_OF_COMPLAINS; i++)
	{
		if (types[i] == filter)
		{
			levelNbr = i;
			break ;
		}
	}

	switch (levelNbr) // fallthrough behavior
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << '\n';
			break;
	}

}

void Harl::debug( void )
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << '\n';
}

void Harl::info( void )
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << '\n';
}

void Harl::warning( void )
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << '\n';
}

void Harl::error( void )
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << '\n';
}