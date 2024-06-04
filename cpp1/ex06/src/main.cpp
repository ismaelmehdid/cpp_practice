#include "../include/Harl.hpp"

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	(void)argc;
	std::string filter = "";
	if (argc > 1)
		filter = argv[1];
	Harl harl;
	harl.complain(filter);
	return 0;
}