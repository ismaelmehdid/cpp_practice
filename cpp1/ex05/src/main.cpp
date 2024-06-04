#include "../include/Harl.hpp"

#include <iostream>

int main(void)
{
	Harl harl;

	for (int i = 0; i < 2; i++)
	{
		harl.complain("debug");
		harl.complain("info");
		harl.complain("warning");
		harl.complain("error");
		std::cout << '\n';
	}
	harl.complain("wtf");
	harl.complain("???");
	harl.complain("");
	
	return 0;
}