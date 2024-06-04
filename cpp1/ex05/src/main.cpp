#include "../include/Harl.hpp"

#include <iostream>

int main(void)
{
	Harl harl;

	for (int i = 0; i < 2; i++)
	{
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		std::cout << '\n';
	}
	harl.complain("wtf");
	harl.complain("???");
	harl.complain("");
	
	return 0;
}